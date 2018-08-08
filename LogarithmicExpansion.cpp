// LogarithmicExpansion.cpp: implementation of the CLogarithmicExpansion class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "LogarithmicExpansion.h"
#include "LogarithmicOptimisationsDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLogarithmicExpansion::CLogarithmicExpansion()
{
	linExpDlg = new CLogarithmicOptimisationsDlg;
}

CLogarithmicExpansion::~CLogarithmicExpansion()
{
	if (linExpDlg) delete linExpDlg;
}

unsigned char CLogarithmicExpansion::GetLookUpTable(int x)
{
	return LookUpTable[x];
}

