// Histogramme.cpp: implementation of the Histogramme class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "Hstogramme.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Histogramme::Histogramme()
{
	Xmin = -4.7;										// Initialise avec des valeurs arbitraires
	Xmax = 4.7;
	
	Ymin = -3.2;
	Ymax = 3.2;

	Xscl = 1.5;
	Yscl = 1.5;

	HistogrammeRect = CRect(0, 0, 100, 100);			

	data = 0;						// On initailise a NULL la variable data
	dataCount = 0;					// Pas de données

	// Le titre de l'histogramme ainsi que son état
	HistoTitle = "No Title";
	HistoTitleEnabled = FALSE;

	// Le titre de l'axe des X ainsi que son état
	XAxisTitle = "L'axe des X";
	XAxisTitleEnabled = FALSE;

	// Le titre de l'axe des Y ainsi que son état
	YAxisTitle = "L'axe des Y";
	YAxisTitleEnabled = FALSE;

	XScaleValueEnabled = FALSE;
	YScaleValueEnabled = FALSE;

	//
	// ATTENTION :	NE PAS OUBLIER D'APPELER CETTE FONTION APRES CHAQUE OPERATION SET QUI
	//				INFLUE SUR LA VARIABLE : DrawingRect
	//
	// SetDrawingRect(pDC);			

	XStep = (Xmax - Xmin) / DrawingRect.Width();	// Calcule le pas à utiliser par pixel (X)
	YStep = (Ymax - Ymin) / DrawingRect.Height();	// Calcule le pas à utiliser par pixel (Y)

	QuadrType = QUADRILLAGE_X | QUADRILLAGE_Y;

	histogrammeType = HISTO_COURBE;

	percentEnabled = FALSE;
	yMaxPercentValue = 1.0;

	XSclFormat = "%5.2f";
	YSclFormat = "%5.2f";
}

Histogramme::~Histogramme()
{

}

double Histogramme::GetXmin()
{
	return Xmin;
}

double Histogramme::GetXmax()
{
	return Xmax;
}

double Histogramme::GetYmin()
{
	return Ymin;
}

double Histogramme::GetYmax()
{
	return Ymax;
}

double Histogramme::GetXscl()
{
	return Xscl;
}

double Histogramme::GetYscl()
{
	return Yscl;
}

double Histogramme::GetXStep()
{
	return XStep;
}

double Histogramme::GetYStep()
{
	return YStep;
}

CRect Histogramme::GetHistogrammeRect()
{
	return HistogrammeRect;
}

void Histogramme::SetHistogrammeRect(CRect NewRect)
{
	// Au cas ou les nouvelles dimensions sont nulles on ne fait rien
	if (NewRect.Width() && NewRect.Height())
		HistogrammeRect = NewRect;
}

void Histogramme::SetYStep(double NewValue)
{
	YStep = NewValue;
}

void Histogramme::SetXStep(double NewValue)
{
	XStep = NewValue;
}

void Histogramme::SetYscl(double NewValue)
{
	Yscl = NewValue;
}

void Histogramme::SetXscl(double NewValue)
{
	Xscl = NewValue;
}

void Histogramme::SetYmax(double NewValue)
{
	Ymax = NewValue;
}

void Histogramme::SetYmin(double NewValue)
{
	Ymin = NewValue;
}

void Histogramme::SetXmax(double NewValue)
{
	Xmax = NewValue;
}

void Histogramme::SetXmin(double NewValue)
{
	Xmin = NewValue;
}

// On initialise le tableau par les données qui sont dans NewData et NewCount
void Histogramme::SetDataPointer(HistoPointData *NewData, int NewCount)
{
	if (NewData)	
	{
		data = NewData;
		dataCount = NewCount;
	}
}

// On récupère les données tracés par l'histogramme
int Histogramme::GetDataPointer(HistoPointData *OldData)
{
	OldData = data;
	return dataCount;
}


CString Histogramme::GetHistoTitle()
{
	return HistoTitle;
}

