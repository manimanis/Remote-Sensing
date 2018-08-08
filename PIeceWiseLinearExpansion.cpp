// PieceWiseLinearExpansion.cpp: implementation of the CPieceWiseLinearExpansion class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "PieceWiseLinearExpansion.h"
#include "PieceWiseLinearOptimisationDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPieceWiseLinearExpansion::CPieceWiseLinearExpansion()
{
	linExpDlg = new CPieceWiseLinearOptimisationDlg;
}

CPieceWiseLinearExpansion::~CPieceWiseLinearExpansion()
{
	if (linExpDlg) delete linExpDlg;
}


unsigned char CPieceWiseLinearExpansion::GetLookUpTable(int x)
{
	return LookUpTable[x];
}

