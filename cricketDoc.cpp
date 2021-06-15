// cricketDoc.cpp : implementation of the CCricketDoc class
//

#include "stdafx.h"
#include "cricket.h"

#include "cricketDoc.h"
#include "cnewdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCricketDoc

IMPLEMENT_DYNCREATE(CCricketDoc, CDocument)

BEGIN_MESSAGE_MAP(CCricketDoc, CDocument)
	//{{AFX_MSG_MAP(CCricketDoc)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCricketDoc construction/destruction

CCricketDoc::CCricketDoc()
	{
	// TODO: add one-time construction code here
	ClearData ();
	SetName (0, "");
	SetName (1, "");
	}

CCricketDoc::~CCricketDoc()
{
}

BOOL CCricketDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCricketDoc serialization

void CCricketDoc::Serialize(CArchive& ar)
	{
	INT i;

	if (ar.IsStoring())
		{
		ar << csName[0] << csName[1];
		for (i=0; i<7; i++)
			ar << piData[0][i] << piData[1][i];
		}
	else
		{
		ar >> csName[0] >> csName [1];

		for (i=0; i<7; i++)
			ar >> piData[0][i] >> piData[1][i];
		}
	}

/////////////////////////////////////////////////////////////////////////////
// CCricketDoc diagnostics

#ifdef _DEBUG
void CCricketDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCricketDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCricketDoc commands

CString CCricketDoc::GetName(INT iPerson)
{
	return csName [iPerson % 2];
}

void CCricketDoc::SetName(INT iPerson, CString csNewName)
{
	csName[iPerson % 2] = csNewName;
}



INT CCricketDoc::GetScore(INT iPerson, INT iPos)
	{
    return piData[iPerson % 2][iPos % 7];
	}


INT CCricketDoc::GetPoints(INT iPerson)
	{
	INT i, iPoints = 0;

	for (i = 0; i<6; i++)		// 20-15 points
		if (piData[iPerson][i] > 3)
			iPoints += (piData[iPerson][i] - 3) * (20 - i);

	if (piData[iPerson][6] > 3)			// bullseye points
		iPoints += (piData[iPerson][6] - 3) * 25;

	return iPoints;
	}


void CCricketDoc::AddDart(INT iPerson, INT iPos, INT iCount)
	{
  	iPerson %= 2;
	iPos    %= 7;
	if (iCount < 0)	// removing darts
		{
		piData[iPerson][iPos] = max (0, piData[iPerson][iPos] + iCount);
		return;
		}
	if (piData [1-iPerson][iPos] < 3) // opponent still open?
		{
		piData[iPerson][iPos] += iCount;
		}
	else if (piData[iPerson][iPos] < 3) // you still open?
		{
		piData[iPerson][iPos] = min (3, piData[iPerson][iPos] + iCount);
		}
	}


void CCricketDoc::ClearData()
	{
	memset (piData, 0, 2 * 7 * sizeof (INT));
	}

void CCricketDoc::OnFileNew() 
	{
 	ClearData ();
	if (GetName(0) == "" || GetName(1) == "")
		DoNewDlg ();

//	InvalidateRect - get handle to view and invalidate the window!
	}

BOOL CCricketDoc::DoNewDlg()
	{
	cNewDlg dlg;

	dlg.m_csPlayer1 = GetName(0);
	dlg.m_csPlayer2 = GetName(1);

	if (dlg.DoModal() == IDOK)
		{
	    SetName (0, dlg.m_csPlayer1);
		SetName (1, dlg.m_csPlayer2);
		return TRUE;
 		}
	return FALSE;
	}	