void Histogramme::SetHistoTitle(CString NewTitle)
{
	HistoTitle = NewTitle;
}

BOOL Histogramme::GetHistoTitleState()
{
	return HistoTitleEnabled;
}

void Histogramme::SetHistoTitleState(BOOL NewState)
{
	HistoTitleEnabled = NewState;	
}

CString Histogramme::GetXAxisTitle()
{
	return XAxisTitle;
}

void Histogramme::SetXAxisTitle(CString NewTitle)
{
	XAxisTitle = NewTitle;
}

BOOL Histogramme::GetXAxisTitleState()
{
	return XAxisTitleEnabled;
}

void Histogramme::SetXAxisTitleState(BOOL NewState)
{
	XAxisTitleEnabled = NewState;
}

CString Histogramme::GetYAxisTitle()
{
	return YAxisTitle;
}

void Histogramme::SetYAxisTitle(CString NewTitle)
{
	YAxisTitle = NewTitle;
}

BOOL Histogramme::GetYAxisTitleState()
{
	return YAxisTitleEnabled;
}

void Histogramme::SetYAxisTitleState(BOOL NewState)
{
	YAxisTitleEnabled = NewState;
}

BOOL Histogramme::GetXScaleValueState()
{
	return XScaleValueEnabled;
}

void Histogramme::SetXScaleValueState(BOOL NewState)
{
	XScaleValueEnabled = NewState;
}

BOOL Histogramme::GetYScaleValueState()
{
	return YScaleValueEnabled;
}

void Histogramme::SetYScaleValueState(BOOL NewState)
{
	YScaleValueEnabled = NewState;
}

void Histogramme::SetDrawingRect(CDC *pDC)
{
	CRect  r = HistogrammeRect;
	CSize size;
	CString str;
	LOGFONT LogFont;
	CFont pol, *oldFont;

	memset(&LogFont, 0, sizeof LogFont);
	strcpy(LogFont.lfFaceName, "Arial");
	LogFont.lfHeight = 400;

	pol.CreateFontIndirect(&LogFont);
	oldFont = (CFont*)pDC->SelectObject(&pol);

	DrawingRect = CRect(r.left + 200, r.top - 200, r.right - 200, r.bottom + 200);

	size = pDC->GetTextExtent("HAHA");

	if (XAxisTitleEnabled) DrawingRect.bottom += 500;
	if (YAxisTitleEnabled) DrawingRect.left += size.cy + 200;

	if (XScaleValueEnabled) DrawingRect.bottom += 500;
	if (YScaleValueEnabled) 
	{
		str.Format(YSclFormat, (Ymax > Ymin) ? Ymax : Ymin);
		size = pDC->GetTextExtent(str);

		DrawingRect.left += size.cx;
		DrawingRect.left += 100;
	}

	if (percentEnabled) DrawingRect.right -= 1500;

	if (HistoTitleEnabled) DrawingRect.top -= 1300;

	pDC->SelectObject(oldFont);
	pol.DeleteObject();
}

CRect Histogramme::GetDrawingRect()
{
	return DrawingRect;
}

