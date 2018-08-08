// SplashScreen.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "SplashScreen.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplashScreen dialog


CSplashScreen::CSplashScreen(CWnd* pParent /*=NULL*/)
	: CDialog(CSplashScreen::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSplashScreen)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSplashScreen::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSplashScreen)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSplashScreen, CDialog)
	//{{AFX_MSG_MAP(CSplashScreen)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSplashScreen message handlers

BOOL CSplashScreen::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CenterWindow();

	// CClientDC dc(this);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


BOOL CSplashScreen::Create(CWnd *pParent)
{
	CDialog::Create(CSplashScreen::IDD, pParent);

	return TRUE;
}

void CSplashScreen::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CBitmap Bmp; Bmp.LoadBitmap(IDB_TFESPLASH);
	BITMAP bm; Bmp.GetBitmap(&bm);

	CDC memDC; memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&Bmp);

	dc.BitBlt(0, 0, bm.bmWidth, bm.bmHeight, &memDC, 0, 0, SRCCOPY);

	memDC.DeleteDC();
	Bmp.DeleteObject();
}
