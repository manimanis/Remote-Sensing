#if !defined(AFX_PICTUREHISTOGRAMMESETTINGSDLG_H__5258D2A7_4D8C_11D4_B2BC_00400550E7C9__INCLUDED_)
#define AFX_PICTUREHISTOGRAMMESETTINGSDLG_H__5258D2A7_4D8C_11D4_B2BC_00400550E7C9__INCLUDED_

// #include "PictureHistogrammeView.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PictureHistogrammeSettingsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPictureHistogrammeSettingsDlg dialog

class CPictureHistogrammeSettingsDlg : public CDialog
{
// Construction
public:
	CPictureHistogrammeSettingsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPictureHistogrammeSettingsDlg)
	enum { IDD = IDD_PICTUREHISTOGRAME_DLG };
	CEdit	m_maxX_pixels;
	CEdit	m_maxX_percent;
	CEdit	m_maxX_divN;
	CEdit	m_maxY_pixels;
	CEdit	m_maxY_percent;
	CEdit	m_maxY_divN;
	double	m_maxX_pixels_value;
	double	m_maxX_percent_value;
	double	m_maxX_divN_value;
	double	m_maxY_pixels_value;
	double	m_maxY_percent_value;
	double	m_maxY_divN_value;
	CEdit	m_XTitle;
	CEdit	m_YTitle;
	CEdit	m_GraphTitle;
	CEdit	m_YMaxPercent;
	CEdit	m_YMaxPixels;
	CString	m_XTitleText;
	CString	m_YTitleText;
	CString	m_GraphTitleText;
	BOOL	m_ComposanteBleu;
	BOOL	m_ComposanteVerte;
	BOOL	m_ComposanteRouge;
	BOOL	m_GraphTitleEnabled;
	BOOL	m_XTitleEnabled;
	BOOL	m_YTitleEnabled;
	BOOL	m_QuadrillageX;
	BOOL	m_QuadrillageY;
	BOOL	m_XsclEnabled;
	BOOL	m_YsclEnabled;
	BOOL	m_YPercentage;
	int		m_GraphType;
	int		m_YMaxType;
	double	m_YMaxPercentDbl;
	double	m_YMaxPixelsDbl;
	int		m_radio_maxX;
	int		m_radio_maxY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPictureHistogrammeSettingsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// CPictureHistogrammeView *pWnd;

	// Generated message map functions
	//{{AFX_MSG(CPictureHistogrammeSettingsDlg)
	afx_msg void OnPichistSettingsRed();
	afx_msg void OnPichistSettingsBlue();
	afx_msg void OnPichistSettingsGreen();
	afx_msg void OnPichistSettingsGraphTtlState();
	afx_msg void OnPichistSettingsGraphXttlState();
	afx_msg void OnPichistSettingsGraphYttlState();
	afx_msg void OnPichistSettingsMaxyUserPercentRadio();
	afx_msg void OnPichistSettingsMaxyUserPixelRadio();
	afx_msg void OnPichistSettingsMaxyRgb();
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioMaxyDivn();
	afx_msg void OnRadioMaxyPercentUser();
	afx_msg void OnRadioMaxyPixelsUser();
	afx_msg void OnRadioMaxxDivn();
	afx_msg void OnRadioMaxxPercentUser();
	afx_msg void OnRadioMaxxPixelsUser();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetMaxYtype();
	void SetMaxY_EditBox_State();
	void SetMaxX_EditBox_State();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICTUREHISTOGRAMMESETTINGSDLG_H__5258D2A7_4D8C_11D4_B2BC_00400550E7C9__INCLUDED_)
