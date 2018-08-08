// RmtSensing.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "RmtSensing.h"

#include "MainFrm.h"
#include "ChildFrm.h"

#include "RmtSensingDoc.h"
#include "RmtSensingView.h"
#include "RmtSensingFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingApp

BEGIN_MESSAGE_MAP(CRmtSensingApp, CWinApp)
	//{{AFX_MSG_MAP(CRmtSensingApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingApp construction

CRmtSensingApp::CRmtSensingApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CRmtSensingApp object

CRmtSensingApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingApp initialization

BOOL CRmtSensingApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_RMTSENTYPE,
		RUNTIME_CLASS(CRmtSensingDoc),
		RUNTIME_CLASS(CRmtSensingFrame), // custom MDI child frame
		RUNTIME_CLASS(CRmtSensingView));
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	int nCmdShow = m_nCmdShow;

	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// setup main window
	nCmdShow = !cmdInfo.m_bRunEmbedded ? m_nCmdShow : SW_HIDE;
	m_nCmdShow = SW_HIDE;
	((CMainFrame*)m_pMainWnd)->InitialShowWindow(nCmdShow);

	// The main window has been initialized, so show and update it.
	pMainFrame->ShowWindow(SW_SHOWMAXIMIZED);
	pMainFrame->UpdateWindow();
	
	if (!cmdInfo.m_bRunEmbedded)
	{
		m_pMainWnd->UpdateWindow();

		if (!m_pMainWnd->IsIconic() && cmdInfo.m_bShowSplash &&
			splScr.Create(m_pMainWnd))
		{
			splScr.ShowWindow(SW_SHOW);
			splScr.UpdateWindow();
			splScr.SetTimer(1, 500, NULL);
		}
		m_dwSplashTime = ::GetCurrentTime();
	}

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CRmtSensingApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingApp message handlers

void CRmtSensingApp::OnFileOpen() 
{
	CFileDialog fDlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, 
		"Fichiers Bitamp (*.bmp)|*.bmp|"
		"Fichiers Hist. de l'image (*.phst)|*.phst|");	

	if (fDlg.DoModal() == IDOK)
	{
		POSITION curTemplatePos = GetFirstDocTemplatePosition();

		while(curTemplatePos != NULL)
		{
			CDocTemplate* curTemplate = GetNextDocTemplate(curTemplatePos);
		
			CString str;
			curTemplate->GetDocString(str, CDocTemplate::docName);
			if(str == _T("RmtSen"))
			{
				curTemplate->OpenDocumentFile(fDlg.GetPathName());
				return;
			}
		}	
	}
}

BOOL CRmtSensingApp::OnIdle(LONG lCount) 
{
	// call base class idle first
	BOOL bResult = CWinApp::OnIdle(lCount);

	// then do our work
	if (splScr.m_hWnd != NULL)
	{
		if (::GetCurrentTime() - m_dwSplashTime > 5000)
		{
			// timeout expired, destroy the splash window
			splScr.DestroyWindow();
			m_pMainWnd->UpdateWindow();

			// NOTE: don't set bResult to FALSE,
			//  CWinApp::OnIdle may have returned TRUE
		}
		else
		{
			// check again later...
			bResult = TRUE;
		}
	}

	return bResult;
}

void CAboutDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	EndDialog(0);	
	// CDialog::OnLButtonDown(nFlags, point);
}

void CRmtSensingApp::AddToRecentFileList(LPCTSTR lpszPathName) 
{
	CString iFile;

	iFile = lpszPathName;

	if (iFile.Right(4) == ".bmp")
		CWinApp::AddToRecentFileList(lpszPathName);
}
