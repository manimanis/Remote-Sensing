// ComposanteG.cpp: implementation of the CComposanteG class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "ComposanteG.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CComposanteG,CComposantesRGB)

BEGIN_MESSAGE_MAP(CComposanteG,CComposantesRGB)
	//{{AFX_MSG_MAP(CComposanteG)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CComposanteG::CComposanteG()
{
	AndColor = 0xff00;
}

CComposanteG::~CComposanteG()
{

}

void CComposanteG::OnDestroy() 
{
	CView::OnDestroy();
	
	GetDocument()->GComponent = FALSE;
}
