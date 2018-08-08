// PictureHistogrammeView.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "PictureHistogrammeView.h"
#include "PictureHistogrammeSettingsDlg.h"
#include "PictureHistogrammeFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPictureHistogrammeView

IMPLEMENT_DYNCREATE(CPictureHistogrammeView, CView)

BEGIN_MESSAGE_MAP(CPictureHistogrammeView, CView)
	//{{AFX_MSG_MAP(CPictureHistogrammeView)
	ON_COMMAND(ID_OUTILS_COMPOSANTEBLEU, OnOutilsComposantebleu)
	ON_COMMAND(ID_OUTILS_COMPOSANTEROUGE, OnOutilsComposanterouge)
	ON_COMMAND(ID_OUTILS_COMPOSANTEVERTE, OnOutilsComposanteverte)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_COMPOSANTEBLEU, OnUpdateOutilsComposantebleu)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_COMPOSANTEROUGE, OnUpdateOutilsComposanterouge)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_COMPOSANTEVERTE, OnUpdateOutilsComposanteverte)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_QUADRILLAGEX, OnUpdateOutilsQuadrillagex)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_QUADRILLAGEY, OnUpdateOutilsQuadrillagey)
	ON_COMMAND(ID_OUTILS_QUADRILLAGEX, OnOutilsQuadrillagex)
	ON_COMMAND(ID_OUTILS_QUADRILLAGEY, OnOutilsQuadrillagey)
	ON_COMMAND(ID_OUTILS_COURBE, OnOutilsCourbe)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_COURBE, OnUpdateOutilsCourbe)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_DISCRET, OnUpdateOutilsDiscret)
	ON_COMMAND(ID_OUTILS_DISCRET, OnOutilsDiscret)
	ON_COMMAND(ID_OUTILS_POINTS, OnOutilsPoints)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_POINTS, OnUpdateOutilsPoints)
	ON_COMMAND(ID_OUTILS_ECHELLEX, OnOutilsEchellex)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_ECHELLEX, OnUpdateOutilsEchellex)
	ON_COMMAND(ID_OUTILS_ECHELLEY, OnOutilsEchelley)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_ECHELLEY, OnUpdateOutilsEchelley)
	ON_COMMAND(ID_OUTILS_ECHELLEYENPOURCENT, OnOutilsEchelleyenpourcent)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_ECHELLEYENPOURCENT, OnUpdateOutilsEchelleyenpourcent)
	ON_COMMAND(ID_OUTILS_TITREAXEDESX, OnOutilsTitreaxedesx)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_TITREAXEDESX, OnUpdateOutilsTitreaxedesx)
	ON_COMMAND(ID_OUTILS_TITREAXEDESY, OnOutilsTitreaxedesy)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_TITREAXEDESY, OnUpdateOutilsTitreaxedesy)
	ON_COMMAND(ID_OUTILS_TITREDUGRAPHE, OnOutilsTitredugraphe)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_TITREDUGRAPHE, OnUpdateOutilsTitredugraphe)
	ON_WM_CONTEXTMENU()
	ON_WM_INITMENUPOPUP()
	ON_COMMAND(ID_OUTILS_PARAMTRES, OnOutilsParamtres)
	ON_COMMAND(ID_OUTILS_HISTOGRAMMEUMULATIF, OnOutilsHistogrammeumulatif)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_OUTILS_HISTOGRAMMEDELIMAGE, OnOutilsHistogrammedelimage)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_HISTOGRAMMEDELIMAGE, OnUpdateOutilsHistogrammedelimage)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_HISTOGRAMMEUMULATIF, OnUpdateOutilsHistogrammeumulatif)
	ON_WM_MOUSEMOVE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPictureHistogrammeView diagnostics

#ifdef _DEBUG
void CPictureHistogrammeView::AssertValid() const
{
	CView::AssertValid();
}

void CPictureHistogrammeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPictureHistogrammeView message handlers

CRmtSensingDoc* CPictureHistogrammeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRmtSensingDoc)));
	return (CRmtSensingDoc*)m_pDocument;
}