void Histogramme::InitDrawingRect(CDC *pDC)
{
	CPen *oldPen, newLightPen, blackPen;
	CBrush brush(RGB(255, 255, 255)), *oldBrush;
	CFont pol, pol1, pol2, *oldFont;

	CSize size;
	CString XText, YText;

	double x, xInc, pX;
	double y, yInc, pY;
	int xPos, yPos;

	LOGFONT LogFont;

	newLightPen.CreatePen(PS_SOLID, 1, RGB(190, 190, 190));
	blackPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));

	oldPen = (CPen*)pDC->SelectObject(&newLightPen);
	oldBrush = (CBrush*)pDC->SelectObject(&brush);

	pDC->Rectangle(DrawingRect);
	pDC->SetBkColor(RGB(255, 255, 255));
	
	if (Xscl && ((QuadrType & QUADRILLAGE_X) == QUADRILLAGE_X))
	{
		x = Xmin - fmod(Xmin, Xscl);
		xInc = (Xmin > Xmax) ? -Xscl : Xscl;
		pX = (x - Xmin) / (Xmax - Xmin);

		while (pX < 1.0)
		{
			xPos = (int) (pX * DrawingRect.Width()) + DrawingRect.left;

			pDC->MoveTo(xPos, DrawingRect.top);
			pDC->LineTo(xPos, DrawingRect.bottom);

			x += xInc;
			pX = (x - Xmin) / (Xmax - Xmin);
		}
	}

	if (Yscl && ((QuadrType & QUADRILLAGE_Y) == QUADRILLAGE_Y))
	{
		y = Ymin - fmod(Ymin, Yscl);
		yInc = (Ymin > Ymax) ? -Yscl : Yscl;
		pY = (y - Ymin) / (Ymax - Ymin);

		while (pY < 1.0)
		{
			yPos = (int) (pY * DrawingRect.Height()) + DrawingRect.top;

			pDC->MoveTo(DrawingRect.left, yPos);
			pDC->LineTo(DrawingRect.right, yPos);

			y += yInc;
			pY = (y - Ymin) / (Ymax - Ymin);
		}
	}

	pDC->SelectObject(&blackPen);

	if ((Xmin * Xmax) <= 0)
	{
		double XOrgAxis = -Xmin / (Xmax - Xmin) * DrawingRect.Width() + DrawingRect.left;
		
		fleche(pDC, CRect((int)XOrgAxis, DrawingRect.top, (int)XOrgAxis, DrawingRect.bottom),
						(Ymin > Ymax) ? FLECHE_ORG : FLECHE_EXT);
	}

	if ((Ymin * Ymax) <= 0)
	{
		double YOrgAxis = -Ymin / (Ymax - Ymin) * DrawingRect.Height() + DrawingRect.top;
		
		fleche(pDC, CRect(DrawingRect.left, (int)YOrgAxis, DrawingRect.right, (int)YOrgAxis),
						(Xmin > Xmax) ? FLECHE_ORG : FLECHE_EXT);
	}
	
	memset(&LogFont, 0, sizeof LogFont);
	strcpy(LogFont.lfFaceName, "Arial");
	LogFont.lfHeight = 400;
	LogFont.lfEscapement = 900; // 90 degree

	pol.CreateFontIndirect(&LogFont);

	oldFont = (CFont*)pDC->SelectObject(&pol);

	if (YAxisTitleEnabled)
	{	
		size = pDC->GetTextExtent(YAxisTitle);
		pDC->TextOut(HistogrammeRect.left + 800, 
			DrawingRect.top + (DrawingRect.Height() + size.cx) / 2, YAxisTitle);
	}

	LogFont.lfEscapement = 0; // 0 degree
	pol1.CreateFontIndirect(&LogFont);
	pDC->SelectObject(&pol1);

	if (XAxisTitleEnabled)
	{	
		size = pDC->GetTextExtent(XAxisTitle);

		pDC->TextOut(DrawingRect.left + (DrawingRect.Width() - size.cx) / 2, 
			DrawingRect.bottom - ((XScaleValueEnabled) ? 500 : 150), XAxisTitle);
	}
	
	if (YScaleValueEnabled)
	{
		if (Yscl)
		{
			y = Ymin - fmod(Ymin, Yscl);
			yInc = (Ymin > Ymax) ? -Yscl : Yscl;
			pY = (y - Ymin) / (Ymax - Ymin);
			int oldPos = 0, Height;
			
			size = pDC->GetTextExtent("%");
			Height = size.cy;
			
			while (pY < 1.0)
			{
				yPos = (int) (pY * DrawingRect.Height()) + DrawingRect.top;

				pDC->MoveTo(DrawingRect.left - 100, yPos);
				pDC->LineTo(DrawingRect.left + 100, yPos);
				
				if (abs(yPos - oldPos) > abs(Height)) 
				{
					YText.Format(XSclFormat, y);
					size = pDC->GetTextExtent(YText);

					pDC->TextOut(DrawingRect.left - size.cx - 200, yPos + 250, YText);
					oldPos = yPos;
				}

				y += yInc;
				pY = (y - Ymin) / (Ymax - Ymin);
			}
			
			// Ymax
			pDC->MoveTo(DrawingRect.left - 100, DrawingRect.bottom);
			pDC->LineTo(DrawingRect.left + 100, DrawingRect.bottom);

			YText.Format(XSclFormat, Ymax);
			size = pDC->GetTextExtent(YText);

			pDC->TextOut(DrawingRect.left - size.cx - 200, DrawingRect.bottom + 250, YText);
			
			// Ymin 
			pDC->MoveTo(DrawingRect.left - 100, DrawingRect.top);
			pDC->LineTo(DrawingRect.left + 100, DrawingRect.top);

			YText.Format(XSclFormat, Ymin);
			size = pDC->GetTextExtent(YText);

			pDC->TextOut(DrawingRect.left - size.cx - 200, DrawingRect.top + 250, YText);
		}	
	}

	if (XScaleValueEnabled)
	{
		if(Xscl)
		{
			x = Xmin - fmod(Xmin, Xscl);
			xInc = (Xmin > Xmax) ? -Xscl : Xscl;
			pX = (x - Xmin) / (Xmax - Xmin);
			
			while (pX < 1.0)
			{
				xPos = (int) (pX * DrawingRect.Width()) + DrawingRect.left;

				pDC->MoveTo(xPos, DrawingRect.bottom - 100);
				pDC->LineTo(xPos, DrawingRect.bottom + 100);

				XText.Format(XSclFormat, x);

				pDC->TextOut(xPos - 200, DrawingRect.bottom - 120, XText);

				x += xInc;
				pX = (x - Xmin) / (Xmax - Xmin);
			}

			x = Xmax;

			pDC->MoveTo(DrawingRect.right, DrawingRect.bottom - 100);
			pDC->LineTo(DrawingRect.right, DrawingRect.bottom + 100);

			XText.Format(XSclFormat, x);

			pDC->TextOut(DrawingRect.right - 200, DrawingRect.bottom - 120, XText);

			x = Xmin;

			pDC->MoveTo(DrawingRect.left, DrawingRect.bottom - 100);
			pDC->LineTo(DrawingRect.left, DrawingRect.bottom + 100);

			XText.Format(XSclFormat, x);

			pDC->TextOut(DrawingRect.left - 200, DrawingRect.bottom - 120, XText);
		}
	}

	if (percentEnabled)
	{
		if (Yscl)
		{
			y = Ymin - fmod(Ymin, Yscl);
			yInc = (Ymin > Ymax) ? -Yscl : Yscl;
			pY = (y - Ymin) / (Ymax - Ymin);
			int oldPos = 0, Height;
			
			size = pDC->GetTextExtent("%");
			Height = size.cy;

			while (pY < 1.0)
			{
				yPos = (int) (pY * DrawingRect.Height()) + DrawingRect.top;

				pDC->MoveTo(DrawingRect.right - 100, yPos);
				pDC->LineTo(DrawingRect.right + 100, yPos);

				if (abs(yPos - oldPos) > abs(Height))
				{
					YText.Format("%5.2f", (y / yMaxPercentValue) * 100);
					pDC->TextOut(DrawingRect.right + 200, yPos + 250, YText + "%");

					oldPos = yPos;
				}
				y += yInc;
				pY = (y - Ymin) / (Ymax - Ymin);
			}

			// Ymax
			pDC->MoveTo(DrawingRect.left - 100, DrawingRect.bottom);
			pDC->LineTo(DrawingRect.left + 100, DrawingRect.bottom);

			YText.Format("%5.2f", (Ymax / yMaxPercentValue) * 100);
			size = pDC->GetTextExtent(YText);

			pDC->TextOut(DrawingRect.right + 200, DrawingRect.bottom + 250, YText + "%");
			
			// Ymin 
			pDC->MoveTo(DrawingRect.left - 100, DrawingRect.top);
			pDC->LineTo(DrawingRect.left + 100, DrawingRect.top);

			YText.Format("%5.2f", (Ymin / yMaxPercentValue) * 100);
			size = pDC->GetTextExtent(YText);

			pDC->TextOut(DrawingRect.right + 200, DrawingRect.top + 250, YText + "%");
		}
	}

	if (HistoTitleEnabled)
	{
		LogFont.lfEscapement = 0; // 0 degree
		LogFont.lfHeight = 0;
		if (HistoTitle.GetLength() > 10)
			LogFont.lfWidth = DrawingRect.Width() / HistoTitle.GetLength();
		else
			LogFont.lfWidth = 0;

		pol2.CreateFontIndirect(&LogFont);
		pDC->SelectObject(&pol2);
		size = pDC->GetTextExtent(HistoTitle);

		pDC->TextOut(	HistogrammeRect.left + (HistogrammeRect.Width() - size.cx) / 2,
						HistogrammeRect.top - 100, HistoTitle);
	}

	// pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
	pDC->SelectObject(oldFont);
	
	newLightPen.DeleteObject();
	blackPen.DeleteObject();
	brush.DeleteObject();
	pol.DeleteObject();
	pol1.DeleteObject();
	pol2.DeleteObject();
}

