// ComposanteR.cpp: implementation of the CComposanteR class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "ComposanteR.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CComposanteR,CComposantesRGB)

BEGIN_MESSAGE_MAP(CComposanteR,CComposantesRGB)
	//{{AFX_MSG_MAP(CComposanteR)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CComposanteR::CComposanteR()
{
	AndColor = 0xff;
}

CComposanteR::~CComposanteR()
{

}

void CComposanteR::OnDestroy() 
{
	CView::OnDestroy();
	
	GetDocument()->RComponent = FALSE;
}
