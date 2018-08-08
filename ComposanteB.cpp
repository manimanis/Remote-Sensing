// ComposanteB.cpp: implementation of the CComposanteB class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "ComposanteB.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CComposanteB,CComposantesRGB)

BEGIN_MESSAGE_MAP(CComposanteB,CComposantesRGB)
	//{{AFX_MSG_MAP(CComposanteG)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CComposanteB::CComposanteB()
{
	AndColor = 0xff0000;
}

CComposanteB::~CComposanteB()
{

}

void CComposanteB::OnDestroy() 
{
	CView::OnDestroy();
	
	GetDocument()->BComponent = FALSE;
}