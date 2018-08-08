#if !defined(AFX_RMTSENSINGFRAME_H__5258D2A6_4D8C_11D4_B2BC_00400550E7C9__INCLUDED_)
#define AFX_RMTSENSINGFRAME_H__5258D2A6_4D8C_11D4_B2BC_00400550E7C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RmtSensingFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingFrame frame

class CRmtSensingFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CRmtSensingFrame)
public:
	CRmtSensingFrame();           // protected constructor used by dynamic creation
	virtual ~CRmtSensingFrame();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRmtSensingFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolBar m_rmtSensingToolBar;
	

	// Generated message map functions
	//{{AFX_MSG(CRmtSensingFrame)
		afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RMTSENSINGFRAME_H__5258D2A6_4D8C_11D4_B2BC_00400550E7C9__INCLUDED_)