CPictureHistogrammeView::CPictureHistogrammeView()
{
	graphType = PICTURE_HISTOGRAMME;
	ComposanteRouge = ComposanteVerte = ComposanteBleu = TRUE;
	QuadrillageX = QuadrillageY = TRUE;
	histoType = HISTO_DISCRET;

	XSclEnabled = YSclEnabled = YSclPercent = TRUE;
	XTitleEnabled = YTitleEnabled = TitleEnabled = TRUE;

	XTitleText = "Luminosité";
	YTitleText = "Pixels";

	PicHistTitle = "Histogramme de l'image";
	PicCumTitle = "Histogramme Cumulatif";

	GraphText = PicHistTitle;

	sclX = 50;
	max_div_scl = 5;

	max = 20000;

	rePaint = FALSE;
	pChild = NULL;
}

CPictureHistogrammeView::~CPictureHistogrammeView()
{
}
/////////////////////////////////////////////////////////////////////////////
// CPictureHistogrammeView drawing

void CPictureHistogrammeView::OnInitialUpdate()
{
	CRmtSensingDoc* pDoc = 	GetDocument();

	pDoc->bmpManip.GetHistogrammeInfo();
	
	nbrPix = pDoc->bmpManip.GetWidth() * pDoc->bmpManip.GetHeight();

	pDoc->FindRGBMax();
	pDoc->histoPlotted = TRUE;
}

