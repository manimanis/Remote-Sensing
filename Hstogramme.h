// Histogramme.h: interface for the Histogramme class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Histogramme_H__7AB68333_48EA_11D4_B2B5_00400550E7C9__INCLUDED_)
#define AFX_Histogramme_H__7AB68333_48EA_11D4_B2B5_00400550E7C9__INCLUDED_

#include "Common.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Histogramme  
{
public:
	BOOL IsInDrawingRect(CPoint point);
	CPoint LPtoDP(HistoPointData hpData);
	HistoPointData DPtoLP(CPoint point);
	void NearPlot(CDC *pDC, CPoint point, COLORREF couleur);
	CString GetYSclFormat();
	void SetYSclFormat(CString NewFormat);
	CString GetXSclFormat();
	void SetXSclFormat(CString NewFormat);
	void PlotEx(CDC *pDC, int dCount, int *p, COLORREF couleur);
	void SetyMaxPercentValue(double NewValue);
	double GetyMaxPercentValue();
	void SetPercentStatus(BOOL NewStatus);
	BOOL GetPercentStatus();
	void SetHistogrammeType(int NewType);
	int GetHistogrammeType();
	void Plot(CDC *pDC, COLORREF couleur);
	void SetQuadrType(int NewValue);
	int GetQuadrType();
	void InitDrawingRect(CDC *pDC);
	CRect GetDrawingRect();
	void SetDrawingRect(CDC *pDC);
	void SetYScaleValueState(BOOL NewState);
	BOOL GetYScaleValueState();
	void SetXScaleValueState(BOOL NewState);
	BOOL GetXScaleValueState();
	void SetYAxisTitleState(BOOL NewState);
	BOOL GetYAxisTitleState();
	void SetYAxisTitle(CString NewTitle);
	CString GetYAxisTitle();
	void SetXAxisTitleState(BOOL NewState);
	BOOL GetXAxisTitleState();
	void SetXAxisTitle(CString NewTitle);
	CString GetXAxisTitle();
	void SetHistoTitleState(BOOL NewState);
	BOOL GetHistoTitleState();
	void SetHistoTitle(CString NewTitle);
	CString GetHistoTitle();
	int GetDataPointer(HistoPointData *OldData);
	void SetDataPointer(HistoPointData *NewData, int NewCount);
	void SetHistogrammeRect(CRect NewRect);
	void SetYStep(double NewValue);
	void SetXStep(double NewValue);
	void SetYscl(double NewValue);
	void SetXscl(double NewValue);
	void SetYmax(double NewValue);
	void SetYmin(double NewValue);
	void SetXmax(double NewValue);
	void SetXmin(double NewValue);

	CRect GetHistogrammeRect();
	double GetYStep();
	double GetXStep();
	double GetYscl();
	double GetXscl();
	double GetYmax();
	double GetYmin();
	double GetXmax();
	double GetXmin();
	Histogramme();
	virtual ~Histogramme();

protected:
	CString XSclFormat;
	CString YSclFormat;
	double yMaxPercentValue;
	BOOL percentEnabled;
	int histogrammeType;
	int QuadrType;
	CRect DrawingRect;
	BOOL XScaleValueEnabled;
	BOOL YScaleValueEnabled;
	BOOL YAxisTitleEnabled;
	CString YAxisTitle;
	BOOL XAxisTitleEnabled;
	CString XAxisTitle;
	BOOL HistoTitleEnabled;
	CString HistoTitle;
	int dataCount;
	HistoPointData *data;
	double Yscl;
	double Xscl;
	double YStep;
	double XStep;
	CRect HistogrammeRect;
	double Ymax;
	double Ymin;
	double Xmax;
	double Xmin;
};

#endif // !defined(AFX_Histogramme_H__7AB68333_48EA_11D4_B2B5_00400550E7C9__INCLUDED_)
