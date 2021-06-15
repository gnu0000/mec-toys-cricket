// cNewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "cricket.h"
#include "cNewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// cNewDlg dialog


cNewDlg::cNewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(cNewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(cNewDlg)
	m_csPlayer1 = _T("");
	m_csPlayer2 = _T("");
	//}}AFX_DATA_INIT
}


void cNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(cNewDlg)
	DDX_Text(pDX, IDC_PLAYER1, m_csPlayer1);
	DDX_Text(pDX, IDC_PLAYER2, m_csPlayer2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(cNewDlg, CDialog)
	//{{AFX_MSG_MAP(cNewDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// cNewDlg message handlers