void CPictureHistogrammeView::OnDraw(CDC* pDC)
{
	CRmtSensingDoc* pDoc = GetDocument();
	CRect rect;

	pDC->SetMapMode(MM_HIMETRIC);

	if (pDC->IsPrinting())
	{
		rect.top = rect.left = 0;
		rect.right = 20000;
		rect.bottom = -15000;
	}
	else
	{
		GetClientRect(&rect);
		pDC->DPtoLP(&rect);
	}

	if (graphType == PICTURE_HISTOGRAMME) DefaultYMax();

	max = (graphType == PICTURE_HISTOGRAMME) ? max : nbrPix;
	
	Histogramme_Image.SetHistogrammeRect(rect);

	Histogramme_Image.SetXSclFormat("%5.0f");
	
	Histogramme_Image.SetXmin(0);
	Histogramme_Image.SetXmax(255);

	Histogramme_Image.SetYmin((double)max);
	Histogramme_Image.SetYmax(0);

	Histogramme_Image.SetXscl(sclX);
	Histogramme_Image.SetYscl((double) max / max_div_scl);

	Histogramme_Image.SetQuadrType(	((QuadrillageX) ? QUADRILLAGE_X : 0) | 
									((QuadrillageY) ? QUADRILLAGE_Y : 0));

	Histogramme_Image.SetXAxisTitle(XTitleText);
	Histogramme_Image.SetXAxisTitleState(XTitleEnabled);

	Histogramme_Image.SetYAxisTitle(YTitleText);
	Histogramme_Image.SetYAxisTitleState(YTitleEnabled);

	Histogramme_Image.SetHistoTitle(GraphText);
	Histogramme_Image.SetHistoTitleState(TitleEnabled);

	Histogramme_Image.SetXScaleValueState(XSclEnabled);
	Histogramme_Image.SetYScaleValueState(YSclEnabled);

	Histogramme_Image.SetPercentStatus(YSclPercent);
	Histogramme_Image.SetyMaxPercentValue((double) nbrPix);

	Histogramme_Image.SetHistogrammeType(histoType);

	Histogramme_Image.SetDrawingRect(pDC);
	Histogramme_Image.InitDrawingRect(pDC);

	if (ComposanteBleu)
	{
		Histogramme_Image.PlotEx(pDC, 256, 
			(graphType == PICTURE_HISTOGRAMME) ? pDoc->picData : pDoc->cumData, RGB(0, 0, 255));
	}

	if (ComposanteVerte)
	{
		Histogramme_Image.PlotEx(pDC, 256, 
			(graphType == PICTURE_HISTOGRAMME) ? (pDoc->picData + 256) : (pDoc->cumData + 256), RGB(0, 255, 0));
	}
			
	if (ComposanteRouge)
	{
		Histogramme_Image.PlotEx(pDC, 256, 
			(graphType == PICTURE_HISTOGRAMME) ? (pDoc->picData + 512) : (pDoc->cumData + 512), RGB(255, 0, 0));
	}

	rePaint = TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CPictureHistogrammeView message handlers

void CPictureHistogrammeView::OnOutilsComposantebleu() 
{
	ComposanteBleu = (ComposanteBleu) ? FALSE : TRUE;	
	Invalidate();
}

void CPictureHistogrammeView::OnOutilsComposanterouge() 
{
	ComposanteRouge = (ComposanteRouge) ? FALSE : TRUE;
	Invalidate();
}

void CPictureHistogrammeView::OnOutilsComposanteverte() 
{
	ComposanteVerte = (ComposanteVerte) ? FALSE : TRUE;
	Invalidate();
}

void CPictureHistogrammeView::OnUpdateOutilsComposantebleu(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(ComposanteBleu);	
}

void CPictureHistogrammeView::OnUpdateOutilsComposanterouge(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(ComposanteRouge);
}

void CPictureHistogrammeView::OnUpdateOutilsComposanteverte(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(ComposanteVerte);
}

void CPictureHistogrammeView::OnUpdateOutilsQuadrillagex(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(QuadrillageX);	
}

void CPictureHistogrammeView::OnUpdateOutilsQuadrillagey(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(QuadrillageY);
}

void CPictureHistogrammeView::OnOutilsQuadrillagex() 
{
	QuadrillageX = (QuadrillageX) ? FALSE : TRUE;
	Invalidate();	
}

void CPictureHistogrammeView::OnOutilsQuadrillagey() 
{
	QuadrillageY = (QuadrillageY) ? FALSE : TRUE;
	Invalidate();
}

void CPictureHistogrammeView::OnOutilsCourbe() 
{
	histoType = HISTO_COURBE;	
	Invalidate();
}

void CPictureHistogrammeView::OnUpdateOutilsCourbe(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck((histoType == HISTO_COURBE));
}

void CPictureHistogrammeView::OnUpdateOutilsDiscret(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck((histoType == HISTO_DISCRET));	
}

void CPictureHistogrammeView::OnOutilsDiscret() 
{
	histoType = HISTO_DISCRET;
	Invalidate();
}

void CPictureHistogrammeView::OnOutilsPoints() 
{
	histoType = HISTO_POINTS;
	Invalidate();
}

void CPictureHistogrammeView::OnUpdateOutilsPoints(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck((histoType == HISTO_POINTS));
}

void CPictureHistogrammeView::OnOutilsEchellex() 
{
	XSclEnabled = (XSclEnabled) ? FALSE : TRUE;	
	Invalidate();
}

void CPictureHistogrammeView::OnUpdateOutilsEchellex(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(XSclEnabled);
}

void CPictureHistogrammeView::OnOutilsEchelley() 
{
	YSclEnabled = (YSclEnabled) ? FALSE : TRUE;
	Invalidate();
}

void CPictureHistogrammeView::OnUpdateOutilsEchelley(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(YSclEnabled);
}

void CPictureHistogrammeView::OnOutilsEchelleyenpourcent() 
{
	YSclPercent = (YSclPercent) ? FALSE : TRUE;
	Invalidate();	
}

void CPictureHistogrammeView::OnUpdateOutilsEchelleyenpourcent(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(YSclPercent);
}

void CPictureHistogrammeView::OnOutilsTitreaxedesx() 
{
	XTitleEnabled = (XTitleEnabled) ? FALSE : TRUE;
	Invalidate();
}

void CPictureHistogrammeView::OnUpdateOutilsTitreaxedesx(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(XTitleEnabled);	
}

void CPictureHistogrammeView::OnOutilsTitreaxedesy() 
{
	YTitleEnabled = (YTitleEnabled) ? FALSE : TRUE;
	Invalidate();
}

void CPictureHistogrammeView::OnUpdateOutilsTitreaxedesy(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(YTitleEnabled);	
}

void CPictureHistogrammeView::OnOutilsTitredugraphe() 
{
	TitleEnabled = (TitleEnabled) ? FALSE : TRUE;
	Invalidate();
}

void CPictureHistogrammeView::OnUpdateOutilsTitredugraphe(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(TitleEnabled);	
}

void CPictureHistogrammeView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	CMenu popup;

	popup.LoadMenu(IDR_PICTUREHISTOGRAMME);
	popup.GetSubMenu(3)->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);

	popup.Detach();
}

