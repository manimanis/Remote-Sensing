// ExponentialExpansion.cpp: implementation of the CExponentialExpansion class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "ExponentialExpansion.h"
#include "ExponentialOptimisationsDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CExponentialExpansion::CExponentialExpansion()
{
	linExpDlg = new CExponentialOptimisationsDlg;
}

CExponentialExpansion::~CExponentialExpansion()
{
	if (linExpDlg) delete linExpDlg;
}

unsigned char CExponentialExpansion::GetLookUpTable(int x)
{
	return LookUpTable[x];
}

