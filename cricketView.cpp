// cricketView.cpp : implementation of the CCricketView class
//

#include "stdafx.h"
#include "cricket.h"

#include "cricketDoc.h"
#include "cricketView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCricketView

IMPLEMENT_DYNCREATE(CCricketView, CView)

BEGIN_MESSAGE_MAP(CCricketView, CView)
	//{{AFX_MSG_MAP(CCricketView)
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCricketView construction/destruction

CCricketView::CCricketView()
{
	// TODO: add construction code here
	m_hIcon = AfxGetApp()->LoadIcon(IDR_CRICKTYPE);
  
}

//
// This should really be done in the App class
// but how?
//
CCricketView::~CCricketView()
	{
	}

BOOL CCricketView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCricketView drawing

void CCricketView::OnDraw(CDC* pDC)
	{
	CCricketDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	DrawBoard (pDC); // The board
	DrawData (pDC);  // The marks/names/points on the board
 	}

//	// Get the invalidated rectangle of the view, or in the case
//	// of printing, the clipping region of the printer dc.
//	CRect rectClip;
//	CRect rectStroke;
//	pDC->GetClipBox(&rectClip);
//	pDC->LPtoDP(&rectClip);
//	rectClip.InflateRect(1, 1); // avoid rounding to nothing
//
//	// Note: CScrollView::OnPaint() will have already adjusted the
//	// viewport origin before calling OnDraw(), to reflect the
//	// currently scrolled position.
//
//	// The view delegates the drawing of individual strokes to
//	// CStroke::DrawStroke().
//	CTypedPtrList<CObList,CStroke*>& strokeList = pDoc->m_strokeList;
//	POSITION pos = strokeList.GetHeadPosition();
//	while (pos != NULL)
//	{
//		CStroke* pStroke = strokeList.GetNext(pos);
//		rectStroke = pStroke->GetBoundingRect();
//		pDC->LPtoDP(&rectStroke);
//		rectStroke.InflateRect(1, 1); // avoid rounding to nothing
//		if (!rectStroke.IntersectRect(&rectStroke, &rectClip))
//			continue;
//		pStroke->DrawStroke(pDC);
//	}


/////////////////////////////////////////////////////////////////////////////
// CCricketView diagnostics

#ifdef _DEBUG
void CCricketView::AssertValid() const
{
	CView::AssertValid();
}

