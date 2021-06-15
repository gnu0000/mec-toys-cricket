// cricketView.h : interface of the CCricketView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CRICKETVIEW_H__E5C2480D_0B80_11D2_AF1C_00E029143D90__INCLUDED_)
#define AFX_CRICKETVIEW_H__E5C2480D_0B80_11D2_AF1C_00E029143D90__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CCricketView : public CView
{
protected: // create from serialization only
	CCricketView();
	DECLARE_DYNCREATE(CCricketView)

// Attributes
public:
	HICON		    m_hIcon;
	CCricketDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCricketView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
  	void MouseClick (UINT nFlags, CPoint point, BOOL bLeft);
	void DrawBoard (CDC *pDC);
	void DrawData (CDC *pDC);
  	virtual ~CCricketView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCricketView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CRect *GetMarkRect (CRect *pcRect, INT iPerson, INT iPos);
	void DrawMark (CDC * pDC, CRect pcRect, INT iCount);
	INT m_iX;
	INT m_iY;
};

#ifndef _DEBUG  // debug version in cricketView.cpp
inline CCricketDoc* CCricketView::GetDocument()
   { return (CCricketDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRICKETVIEW_H__E5C2480D_0B80_11D2_AF1C_00E029143D90__INCLUDED_)
