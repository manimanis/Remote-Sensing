// LinearExpansion.cpp: implementation of the CLinearExpansion class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "LinearExpansion.h"
#include "LinearOptimisationDlg.h"

#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLinearExpansion::CLinearExpansion()
{
	linExpDlg = new CLinearOptimisationDlg;
}

CLinearExpansion::~CLinearExpansion()
{
	if (linExpDlg) delete linExpDlg;
}

unsigned char CLinearExpansion::GetLookUpTable(int x)
{
	return LookUpTable[x];
}

BOOL CLinearExpansion::PreDlgShow(int *inTable)
{
	int min[3], max[3];

	for (int j = 0 ; j < 3 ; j++)
	{
		min[j] = 256;
		max[j] = 256;
	}

	for (j = 0 ; j < 3 ; j++)
		for (int i = 0 ; i < 256 ; i++)
		{
			if (min[j] == 256 && inTable[j * 256 + i]) min[j] = i;
			if (min[j] != 256 && inTable[j * 256 + i]) max[j] = i;
		}

	for (j = 0 ; j < 3 ; j++)
	{
		linExpDlg->pt[2 - j][0] = CPoint(min[j], 0);
		linExpDlg->pt[2 - j][1] = CPoint(max[j], 255);
	}

	linExpDlg->m_xCoords = linExpDlg->pt[linExpDlg->currentTab][linExpDlg->m_curPoint].x;
	linExpDlg->m_yCoords = linExpDlg->pt[linExpDlg->currentTab][linExpDlg->m_curPoint].y;

	linExpDlg->Recalc();

	return TRUE;
}
