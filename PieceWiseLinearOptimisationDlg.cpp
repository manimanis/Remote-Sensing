// PieceWiseLinearOptimisationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "PieceWiseLinearOptimisationDlg.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPieceWiseLinearOptimisationDlg::CPieceWiseLinearOptimisationDlg()
{
	m_maxPoints = 2;

	for (int j = 0 ; j < 3 ; j++)
	{
		pt[j][0] = CPoint(0, 0);
		pt[j][1] = CPoint(255, 255);
	}

	m_xCoords = pt[currentTab][m_curPoint].x;
	m_yCoords = pt[currentTab][m_curPoint].y;

	Recalc();
}

CPieceWiseLinearOptimisationDlg::~CPieceWiseLinearOptimisationDlg()
{

}

void CPieceWiseLinearOptimisationDlg::Recalc()
{
	int i, j, k;
	double a, b, y;

	for (j = 0 ; j < 3 ; j++)
	{
		if (pt[j][0].x != 0)
		{
			a = double(pt[j][0].y) / double(pt[j][0].x);
					
			for (k = 0 ; k <= pt[j][0].x ; k++)
			{
				y = a * k;
				if (y < 0) y = 0;
				if (y > 255) y = 255;
				LookUpTable[j][k] = int(y);
			}
		}
	
		for (i = 1 ; i < m_maxPoints ; i++)
		{
			if (pt[j][i].x == pt[j][i - 1].x) 
				for (k = pt[j][i - 1].x ; k <= pt[j][i - 1].x ; k++)
					LookUpTable[j][k] = pt[j][i - 1].y;
			else
			{
				a = double(pt[j][i].y - pt[j][i - 1].y) / double(pt[j][i].x - pt[j][i - 1].x);
				b = double(pt[j][i - 1].y) - a * pt[j][i - 1].x; 

				for (k = pt[j][i - 1].x ; k <= pt[j][i].x ; k++)
				{
					y = a * k + b;
					if (y < 0) y = 0;
					if (y > 255) y = 255;
					LookUpTable[j][k] = int(y);
				}
			}
		}

		if (pt[j][m_maxPoints - 1].x != 255)
		{
			a = double(255 - pt[j][m_maxPoints - 1].y) / double(255 - pt[j][m_maxPoints - 1].x);
			b = double(pt[j][m_maxPoints - 1].y) - a * pt[j][m_maxPoints - 1].x;
					
			for (k = pt[j][m_maxPoints - 1].x ; k < 256 ; k++)
			{
				y = a * k + b;
				if (y < 0) y = 0;
				if (y > 255) y = 255;
				LookUpTable[j][k] = int(y);
			}
		}
	}
}

void CPieceWiseLinearOptimisationDlg::OnChangeMaxPoints() 
{
	int oldmax = m_maxPoints;

	UpdateData();

	if (m_maxPoints < 1) m_maxPoints = 2;
	if (m_maxPoints > 30) m_maxPoints = 30;

	for (int i = oldmax ; i < m_maxPoints ; i++) 
	{
		pt[0][i] = pt[0][oldmax - 1];
		pt[1][i] = pt[1][oldmax - 1];
		pt[2][i] = pt[2][oldmax - 1];
	}

	UpdateData(FALSE);
}
