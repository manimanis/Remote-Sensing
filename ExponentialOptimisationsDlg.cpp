// ExponentialOptimisationsDlg.cpp: implementation of the CExponentialOptimisationsDlg class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "ExponentialOptimisationsDlg.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CExponentialOptimisationsDlg::CExponentialOptimisationsDlg()
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

CExponentialOptimisationsDlg::~CExponentialOptimisationsDlg()
{

}

void CExponentialOptimisationsDlg::Recalc()
{
	for (int j = 0 ; j < 3 ; j++)
	{
		double	b = double(pt[currentTab][1].x - pt[j][0].x) / 
					double(log(pt[currentTab][1].y) - log(pt[j][0].y)), y,
				a = exp(double(pt[currentTab][0].x) / b - log(pt[j][0].y)); 

		for (int i = 0 ; i < 256 ; i++)
		{
			y = exp(i / b - log(a));
			if (y < 0) y = 0;
			if (y > 255) y = 255;
			LookUpTable[j][i] = y;
		}
	}
}

void CExponentialOptimisationsDlg::OnChangeMaxPoints() 
{
	m_maxPoints = 2;
	UpdateData(FALSE);
}
