// RmtSensingFrame.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "RmtSensingFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingFrame

IMPLEMENT_DYNCREATE(CRmtSensingFrame, CMDIChildWnd)

CRmtSensingFrame::CRmtSensingFrame()
{
}

CRmtSensingFrame::~CRmtSensingFrame()
{
}


BEGIN_MESSAGE_MAP(CRmtSensingFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CRmtSensingFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingFrame message handlers
int CRmtSensingFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_rmtSensingToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_rmtSensingToolBar.LoadToolBar(IDR_RMTSENSINGTOOLBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_rmtSensingToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_rmtSensingToolBar);

	return 0;
}

BOOL CRmtSensingFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		| WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE;

	cs.cx = GetSystemMetrics(SM_CXSCREEN) * 3 / 5;
	cs.cy = GetSystemMetrics(SM_CYSCREEN) * 3 / 5;
	return TRUE;
}
