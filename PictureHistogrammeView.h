#if !defined(AFX_TESTVIEW_H__07AF57EE_6229_11D4_9E82_0000E8EA8C1A__INCLUDED_)
#define AFX_TESTVIEW_H__07AF57EE_6229_11D4_9E82_0000E8EA8C1A__INCLUDED_

#include "RmtSensingDoc.h"
#include "PictureHistogrammeFrame.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PictureHistogrammeView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPictureHistogrammeView view

class CPictureHistogrammeView : public CView
{
protected:
	CPictureHistogrammeView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CPictureHistogrammeView)

// Attributes
public:
	BOOL rePaint;
// Operations
public:
	CRmtSensingDoc* GetDocument();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPictureHistogrammeView)
	public:
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL TitleEnabled;
	BOOL YTitleEnabled;
	BOOL XTitleEnabled;
	BOOL YSclPercent;
	BOOL YSclEnabled;
	BOOL XSclEnabled;
	int histoType;
	BOOL QuadrillageX;
	BOOL QuadrillageY;
	BOOL ComposanteRouge;
	BOOL ComposanteVerte;
	BOOL ComposanteBleu;
	int nbrPix;
	CRect ClientRect;
	int *picData;
	int *cumData;
	Histogramme Histogramme_Image;
	CPictureHistogrammeFrame *pChild;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
	double max_div_scl;
	double sclX;
	char graphType;
	void DefaultYMax();
	CString GraphText;
	CString YTitleText;
	CString XTitleText;
	int max;
	virtual ~CPictureHistogrammeView();

	// Generated message map functions
protected:
	CString PicCumTitle;
	CString PicHistTitle;
	//{{AFX_MSG(CPictureHistogrammeView)
	afx_msg void OnOutilsComposantebleu();
	afx_msg void OnOutilsComposanterouge();
	afx_msg void OnOutilsComposanteverte();
	afx_msg void OnUpdateOutilsComposantebleu(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOutilsComposanterouge(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOutilsComposanteverte(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOutilsQuadrillagex(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOutilsQuadrillagey(CCmdUI* pCmdUI);
	afx_msg void OnOutilsQuadrillagex();
	afx_msg void OnOutilsQuadrillagey();
	afx_msg void OnOutilsCourbe();
	afx_msg void OnUpdateOutilsCourbe(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOutilsDiscret(CCmdUI* pCmdUI);
	afx_msg void OnOutilsDiscret();
	afx_msg void OnOutilsPoints();
	afx_msg void OnUpdateOutilsPoints(CCmdUI* pCmdUI);
	afx_msg void OnOutilsEchellex();
	afx_msg void OnUpdateOutilsEchellex(CCmdUI* pCmdUI);
	afx_msg void OnOutilsEchelley();
	afx_msg void OnUpdateOutilsEchelley(CCmdUI* pCmdUI);
	afx_msg void OnOutilsEchelleyenpourcent();
	afx_msg void OnUpdateOutilsEchelleyenpourcent(CCmdUI* pCmdUI);
	afx_msg void OnOutilsTitreaxedesx();
	afx_msg void OnUpdateOutilsTitreaxedesx(CCmdUI* pCmdUI);
	afx_msg void OnOutilsTitreaxedesy();
	afx_msg void OnUpdateOutilsTitreaxedesy(CCmdUI* pCmdUI);
	afx_msg void OnOutilsTitredugraphe();
	afx_msg void OnUpdateOutilsTitredugraphe(CCmdUI* pCmdUI);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnInitMenuPopup(CMenu *pMenuPopup, UINT nIndex, BOOL sysMenu);
	afx_msg void OnOutilsParamtres();
	afx_msg void OnOutilsHistogrammeumulatif();
	afx_msg void OnEditCopy();
	afx_msg void OnOutilsHistogrammedelimage();
	afx_msg void OnUpdateOutilsHistogrammedelimage(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOutilsHistogrammeumulatif(CCmdUI* pCmdUI);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTVIEW_H__07AF57EE_6229_11D4_9E82_0000E8EA8C1A__INCLUDED_)
