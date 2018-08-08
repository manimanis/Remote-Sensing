// RmtSensingView.cpp : implementation of the CRmtSensingView class
//

#include "stdafx.h"
#include "RmtSensing.h"

#include "RmtSensingDoc.h"
#include "RmtSensingView.h"
#include "ChildFrm.h"

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include "PictureHistogrammeSettingsDlg.h"
#include "SaturatingLinearExpansion.h"
#include "LogarithmicExpansion.h"
#include "ExponentialExpansion.h"
#include "PieceWiseLinearExpansion.h"
#include "LinearExpansion.h"
#include "PictureHistogrammeView.h"
#include "ComposanteR.h"
#include "ComposanteG.h"
#include "ComposanteB.h"

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingView

IMPLEMENT_DYNCREATE(CRmtSensingView, CView)

BEGIN_MESSAGE_MAP(CRmtSensingView, CView)
	//{{AFX_MSG_MAP(CRmtSensingView)
	ON_COMMAND(ID_PICTURE_INFO, OnPictureInfo)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_OUTILS_EXPANSIONLINAIRE, OnOutilsExpansionlinaire)
	ON_COMMAND(ID_OUTILS_AJUSTEXY, OnOutilsAjustexy)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_AJUSTEXY, OnUpdateOutilsAjustexy)
	ON_COMMAND(ID_OUTILS_CENTRE, OnOutilsCentre)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_CENTRE, OnUpdateOutilsCentre)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_EXPANSIONLINAIRE, OnUpdateOutilsExpansionlinaire)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, OnUpdateEditUndo)
	ON_COMMAND(ID_OUTILS_EXPANSIONLINAIREAVECSATURATION, OnOutilsExpansionlinaireavecsaturation)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_EXPANSIONLINAIREAVECSATURATION, OnUpdateOutilsExpansionlinaireavecsaturation)
	ON_COMMAND(ID_OUTILS_EXPANSIONLOGARITHMIQUE, OnOutilsExpansionlogarithmique)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_EXPANSIONLOGARITHMIQUE, OnUpdateOutilsExpansionlogarithmique)
	ON_COMMAND(ID_OUTILS_EXPANSIONEXPONENTIELLE, OnOutilsExpansionexponentielle)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_EXPANSIONEXPONENTIELLE, OnUpdateOutilsExpansionexponentielle)
	ON_COMMAND(ID_OUTILS_EXPANSIONLINAIRESEGMENTE, OnOutilsExpansionlinairesegmente)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_EXPANSIONLINAIRESEGMENTE, OnUpdateOutilsExpansionlinairesegmente)
	ON_COMMAND(ID_OUTILS_HISTOGRAMMEDELIMAGE, OnOutilsHistogrammedelimage)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_HISTOGRAMMEDELIMAGE, OnUpdateOutilsHistogrammedelimage)
	ON_COMMAND(ID_OUTILS_COMPOSANTESRGB, OnOutilsComposantesrgb)
	ON_UPDATE_COMMAND_UI(ID_OUTILS_COMPOSANTESRGB, OnUpdateOutilsComposantesrgb)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingView construction/destruction

CRmtSensingView::CRmtSensingView()
{
	bmpCentered = FALSE;
	bmpAdjustXY = TRUE;
	linExpDone = FALSE;
	copyMode = FALSE;
	satLinExpDone = FALSE;

	wnd = NULL;
}

CRmtSensingView::~CRmtSensingView()
{
}

BOOL CRmtSensingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingView drawing