int Histogramme::GetQuadrType()
{
	return QuadrType;
}

void Histogramme::SetQuadrType(int NewValue)
{
	QuadrType = NewValue;
}

void Histogramme::Plot(CDC *pDC, COLORREF couleur)
{
	CPen *oldPen, clrPen;
	int i;
	
	if (!dataCount || !data) 
	{
		AfxMessageBox("Stop !!! Appel de la méthode\nPlot(CDC *pDC, COLORREF couleur)\n"
					  "refusé\nCause : (dataCount == 0) || (data == NULL)", 
					  MB_OK | MB_ICONEXCLAMATION);
		return;
	}

	clrPen.CreatePen(PS_SOLID, 1, couleur);
	oldPen = (CPen *)pDC->SelectObject(&clrPen);

	switch (histogrammeType)
	{
		// -------------------------------------------------------------------------------
		case HISTO_COURBE :
	pDC->MoveTo(DrawingRect.left + int((data[0].x - Xmin) / (Xmax - Xmin) * DrawingRect.Width()), 
		DrawingRect.top - int((data[0].y - Ymin) / (Ymax - Ymin) * abs(DrawingRect.Height())));

	for (i = 0 ; i < dataCount ; i++)
	{
		pDC->LineTo(DrawingRect.left + int((data[i].x - Xmin) / (Xmax - Xmin) * DrawingRect.Width()), 
			DrawingRect.top - int((data[i].y - Ymin) / (Ymax - Ymin) * abs(DrawingRect.Height())));
	}

	break;

		// -------------------------------------------------------------------------------
		case HISTO_DISCRET:
	for (i = 0 ; i < dataCount ; i++)
	{
		pDC->MoveTo(DrawingRect.left + int((data[i].x - Xmin) / (Xmax - Xmin) * DrawingRect.Width()), 
			DrawingRect.bottom);

		pDC->LineTo(DrawingRect.left + int((data[i].x - Xmin) / (Xmax - Xmin) * DrawingRect.Width()), 
			DrawingRect.top - int((data[i].y - Ymin) / (Ymax - Ymin) * abs(DrawingRect.Height())));
	}

	break;

		// -------------------------------------------------------------------------------
		case HISTO_POINTS :
	for (i = 0 ; i < dataCount ; i++)
	{
		pDC->MoveTo(DrawingRect.left + int((data[i].x - Xmin) / (Xmax - Xmin) * DrawingRect.Width()) - 100, 
			DrawingRect.top - int((data[i].y - Ymin) / (Ymax - Ymin) * abs(DrawingRect.Height())));

		pDC->LineTo(DrawingRect.left + int((data[i].x - Xmin) / (Xmax - Xmin) * DrawingRect.Width()) + 101, 
			DrawingRect.top - int((data[i].y - Ymin) / (Ymax - Ymin) * abs(DrawingRect.Height())));

		pDC->MoveTo(DrawingRect.left + int((data[i].x - Xmin) / (Xmax - Xmin) * DrawingRect.Width()), 
			DrawingRect.top - int((data[i].y - Ymin) / (Ymax - Ymin) * abs(DrawingRect.Height())) - 100);

		pDC->LineTo(DrawingRect.left + int((data[i].x - Xmin) / (Xmax - Xmin) * DrawingRect.Width()), 
			DrawingRect.top - int((data[i].y - Ymin) / (Ymax - Ymin) * abs(DrawingRect.Height())) + 101);
	}

	break;
	}

	pDC->SelectObject(oldPen);
	clrPen.DeleteObject();
}

