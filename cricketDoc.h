// cricketDoc.h : interface of the CCricketDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CRICKETDOC_H__E5C2480B_0B80_11D2_AF1C_00E029143D90__INCLUDED_)
#define AFX_CRICKETDOC_H__E5C2480B_0B80_11D2_AF1C_00E029143D90__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CCricketDoc : public CDocument
{
protected: // create from serialization only
	CCricketDoc();
	DECLARE_DYNCREATE(CCricketDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCricketDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL DoNewDlg ();
	virtual ~CCricketDoc();
	CString GetName (INT iPerson);
	void SetName (INT iPerson, CString csName);
	INT GetScore (INT iPerson, INT iPos);
	INT GetPoints (INT iPerson);
	void AddDart (INT iPerson, INT iPosition, INT iCount);
	void ClearData ();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	INT piData[2][7];
	CString csName[2];
	//{{AFX_MSG(CCricketDoc)
	afx_msg void OnFileNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
  };

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRICKETDOC_H__E5C2480B_0B80_11D2_AF1C_00E029143D90__INCLUDED_)
