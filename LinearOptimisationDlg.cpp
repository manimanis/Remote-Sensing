// LinearOptimisationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "LinearOptimisationDlg.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLinearOptimisationDlg::CLinearOptimisationDlg()
{
	m_maxPoints = 2;
}

CLinearOptimisationDlg::~CLinearOptimisationDlg()
{

}

void CLinearOptimisationDlg::Recalc()
{
	for (int j = 0 ; j < 3 ; j++)
	{
		double	a = double(pt[j][1].y - pt[j][0].y) / double(pt[j][1].x - pt[j][0].x), y,
				b = double(pt[j][0].y) - a * pt[j][0].x; 

		for (int i = 0 ; i < 256 ; i++)
		{
			y = a * i + b;
			if (y < 0) y = 0;
			if (y > 255) y = 255;
			LookUpTable[j][i] = int(y);
		}
	}
}

void CLinearOptimisationDlg::OnChangeMaxPoints() 
{
	m_maxPoints = 2;
	UpdateData(FALSE);
}

