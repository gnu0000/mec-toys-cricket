#if !defined(AFX_CNEWDLG_H__72E52861_1004_11D2_AF1C_00E029143D90__INCLUDED_)
#define AFX_CNEWDLG_H__72E52861_1004_11D2_AF1C_00E029143D90__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// cNewDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// cNewDlg dialog

class cNewDlg : public CDialog
{
// Construction
public:
	cNewDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(cNewDlg)
	enum { IDD = IDD_NEWDLG};
	CString	m_csPlayer1;
	CString	m_csPlayer2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(cNewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(cNewDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNEWDLG_H__72E52861_1004_11D2_AF1C_00E029143D90__INCLUDED_)