void CPictureHistogrammeView::OnInitMenuPopup(CMenu *pMenuPopup, UINT nIndex, BOOL sysMenu)
{
	pMenuPopup->EnableMenuItem(ID_OUTILS_PARAMTRES, MF_ENABLED);

	pMenuPopup->CheckMenuItem(ID_OUTILS_COMPOSANTEROUGE, 
								(ComposanteRouge) ? MF_CHECKED : MF_UNCHECKED);
	pMenuPopup->CheckMenuItem(ID_OUTILS_COMPOSANTEVERTE, 
								(ComposanteVerte) ? MF_CHECKED : MF_UNCHECKED);
	pMenuPopup->CheckMenuItem(ID_OUTILS_COMPOSANTEBLEU, 
								(ComposanteBleu) ? MF_CHECKED : MF_UNCHECKED);
	
	pMenuPopup->CheckMenuItem(ID_OUTILS_QUADRILLAGEX, 
								(QuadrillageX) ? MF_CHECKED : MF_UNCHECKED);
	pMenuPopup->CheckMenuItem(ID_OUTILS_QUADRILLAGEY, 
								(QuadrillageY) ? MF_CHECKED : MF_UNCHECKED);

	pMenuPopup->CheckMenuItem(ID_OUTILS_COURBE, 
								(histoType == HISTO_COURBE) ? MF_CHECKED : MF_UNCHECKED);
	pMenuPopup->CheckMenuItem(ID_OUTILS_DISCRET, 
								(histoType == HISTO_DISCRET) ? MF_CHECKED : MF_UNCHECKED);
	pMenuPopup->CheckMenuItem(ID_OUTILS_POINTS, 
								(histoType == HISTO_POINTS) ? MF_CHECKED : MF_UNCHECKED);

	pMenuPopup->CheckMenuItem(ID_OUTILS_ECHELLEX, 
								(XSclEnabled) ? MF_CHECKED : MF_UNCHECKED);
	pMenuPopup->CheckMenuItem(ID_OUTILS_ECHELLEY, 
								(YSclEnabled) ? MF_CHECKED : MF_UNCHECKED);
	pMenuPopup->CheckMenuItem(ID_OUTILS_ECHELLEYENPOURCENT, 
								(YSclPercent) ? MF_CHECKED : MF_UNCHECKED);

	pMenuPopup->CheckMenuItem(ID_OUTILS_TITREAXEDESX, 
								(XTitleEnabled) ? MF_CHECKED : MF_UNCHECKED);
	pMenuPopup->CheckMenuItem(ID_OUTILS_TITREAXEDESY, 
								(YTitleEnabled) ? MF_CHECKED : MF_UNCHECKED);
	pMenuPopup->CheckMenuItem(ID_OUTILS_TITREDUGRAPHE, 
								(TitleEnabled) ? MF_CHECKED : MF_UNCHECKED);
	
	pMenuPopup->CheckMenuItem(ID_OUTILS_HISTOGRAMMEUMULATIF, 
								(graphType == CUMULATIF_HISTOGRAMME) ? MF_CHECKED : MF_UNCHECKED);
	pMenuPopup->CheckMenuItem(ID_OUTILS_HISTOGRAMMEDELIMAGE, 
								(graphType == PICTURE_HISTOGRAMME) ? MF_CHECKED : MF_UNCHECKED);
}

