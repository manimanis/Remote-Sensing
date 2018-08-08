// PictureHistogrammeFrame.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "PictureHistogrammeFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR,
};

/////////////////////////////////////////////////////////////////////////////
// CPictureHistogrammeFrame

IMPLEMENT_DYNCREATE(CPictureHistogrammeFrame, CMDIChildWnd)

CPictureHistogrammeFrame::CPictureHistogrammeFrame()
{
}

CPictureHistogrammeFrame::~CPictureHistogrammeFrame()
{
}


BEGIN_MESSAGE_MAP(CPictureHistogrammeFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CPictureHistogrammeFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPictureHistogrammeFrame message handlers
int CPictureHistogrammeFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_pictureHistoToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_pictureHistoToolBar.LoadToolBar(IDR_PICTUREHISTOGRAMME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	UINT nID, nStyle;
	int cxWidth;

	m_wndStatusBar.GetPaneInfo(0, nID, nStyle, cxWidth);

	m_wndStatusBar.SetPaneInfo(0, nID, SBPS_NORMAL | SBPS_STRETCH, 100);
	m_wndStatusBar.SetPaneInfo(1, nID, SBPS_NORMAL, 50);
	m_wndStatusBar.SetPaneInfo(2, nID, SBPS_NORMAL, 50);
	m_wndStatusBar.SetPaneInfo(3, nID, SBPS_NORMAL, 50);
	m_wndStatusBar.SetPaneInfo(4, nID, SBPS_NORMAL | SBPS_STRETCH, 50);

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_pictureHistoToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_pictureHistoToolBar);

	return 0;
}

BOOL CPictureHistogrammeFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		| WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE;

	cs.x = 0;
	cs.y = 0;

	cs.cx = GetSystemMetrics(SM_CXSCREEN) * 3 / 5;
	cs.cy = GetSystemMetrics(SM_CYSCREEN) * 3 / 5;

	return TRUE;
}

BOOL CPictureHistogrammeFrame::DestroyWindow() 
{
	return CMDIChildWnd::DestroyWindow();
}