int Histogramme::GetHistogrammeType()
{
	return histogrammeType;
}

void Histogramme::SetHistogrammeType(int NewType)
{
	histogrammeType = NewType;
}

BOOL Histogramme::GetPercentStatus()
{
	return percentEnabled;
}

void Histogramme::SetPercentStatus(BOOL NewStatus)
{
	percentEnabled = NewStatus;
}

double Histogramme::GetyMaxPercentValue()
{
	return yMaxPercentValue;
}

void Histogramme::SetyMaxPercentValue(double NewValue)
{
	yMaxPercentValue = NewValue;
}

void Histogramme::PlotEx(CDC *pDC, int dCount, int *p, COLORREF couleur)
{
	CPen *oldPen, clrPen;
	int i, x, y;
	double percent;
	CPoint pt;

	clrPen.CreatePen(PS_SOLID, 1, couleur);
	oldPen = (CPen *)pDC->SelectObject(&clrPen);

	switch (histogrammeType)
	{
		// -------------------------------------------------------------------------------
		case HISTO_COURBE :
	i = 0;
	x = DrawingRect.left + int((i - Xmin) / (Xmax - Xmin) * DrawingRect.Width());
	percent = (p[i] - Ymin) / (Ymax - Ymin);

	if (percent >= 0 && percent <= 1.0)
	{
		y = DrawingRect.top - int(percent * abs(DrawingRect.Height()));
		pDC->MoveTo(x, y);
	}
	else
	{
		y = (percent < 0) ? DrawingRect.top : DrawingRect.bottom;
		fleche(pDC, CRect(x, y, x, y), FLECHE_EXT);
	}

	pt.x = x; pt.y = y;
	for (i = 0 ; i < dCount ; i++)
	{
		x = DrawingRect.left + int((i - Xmin) / (Xmax - Xmin) * DrawingRect.Width());
		percent = (p[i] - Ymin) / (Ymax - Ymin);

		if (percent >= 0 && percent <= 1.0)
		{
			y = DrawingRect.top - int(percent * abs(DrawingRect.Height()));
			pDC->LineTo(x, y);
			pt.x = x; pt.y = y;
		}
		else
		{
			y = (percent < 0) ? DrawingRect.top : DrawingRect.bottom;
			fleche(pDC, CRect(pt.x, pt.y, x, y), FLECHE_EXT);
		}
			
		
	}

	break;

		// -------------------------------------------------------------------------------
		case HISTO_DISCRET:
	for (i = 0 ; i < dCount ; i++)
	{
		x = DrawingRect.left + int((i - Xmin) / (Xmax - Xmin) * DrawingRect.Width());
		percent = (p[i] - Ymin) / (Ymax - Ymin);
		y = DrawingRect.top - int((p[i] - Ymin) / (Ymax - Ymin) * abs(DrawingRect.Height()));

		if (percent >= 0 && percent <= 1.0)
		{
			y = DrawingRect.top - int(percent * abs(DrawingRect.Height()));
			pDC->MoveTo(x, DrawingRect.bottom);
			pDC->LineTo(x, y);
		}
		else
		{
			y = (percent < 0) ? DrawingRect.top : DrawingRect.bottom;
			fleche(pDC, CRect(x, DrawingRect.bottom, x, y), FLECHE_EXT);
		}
	}

	break;

		// -------------------------------------------------------------------------------
		case HISTO_POINTS :
	for (i = 0 ; i < dCount ; i++)
	{
		x = DrawingRect.left + int((i - Xmin) / (Xmax - Xmin) * DrawingRect.Width());
		percent = (p[i] - Ymin) / (Ymax - Ymin);
		if (percent > 1.0 || percent < 0.0) continue;

		y = DrawingRect.top - int((p[i] - Ymin) / (Ymax - Ymin) * abs(DrawingRect.Height()));

		pDC->MoveTo(x - 100, y);
		pDC->LineTo(x + 101, y);

		pDC->MoveTo(x, y - 100);
		pDC->LineTo(x, y + 101);
	}

	break;
	}

	pDC->SelectObject(oldPen);
	clrPen.DeleteObject();
}