void CPictureHistogrammeView::OnOutilsParamtres() 
{
	CPictureHistogrammeSettingsDlg picHistDlg(this);

	picHistDlg.m_ComposanteBleu = ComposanteBleu;
	picHistDlg.m_ComposanteRouge = ComposanteRouge;
	picHistDlg.m_ComposanteVerte = ComposanteVerte;

	picHistDlg.m_GraphTitleText = Histogramme_Image.GetHistoTitle();
	picHistDlg.m_GraphTitleEnabled = TitleEnabled;

	picHistDlg.m_XTitleEnabled = XTitleEnabled;
	picHistDlg.m_XTitleText = Histogramme_Image.GetXAxisTitle();

	picHistDlg.m_YTitleEnabled = YTitleEnabled;
	picHistDlg.m_YTitleText = Histogramme_Image.GetYAxisTitle();

	picHistDlg.m_QuadrillageX = QuadrillageX;
	picHistDlg.m_QuadrillageY = QuadrillageY;

	picHistDlg.m_GraphType = histoType - 1;

	picHistDlg.m_YMaxPercentDbl = 100.0 * Histogramme_Image.GetYmin() / (double) nbrPix;
	picHistDlg.m_YMaxPixelsDbl = max;

	picHistDlg.m_XsclEnabled = XSclEnabled;
	picHistDlg.m_YsclEnabled = YSclEnabled;
	picHistDlg.m_YPercentage = YSclPercent;

	picHistDlg.m_radio_maxX = 0;
	picHistDlg.m_radio_maxY = 0;

	picHistDlg.m_maxX_divN_value = Histogramme_Image.GetXmax() / Histogramme_Image.GetXscl();
	picHistDlg.m_maxX_percent_value = Histogramme_Image.GetXscl() / Histogramme_Image.GetXmax() * 100.0;
	picHistDlg.m_maxX_pixels_value = Histogramme_Image.GetXscl();

	picHistDlg.m_maxY_divN_value = Histogramme_Image.GetYmin() / Histogramme_Image.GetYscl();
	picHistDlg.m_maxY_percent_value = Histogramme_Image.GetYscl() / nbrPix * 100.0;
	picHistDlg.m_maxY_pixels_value = Histogramme_Image.GetYscl();

	picHistDlg.m_YMaxType = 0;

	if (picHistDlg.DoModal() == IDCANCEL) return;

	ComposanteBleu = picHistDlg.m_ComposanteBleu;
	ComposanteRouge = picHistDlg.m_ComposanteRouge;
	ComposanteVerte = picHistDlg.m_ComposanteVerte;

	if (graphType == PICTURE_HISTOGRAMME)
		PicHistTitle = picHistDlg.m_GraphTitleText;
	else
		PicCumTitle = picHistDlg.m_GraphTitleText;
	
	GraphText = picHistDlg.m_GraphTitleText;
	TitleEnabled = picHistDlg.m_GraphTitleEnabled;

	XTitleEnabled = picHistDlg.m_XTitleEnabled;
	XTitleText = picHistDlg.m_XTitleText;

	YTitleEnabled = picHistDlg.m_YTitleEnabled;
	YTitleText = picHistDlg.m_YTitleText;

	QuadrillageX = picHistDlg.m_QuadrillageX;
	QuadrillageY = picHistDlg.m_QuadrillageY;

	histoType = picHistDlg.m_GraphType + 1;

	if (picHistDlg.m_YMaxType == 2) max = (int)picHistDlg.m_YMaxPixelsDbl;
	else if (picHistDlg.m_YMaxType == 1) max = (int) (nbrPix * picHistDlg.m_YMaxPercentDbl / 100);
	else DefaultYMax();

	switch (picHistDlg.m_radio_maxX)
	{
	case 0 :
		sclX = 255.0 / picHistDlg.m_maxX_divN_value; break;
	case 1:
		sclX = 255.0 * picHistDlg.m_maxX_percent_value / 100.0; break;
	case 2:
		sclX = picHistDlg.m_maxX_pixels_value;break;
	}


	switch (picHistDlg.m_radio_maxY)
	{
	case 0 :
		max_div_scl = picHistDlg.m_maxY_divN_value; break;
	case 1:
		max_div_scl = max / (nbrPix * picHistDlg.m_maxY_percent_value / 100); break;
	case 2:
		if (graphType == PICTURE_HISTOGRAMME)
			max_div_scl = max / picHistDlg.m_maxY_pixels_value;
		else
			max_div_scl = nbrPix / picHistDlg.m_maxY_pixels_value;
	break;
	}

	XSclEnabled = picHistDlg.m_XsclEnabled;
	YSclEnabled = picHistDlg.m_YsclEnabled;
	YSclPercent = picHistDlg.m_YPercentage;

	Invalidate();
}

void CPictureHistogrammeView::DefaultYMax()
{
	CRmtSensingDoc* pDoc = GetDocument();

	max = pDoc->rYmax;
	if (pDoc->gYmax > max) max = pDoc->gYmax;
	if (pDoc->bYmax > max) max = pDoc->bYmax;
}

void CPictureHistogrammeView::OnOutilsHistogrammeumulatif() 
{
	CRmtSensingDoc* pDoc = GetDocument();

	graphType = CUMULATIF_HISTOGRAMME;
	GraphText = PicCumTitle;	
	max_div_scl = nbrPix / Histogramme_Image.GetYscl();
	if (max_div_scl > 50) max_div_scl = 20;

	Invalidate();	
}