void CRmtSensingView::OnDraw(CDC* pDC)
{
	CRmtSensingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

/*
	unsigned char *p, *p2, *pBmpData = p = p2 = (unsigned char *)bm.bmBits;

	for (int i = 0 ; i < bm.bmHeight ; i++)
	{
		for (int j = 0 ; j < bm.bmWidth ; j++)
		{
			pDC->SetPixel(j, i, RGB(*(p + 2), *(p + 1), *p));
			
			p += 3;
		}
		p = p2;
		p = p2 = p + bm.bmWidthBytes;
	}
// */ 

	CRect OutsideRect;
	CBrush brush(HS_DIAGCROSS, RGB(220, 220, 220)), *oldBrush;
	CPen pen(PS_NULL, 1, RGB(0, 0, 0)), *oldPen;
	int Width, Height;

	oldBrush = (CBrush*) pDC->SelectObject(&brush);
	oldPen = (CPen*) pDC->SelectObject(&pen);

	if (pDC->IsPrinting())
	{
		pDC->SetMapMode(MM_HIMETRIC);
		OutsideRect.top = OutsideRect.left = 0;
		OutsideRect.right = 20000;
		OutsideRect.bottom = -15000;
	}
	else
	{
		GetClientRect(&OutsideRect);
	}

	PicRect = OutsideRect;

	pDC->Rectangle(&OutsideRect);
	if (bmpCentered)
	{
		if (OutsideRect.Width() > pDoc->bmpManip.GetWidth()) 
		{
			PicRect.left = (OutsideRect.Width() - pDoc->bmpManip.GetWidth()) / 2;
			PicRect.right = PicRect.left + pDoc->bmpManip.GetWidth();
		}

		if (OutsideRect.Height() > pDoc->bmpManip.GetHeight()) 
		{
			PicRect.top = (OutsideRect.Height() - pDoc->bmpManip.GetHeight()) / 2;
			PicRect.bottom = PicRect.top + pDoc->bmpManip.GetHeight();
		}
	}

	if (bmpAdjustXY)
	{
		double ratio = (double)pDoc->bmpManip.GetWidth() / (double)pDoc->bmpManip.GetHeight();
	
		Width = PicRect.Width(); Height = PicRect.Height();

		if (double(PicRect.Width() / PicRect.Height()) > ratio)
			Width = int(ratio * Height);
		else
			Height = Width / ratio;
		
		if (OutsideRect.Width() > Width) 
		{
			PicRect.left = (OutsideRect.Width() - Width) / 2;
			PicRect.right = PicRect.left + Width;
		}

		if (OutsideRect.Height() > Height) 
		{
			PicRect.top = (OutsideRect.Height() - Height) / 2;
			PicRect.bottom = PicRect.top + Height;
		}
	}

	if (copyMode)	pDoc->bmpManip.Draw(pDC, CRect(0, 0, pDoc->bmpManip.GetWidth(), 
															pDoc->bmpManip.GetHeight()));
			else pDoc->bmpManip.Draw(pDC, PicRect);

	pDC->SelectObject(oldBrush);
	pDC->SelectObject(oldPen);

	brush.DeleteObject();
	pen.DeleteObject();
}

void CRmtSensingView::OnInitialUpdate()
{
	CRmtSensingDoc *pDoc = (CRmtSensingDoc *)GetDocument();

	CView::OnInitialUpdate();
	pDoc->bmpManip.GetHistogrammeInfo();
}

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingView printing

BOOL CRmtSensingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRmtSensingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRmtSensingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingView diagnostics

#ifdef _DEBUG
void CRmtSensingView::AssertValid() const
{
	CView::AssertValid();
}

void CRmtSensingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRmtSensingDoc* CRmtSensingView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRmtSensingDoc)));
	return (CRmtSensingDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingView message handlers

void CRmtSensingView::OnPictureInfo() 
{
	CRmtSensingDoc* pDoc = GetDocument();

	pDoc->Informations();
}

void CRmtSensingView::OnOutilsHistogrammedelimage() 
{
	CRmtSensingDoc* pDoc = GetDocument();

	HICON hIcon = AfxGetApp()->LoadIcon(IDI_OUTILS_HISTOGRAMMEDELIMAGE);

	if (pDoc->bmpManip.GetBitCount() < 24) 
	{
		AfxMessageBox("Ce format n'est pas encore pris en charge par le programme");
		return;
	}

	wnd = new CPictureHistogrammeFrame;

	CCreateContext context;

	context.m_pNewViewClass = RUNTIME_CLASS(CPictureHistogrammeView);
	context.m_pCurrentDoc = pDoc;
	context.m_pCurrentFrame = wnd;

	wnd->Create(NULL, "MABROUKA", WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW, 
		CFrameWnd::rectDefault, (CMDIFrameWnd *)AfxGetMainWnd(), &context);

	wnd->InitialUpdateFrame(pDoc, TRUE);
	wnd->SetIcon(hIcon, TRUE);
	wnd->ShowWindow(SW_SHOW);
}

void CRmtSensingView::OnEditCopy() 
{
	CRmtSensingDoc* pDoc = GetDocument();

	if (OpenClipboard())
	{
		CClientDC dc(this);
		CDC memDC; CBitmap Bmp;
		memDC.CreateCompatibleDC(&dc);
		Bmp.CreateDiscardableBitmap(&dc, pDoc->bmpManip.GetWidth(), pDoc->bmpManip.GetHeight());
		memDC.SelectObject(&Bmp);

		copyMode = TRUE;
		OnDraw(&memDC);
		copyMode = FALSE;

		BeginWaitCursor();
		EmptyClipboard();
		SetClipboardData(CF_BITMAP, HBITMAP(Bmp));
		CloseClipboard();
		EndWaitCursor();

		memDC.DeleteDC();
		Bmp.DeleteObject();
	}	
}

void CRmtSensingView::OnOutilsExpansionlinaire() 
{

	CLinearExpansion linExp;	

	Expansion(&linExp);
}

void CRmtSensingView::OnOutilsAjustexy() 
{
	bmpAdjustXY = (bmpAdjustXY) ? FALSE : TRUE;
	Invalidate();
}

void CRmtSensingView::OnUpdateOutilsAjustexy(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(bmpAdjustXY);
}

void CRmtSensingView::OnOutilsCentre() 
{
	bmpCentered = (bmpCentered) ? FALSE : TRUE;
	Invalidate();
}

void CRmtSensingView::OnUpdateOutilsCentre(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(bmpCentered);
}

void CRmtSensingView::OnEditUndo() 
{
	CRmtSensingDoc* pDoc = GetDocument();

	if (linExpDone) linExpDone = FALSE;
	if (satLinExpDone) satLinExpDone = FALSE;

	pDoc->bmpManip.RestoreFromTempCopy(pDoc->oFile);

	pDoc->bmpManip.GetHistogrammeInfo();

	pDoc->FindRGBMax();

	pDoc->UpdateAllViews(NULL);
}

void CRmtSensingView::OnUpdateOutilsExpansionlinaire(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(!linExpDone);
}

void CRmtSensingView::OnUpdateEditUndo(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(TRUE);
}

void CRmtSensingView::OnOutilsExpansionlinaireavecsaturation() 
{
	CSaturatingLinearExpansion linExp;	

	Expansion(&linExp);
}

void CRmtSensingView::OnUpdateOutilsExpansionlinaireavecsaturation(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(!satLinExpDone);	
}

void CRmtSensingView::OnOutilsExpansionlogarithmique() 
{
	CLogarithmicExpansion logExp;
	
	Expansion(&logExp);
}

void CRmtSensingView::OnUpdateOutilsExpansionlogarithmique(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CRmtSensingView::OnOutilsExpansionexponentielle() 
{
	CExponentialExpansion expExp;
	
	Expansion(&expExp);
}

void CRmtSensingView::OnUpdateOutilsExpansionexponentielle(CCmdUI* pCmdUI) 
{
	
}

void CRmtSensingView::OnOutilsExpansionlinairesegmente() 
{
	CPieceWiseLinearExpansion wiseExp;
	
	Expansion(&wiseExp);
}

void CRmtSensingView::OnUpdateOutilsExpansionlinairesegmente(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CRmtSensingView::Expansion(CLookUpTables *lkUpTables)
{
	CRmtSensingDoc* pDoc = GetDocument();

	pDoc->SetModifiedFlag();

	pDoc->bmpManip.GetHistogrammeInfo();

	pDoc->bmpManip.MakeModification(lkUpTables);
	pDoc->bmpManip.GetHistogrammeInfo();

	pDoc->FindRGBMax();

	pDoc->UpdateAllViews(NULL);
}


void CRmtSensingView::OnUpdateOutilsHistogrammedelimage(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(!GetDocument()->histoPlotted);
}

void CRmtSensingView::OnOutilsComposantesrgb() 
{
	CRmtSensingDoc* pDoc = GetDocument();

	if (pDoc->bmpManip.GetBitCount() < 24) 
	{
		AfxMessageBox("Ce format n'est pas encore pris en charge par le programme");
		return;
	}

	CCreateContext context;
	HICON hIcon = AfxGetApp()->LoadIcon(IDI_RGB);

	if (!pDoc->RComponent)
	{
		pDoc->RComponent = TRUE;

		wndR = new CChildFrame;
		
		context.m_pNewViewClass = RUNTIME_CLASS(CComposanteR);
		context.m_pCurrentDoc = pDoc;
		context.m_pCurrentFrame = wndR;

		wndR->Create(NULL, "Rouge", WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW, 
			CFrameWnd::rectDefault, (CMDIFrameWnd *)AfxGetMainWnd(), &context);

		wndR->InitialUpdateFrame(pDoc, TRUE);
		wndR->SetIcon(hIcon, TRUE);

		wndR->ShowWindow(SW_SHOW);		
	}

	if (!pDoc->GComponent)
	{
		pDoc->GComponent = TRUE;

		wndG = new CChildFrame;

		context.m_pNewViewClass = RUNTIME_CLASS(CComposanteG);
		context.m_pCurrentDoc = pDoc;
		context.m_pCurrentFrame = wndG;

		wndG->Create(NULL, "Vert", WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW, 
			CFrameWnd::rectDefault, (CMDIFrameWnd *)AfxGetMainWnd(), &context);
	
		wndG->InitialUpdateFrame(pDoc, TRUE);
		wndG->SetIcon(hIcon, TRUE);

		wndG->ShowWindow(SW_SHOW);	
	}
	
	if (!pDoc->BComponent)
	{
		pDoc->BComponent = TRUE;

		wndB = new CChildFrame;
	
		context.m_pNewViewClass = RUNTIME_CLASS(CComposanteB);
		context.m_pCurrentDoc = pDoc;
		context.m_pCurrentFrame = wndB;

		wndB->Create(NULL, "Bleu", WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW, 
			CFrameWnd::rectDefault, (CMDIFrameWnd *)AfxGetMainWnd(), &context);

		wndB->InitialUpdateFrame(pDoc, TRUE);
		wndB->SetIcon(hIcon, TRUE);

		wndB->ShowWindow(SW_SHOW);		
	}
}

void CRmtSensingView::OnUpdateOutilsComposantesrgb(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}
