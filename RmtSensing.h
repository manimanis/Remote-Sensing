// RmtSensing.h : main header file for the RMTSENSING application
//

#if !defined(AFX_RMTSENSING_H__FAA77695_4D88_11D4_B2BC_00400550E7C9__INCLUDED_)
#define AFX_RMTSENSING_H__FAA77695_4D88_11D4_B2BC_00400550E7C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "SplashScreen.h"

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingApp:
// See RmtSensing.cpp for the implementation of this class
//

class CRmtSensingApp : public CWinApp
{
public:
	CRmtSensingApp();

	DWORD m_dwSplashTime;
	CSplashScreen splScr;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRmtSensingApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount);
	virtual void AddToRecentFileList(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRmtSensingApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RMTSENSING_H__FAA77695_4D88_11D4_B2BC_00400550E7C9__INCLUDED_)