void Histogramme::SetXSclFormat(CString NewFormat)
{
	XSclFormat = NewFormat;
}

CString Histogramme::GetXSclFormat()
{
	return XSclFormat;
}

void Histogramme::SetYSclFormat(CString NewFormat)
{
	YSclFormat = NewFormat;
}

CString Histogramme::GetYSclFormat()
{
	return YSclFormat;
}

void Histogramme::NearPlot(CDC *pDC, CPoint point, COLORREF couleur)
{
	CBrush brush(couleur), *oldBrush;
	CPen pen(PS_SOLID, 1, couleur), *oldPen;
	
	oldBrush = (CBrush *)pDC->SelectObject(&brush);
	oldPen = (CPen*)pDC->SelectObject(&pen);

	pDC->Rectangle(CRect(point.x - 150, point.y - 150, point.x + 150, point.y + 150));

	pDC->SelectObject(oldBrush);
	pDC->SelectObject(oldPen);

	brush.DeleteObject();
	pen.DeleteObject();
}

HistoPointData Histogramme::DPtoLP(CPoint point)
{
	HistoPointData hpData;
	
	hpData.x = double(point.x - DrawingRect.left) / double(DrawingRect.Width()) * 
				(Xmax - Xmin) + Xmin;
	hpData.y = Ymax - double(DrawingRect.bottom - point.y) / double(DrawingRect.Height()) * 
				(Ymax - Ymin);
	
	return hpData;
}

