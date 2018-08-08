// RmtSensingView.h : interface of the CRmtSensingView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RMTSENSINGVIEW_H__FAA7769F_4D88_11D4_B2BC_00400550E7C9__INCLUDED_)
#define AFX_RMTSENSINGVIEW_H__FAA7769F_4D88_11D4_B2BC_00400550E7C9__INCLUDED_


#include "BitmapManipulations.h"	// Added by ClassView
#include "PictureHistogrammeFrame.h"	// Added by ClassView
#include "RmtSensingDoc.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRmtSensingView : public CView
{
protected: // create from serialization only
	CRmtSensingView();
	DECLARE_DYNCREATE(CRmtSensingView)

// Attributes
public:
	CRmtSensingDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRmtSensingView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void Expansion(CLookUpTables *lkUpTables);
	virtual ~CRmtSensingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	CPictureHistogrammeFrame *wnd;
	CMDIChildWnd *wndR;
	CMDIChildWnd *wndG;
	CMDIChildWnd *wndB;
	BOOL satLinExpDone;
	BOOL copyMode;
	BOOL linExpDone;
	BOOL bmpAdjustXY;
	BOOL bmpCentered;
	CRect PicRect;
	//{{AFX_MSG(CRmtSensingView)
	afx_msg void OnPictureInfo();
	afx_msg void OnEditCopy();
	afx_msg void OnOutilsExpansionlinaire();
	afx_msg void OnOutilsAjustexy();
	afx_msg void OnUpdateOutilsAjustexy(CCmdUI* pCmdUI);
	afx_msg void OnOutilsCentre();
	afx_msg void OnUpdateOutilsCentre(CCmdUI* pCmdUI);
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateOutilsExpansionlinaire(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditUndo(CCmdUI* pCmdUI);
	afx_msg void OnOutilsExpansionlinaireavecsaturation();
	afx_msg void OnUpdateOutilsExpansionlinaireavecsaturation(CCmdUI* pCmdUI);
	afx_msg void OnOutilsExpansionlogarithmique();
	afx_msg void OnUpdateOutilsExpansionlogarithmique(CCmdUI* pCmdUI);
	afx_msg void OnOutilsExpansionexponentielle();
	afx_msg void OnUpdateOutilsExpansionexponentielle(CCmdUI* pCmdUI);
	afx_msg void OnOutilsExpansionlinairesegmente();
	afx_msg void OnUpdateOutilsExpansionlinairesegmente(CCmdUI* pCmdUI);
	afx_msg void OnOutilsHistogrammedelimage();
	afx_msg void OnUpdateOutilsHistogrammedelimage(CCmdUI* pCmdUI);
	afx_msg void OnOutilsComposantesrgb();
	afx_msg void OnUpdateOutilsComposantesrgb(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RmtSensingView.cpp
inline CRmtSensingDoc* CRmtSensingView::GetDocument()
   { return (CRmtSensingDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RMTSENSINGVIEW_H__FAA7769F_4D88_11D4_B2BC_00400550E7C9__INCLUDED_)
