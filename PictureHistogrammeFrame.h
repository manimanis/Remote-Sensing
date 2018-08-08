#if !defined(AFX_PICTUREHISTOGRAMMEFRAME_H__5258D2AA_4D8C_11D4_B2BC_00400550E7C9__INCLUDED_)
#define AFX_PICTUREHISTOGRAMMEFRAME_H__5258D2AA_4D8C_11D4_B2BC_00400550E7C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PictureHistogrammeFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPictureHistogrammeFrame frame

class CPictureHistogrammeFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CPictureHistogrammeFrame)
protected:

// Attributes
public:

// Operations
public:
	CToolBar m_pictureHistoToolBar;
	CPictureHistogrammeFrame();           // protected constructor used by dynamic creation
	virtual ~CPictureHistogrammeFrame();
	CStatusBar  m_wndStatusBar;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPictureHistogrammeFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL DestroyWindow();
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPictureHistogrammeFrame)
		// NOTE - the ClassWizard will add and remove member functions here.
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICTUREHISTOGRAMMEFRAME_H__5258D2AA_4D8C_11D4_B2BC_00400550E7C9__INCLUDED_)