CPoint Histogramme::LPtoDP(HistoPointData hpData)
{
	double  maxX = (Xmax > Xmin) ? Xmax : Xmin,
			minX = (Xmax > Xmin) ? Xmin : Xmax,
			maxY = (Ymax > Ymin) ? Ymax : Ymin,
			minY = (Ymax > Ymin) ? Ymin : Ymax;

	if (hpData.x > maxX || hpData.x < minX) return CPoint(-1, -1);
	if (hpData.y > maxY || hpData.y < minY) return CPoint(-1, -1);

	return CPoint(
		DrawingRect.left + int((hpData.x - Xmin) / (Xmax - Xmin) * abs(DrawingRect.Width())),
		DrawingRect.top - int((hpData.y - Ymin) / (Ymax - Ymin) * abs(DrawingRect.Height())));
}

BOOL Histogramme::IsInDrawingRect(CPoint point)
{
	int minX = (DrawingRect.left > DrawingRect.right) ? DrawingRect.right : DrawingRect.left;
	int	maxX = (DrawingRect.left < DrawingRect.right) ? DrawingRect.right : DrawingRect.left;

	int minY = (DrawingRect.top > DrawingRect.bottom) ? DrawingRect.bottom : DrawingRect.top;
	int	maxY = (DrawingRect.top < DrawingRect.bottom) ? DrawingRect.bottom : DrawingRect.top;

	return (point.x >= minX && point.x <= maxX && point.y >= minY && point.y <= maxY);
}
