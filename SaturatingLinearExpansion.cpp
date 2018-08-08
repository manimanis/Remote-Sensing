// SaturatingLinearExpansion.cpp: implementation of the CSaturatingLinearExpansion class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "SaturatingLinearExpansion.h"
#include "SaturatingLinearOptimisationDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSaturatingLinearExpansion::CSaturatingLinearExpansion()
{
	linExpDlg = new CSaturatingLinearOptimisationDlg;
}

CSaturatingLinearExpansion::~CSaturatingLinearExpansion()
{
	if (linExpDlg) delete linExpDlg;
}


unsigned char CSaturatingLinearExpansion::GetLookUpTable(int x)
{
	return LookUpTable[x];
}

