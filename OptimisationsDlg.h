#if !defined(AFX_OptimisationsDlg_H__47C62600_5CF8_11D4_9E82_0000E8EA8C1A__INCLUDED_)
#define AFX_OptimisationsDlg_H__47C62600_5CF8_11D4_9E82_0000E8EA8C1A__INCLUDED_

#include "Hstogramme.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptimisationsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptimisationsDlg dialog

class COptimisationsDlg : public CDialog
{
// Construction
public:
	CPoint pt[3][30];
	char currentTab;
	int LookUpTable[3][256];
	Histogramme hst;
	TCITEM tcItem[3];
	COptimisationsDlg(CWnd* pParent = NULL);   // standard constructor
	virtual void Recalc() = 0;
// Dialog Data
	//{{AFX_DATA(COptimisationsDlg)
	enum { IDD = IDD_OPTIMISATIONS_DLG };
	CTabCtrl	m_propertySheet;
	int		m_xCoords;
	int		m_yCoords;
	int		m_curPoint;
	int		m_maxPoints;
	BOOL	m_rEqualVB;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptimisationsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(COptimisationsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSelchangePropertySheet(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnREqualVB();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg virtual void OnChangeXCoords();
	afx_msg virtual void OnChangeYCoords();
	afx_msg virtual void OnChangeCurrentPoint();
	afx_msg virtual void OnChangeMaxPoints() = 0;
	DECLARE_MESSAGE_MAP()
private:
	CRect itemRect;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OptimisationsDlg_H__47C62600_5CF8_11D4_9E82_0000E8EA8C1A__INCLUDED_)