void CCricketView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCricketDoc* CCricketView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCricketDoc)));
	return (CCricketDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCricketView message handlers

/*
 * returns the rectangle where marks should be placed
 *
 */
CRect *CCricketView::GetMarkRect(CRect *pcRect, INT iPerson, INT iPos)
	{
	pcRect->SetRect (m_iX*(iPerson*9+1)/16,  m_iY*(iPos*9+1)/72,
                     m_iX*(iPerson*9+6)/16,  m_iY*(iPos*9+8)/72);
	return pcRect;
	}


void CCricketView::OnSize(UINT nType, int cx, int cy) 
	{
	CView::OnSize(nType, cx, cy);

	// Calculate New window Metrics
	m_iX = cx;
	m_iY = cy;
	}


void CCricketView::DrawBoard(CDC * pDC)
	{
	INT		i;
	CRect	cRect;
	CBrush  MyBrush, pOldBrush;
	PSZ     psz[] = {"20", "19", "18", "17", "16", "15", "0"};
	COLORREF crText, crBar, crOldBG, crOldText;

	crBar	= RGB(0,64,64);
	crText  = RGB(210,255,255);

	MyBrush.CreateSolidBrush (crBar);

	cRect.SetRect (m_iX*7/16, m_iY/8, m_iX*9/16, m_iY);
	pDC->FillRect (cRect, &MyBrush);
	cRect.SetRect (0, m_iY/8 - m_iY/80, m_iX, m_iY/8);
	pDC->FillRect (cRect, &MyBrush);

  	crOldText = pDC->SetTextColor (crText);
	crOldBG   = pDC->SetBkColor(crBar);

	for (i=0; i<7; i++)
		{
		cRect.SetRect (m_iX*7/16, m_iY*(i+1)/8, m_iX*9/16, m_iY*(i+2)/8);
		pDC->DrawText (psz[i], -1, cRect, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
		}
	pDC->SetTextColor (crOldText);
	pDC->SetBkColor   (crOldBG  );

	pDC->DrawIcon (m_iX/2-16, max (0, m_iY/16-16), m_hIcon);
	}



void CCricketView::DrawData(CDC *pDC)
	{
	CRect		cRect;
	CCricketDoc *pDoc;
	INT			iPerson, iPos, iPoints;
	CString		csTemp;

	pDoc = (CCricketDoc *) GetDocument ();

   	/*--- Draw Scores ---*/
	for (iPerson=0; iPerson<2; iPerson++)
		{
		for (iPos=0; iPos<8; iPos++)
			{
			GetMarkRect (&cRect, iPerson, iPos);

			if (!iPos) // draw name
				{
				iPoints = pDoc->GetPoints(iPerson);
				csTemp.Format ((iPoints ? "%s\n+%d" : "%s"),
						(LPCTSTR)pDoc->GetName(iPerson), iPoints);
			   
				pDC->DrawText (csTemp, cRect, DT_CENTER);
				}
			else // draw marks
				{
		 		DrawMark (pDC, cRect, pDoc->GetScore (iPerson, iPos-1));
				}
			}
		}
	}


void CCricketView::DrawMark(CDC * pDC, CRect cRect, INT iCount)
	{
	CPen	*pcOldPen, cPen;
	INT		iThickness;

	iThickness = m_iX/60;
	cRect.DeflateRect (iThickness/2, iThickness/2, 
	                   iThickness/2, iThickness/2);

	cPen.CreatePen (PS_SOLID, iThickness, RGB(0,0,0));
	pcOldPen = pDC->SelectObject (&cPen);

	if (iCount > 2) // 0
		{
		pDC->Ellipse (cRect);
		}
	if (iCount)		// /
		{
		pDC->MoveTo (cRect.right, cRect.top);
		pDC->LineTo (cRect.left,  cRect.bottom);
		}
	if (iCount > 1) // backslash
		{
		pDC->MoveTo (cRect.left,  cRect.top);
		pDC->LineTo (cRect.right, cRect.bottom);
		}
	pDC->SelectObject (pcOldPen);
	}


void CCricketView::OnLButtonDown(UINT nFlags, CPoint point) 
	{
	MouseClick(nFlags, point, TRUE);
	CView::OnLButtonDown(nFlags, point);
	}



void CCricketView::OnRButtonDown(UINT nFlags, CPoint point) 
	{
 	MouseClick (nFlags, point, FALSE);
 	CView::OnRButtonDown(nFlags, point);
	}


void CCricketView::OnLButtonDblClk(UINT nFlags, CPoint point) 
	{
	CRect		cRect;
	CCricketDoc *pDoc;

	cRect.SetRect (m_iX/2-16, max (0, m_iY/16-16), 
		           m_iX/2+16, max (0, m_iY/16-16) + 32);

	if (cRect.PtInRect (point))
		{
		pDoc  = (CCricketDoc *) GetDocument ();
		if (pDoc->DoNewDlg ())
			{
			pDoc->ClearData();
			InvalidateRect (NULL, TRUE);
			}
		}
	else
		{
		MouseClick(nFlags, point, TRUE);
		}
	CView::OnLButtonDblClk(nFlags, point);
	}

void CCricketView::OnRButtonDblClk(UINT nFlags, CPoint point) 
	{
	MouseClick(nFlags, point, false);
   	CView::OnRButtonDblClk(nFlags, point);
	}

void CCricketView::MouseClick(UINT nFlags, CPoint point, BOOL bLeft)
	{
	INT			i, iSide;
	CRect		cRect;
 	CCricketDoc *pDoc;
 
	pDoc  = (CCricketDoc *) GetDocument ();
	iSide = (point.x > m_iX/2 ? 1 : 0);

	for (i=0; i<7; i++)
		{
		GetMarkRect (&cRect, iSide, i+1);
		if (cRect.PtInRect (point))
			{
			pDoc->AddDart (iSide, i, (bLeft ? 1 : -1));
			InvalidateRect (cRect, TRUE);
			InvalidateRect (GetMarkRect (&cRect, iSide, 0), TRUE);
			}
		}
	}
