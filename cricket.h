// cricket.h : main header file for the CRICKET application
//

#if !defined(AFX_CRICKET_H__E5C24805_0B80_11D2_AF1C_00E029143D90__INCLUDED_)
#define AFX_CRICKET_H__E5C24805_0B80_11D2_AF1C_00E029143D90__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "Cricket.h"

/////////////////////////////////////////////////////////////////////////////
// CCricketApp:
// See cricket.cpp for the implementation of this class
//

class CCricketApp : public CWinApp
{
public:
	void SaveSettings ();
   	CCricketApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCricketApp)
	public:
	virtual BOOL InitInstance();
		virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCricketApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bATLInited;
private:
	BOOL InitATL();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRICKET_H__E5C24805_0B80_11D2_AF1C_00E029143D90__INCLUDED_)
