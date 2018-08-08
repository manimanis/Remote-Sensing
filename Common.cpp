#include "stdafx.h"
#include "Common.h"
#include "math.h"

#define PI	3.1415926535897932384626433832795

// Définition de la fonction de tracage des flèches
void fleche(CDC *pDC, CRect rect, int type)
{
	double sin_a, cos_a;
	double dx, dy;

	double sin_b = sin(PI / 12);
	double cos_b = cos(PI / 12);

	dx = (double)(rect.right - rect.left);
	dy = (double)(rect.bottom - rect.top);

	cos_a =  dx / sqrt(dx * dx + dy * dy);
	sin_a =  dy / sqrt(dx * dx + dy * dy);

	double cos_a_p_b = cos_a * cos_b - sin_a * sin_b;
	double sin_a_p_b = sin_a * cos_b + cos_a * sin_b;

	double cos_a_m_b = cos_a * cos_b + sin_a * sin_b;
	double sin_a_m_b = sin_a * cos_b - cos_a * sin_b;

	if ((!type) || ((type & FLECHE_ORG) == FLECHE_ORG))
	{
		pDC->MoveTo(rect.left, rect.top);
		pDC->LineTo(rect.left + (int) (300 * cos_a_p_b),
					rect.top + (int) (300 * sin_a_p_b));

	
		pDC->MoveTo(rect.left, rect.top);
		pDC->LineTo(rect.left + (int) (300 * cos_a_m_b),
					rect.top + (int) (300 * sin_a_m_b));
	}
	
	if ((!type) || ((type & FLECHE_EXT) == FLECHE_EXT))
	{
		pDC->MoveTo(rect.right, rect.bottom);
		pDC->LineTo(rect.right - (int) (300 * cos_a_p_b),
					rect.bottom - (int) (300 * sin_a_p_b));

		pDC->MoveTo(rect.right, rect.bottom);
		pDC->LineTo(rect.right - (int) (300 * cos_a_m_b),
				rect.bottom - (int) (300 * sin_a_m_b));
	}

	pDC->MoveTo(rect.left, rect.top);
	pDC->LineTo(rect.right, rect.bottom);
}

void sort(int count, CPoint pt[], BOOL x_ord)
{
	int min;
	CPoint swapper;

	if (x_ord)
		for (int i = 0 ; i < count - 1 ; i++)
		{
			min = i;
			for (int j = min ; j < count ; j++)
					if (pt[j].x < pt[min].x) min = j;
		
			swapper = pt[i];
			pt[i] = pt[min];
			pt[min] = swapper;
		}
	else
		for (int i = 0 ; i < (count - 1) ; i++)
		{
			min = i;
			for (int j = min ; j < count ; j++)
					if (pt[j].y < pt[min].y) min = j;
		
			swapper = pt[i];
			pt[i] = pt[min];
			pt[min] = swapper;
		}
}