BOOL CPictureHistogrammeView::OnPreparePrinting(CPrintInfo* pInfo) 
{
	return DoPreparePrinting(pInfo);
}

void CPictureHistogrammeView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
}

void CPictureHistogrammeView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
}

void CPictureHistogrammeView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	OnDraw(pDC);
}

void CPictureHistogrammeView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	CView::OnPrepareDC(pDC, pInfo);
}

void CPictureHistogrammeView::OnEditCopy() 
{
	if (OpenClipboard())
	{
		CRmtSensingDoc *pDoc = GetDocument();
		CClientDC dc(this);

		CRect rect;
		GetClientRect(&rect);

		CDC memDC; memDC.CreateCompatibleDC(&dc);
		CBitmap bmp; bmp.CreateDiscardableBitmap(&dc, rect.Width(), rect.Height());
		memDC.SelectObject(&bmp);

		memDC.Rectangle(rect);
		OnDraw(&memDC);


		BeginWaitCursor();
		EmptyClipboard();
		SetClipboardData(CF_BITMAP, HBITMAP(bmp));
		CloseClipboard();
		EndWaitCursor();

		bmp.DeleteObject();
		memDC.DeleteDC();
	}	
}

void CPictureHistogrammeView::OnOutilsHistogrammedelimage() 
{
	CRmtSensingDoc* pDoc = GetDocument();

	graphType = PICTURE_HISTOGRAMME;
	GraphText = PicHistTitle;	
	DefaultYMax();
	max_div_scl = max / Histogramme_Image.GetYscl();

	Invalidate();
}

void CPictureHistogrammeView::OnUpdateOutilsHistogrammedelimage(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck((graphType == PICTURE_HISTOGRAMME));
}

void CPictureHistogrammeView::OnUpdateOutilsHistogrammeumulatif(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck((graphType == CUMULATIF_HISTOGRAMME));
}

void CPictureHistogrammeView::OnMouseMove(UINT nFlags, CPoint point) 
{
	CRmtSensingDoc* pDoc = GetDocument();
	CClientDC dc(this);
	HistoPointData hpData;
	
	dc.SetMapMode(MM_HIMETRIC);
	dc.DPtoLP(&point);

	hpData = Histogramme_Image.DPtoLP(point);
	
	if (Histogramme_Image.IsInDrawingRect(point))
	{
		if (ComposanteRouge ||ComposanteBleu || ComposanteVerte)
		{
			CString str;
			char rvb = (ComposanteRouge == TRUE) ? 2 : 
					((ComposanteVerte == TRUE) ? 1 : 0);
		
			hpData.x = int(hpData.x);
			hpData.y = (graphType == PICTURE_HISTOGRAMME) ? 
						pDoc->picData[rvb * 256 + int(hpData.x) % 256] :
						pDoc->cumData[rvb * 256 + int(hpData.x) % 256];
		
			point = Histogramme_Image.LPtoDP(hpData);

			str.Format("Position = (x : %d, y : %d)", int(hpData.x), int(hpData.y));

			if (pChild)
				pChild->m_wndStatusBar.SetPaneText(0, str);

			static HistoPointData hpd;
		
			dc.SetROP2(R2_NOT);
			
			if (!rePaint) 
			{
				Histogramme_Image.NearPlot(&dc, Histogramme_Image.LPtoDP(hpd), RGB(255, 0, 0));
			} else rePaint = FALSE;

			Histogramme_Image.NearPlot(&dc, point, RGB(255, 0, 0));

			dc.SetROP2(R2_COPYPEN);
		
			hpd.x = int(hpData.x);
			hpd.y = hpData.y;
		}
	}
}


void CPictureHistogrammeView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	if (!pChild && pActivateView == this)
	{
		CMDIFrameWnd *pFrame = (CMDIFrameWnd*)AfxGetApp()->m_pMainWnd;
		// Get the active MDI child window.
		pChild = (CPictureHistogrammeFrame *) pFrame->GetActiveFrame();	
	}

	CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}

void CPictureHistogrammeView::OnDestroy() 
{
	CView::OnDestroy();
	
	GetDocument()->histoPlotted = FALSE;
}
