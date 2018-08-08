// SaturatingLinearOptimisationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "SaturatingLinearOptimisationDlg.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSaturatingLinearOptimisationDlg::CSaturatingLinearOptimisationDlg()
{
	m_maxPoints = 2;

	for (int j = 0 ; j < 3 ; j++)
	{
		pt[j][0] = CPoint(1, 1);
		pt[j][1] = CPoint(255, 255);
	}

	m_xCoords = pt[currentTab][m_curPoint].x;
	m_yCoords = pt[currentTab][m_curPoint].y;

	Recalc();
}

CSaturatingLinearOptimisationDlg::~CSaturatingLinearOptimisationDlg()
{

}

void CSaturatingLinearOptimisationDlg::Recalc()
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

void CSaturatingLinearOptimisationDlg::OnChangeMaxPoints() 
{
	m_maxPoints = 2;
	UpdateData(FALSE);
}
