// PictureHistogrammeSettingsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "PictureHistogrammeSettingsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPictureHistogrammeSettingsDlg dialog


CPictureHistogrammeSettingsDlg::CPictureHistogrammeSettingsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPictureHistogrammeSettingsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPictureHistogrammeSettingsDlg)
	m_XTitleText = _T("");
	m_YTitleText = _T("");
	m_GraphTitleText = _T("");
	m_ComposanteBleu = FALSE;
	m_ComposanteVerte = FALSE;
	m_ComposanteRouge = FALSE;
	m_GraphTitleEnabled = FALSE;
	m_XTitleEnabled = FALSE;
	m_YTitleEnabled = FALSE;
	m_QuadrillageX = FALSE;
	m_QuadrillageY = FALSE;
	m_XsclEnabled = FALSE;
	m_YsclEnabled = FALSE;
	m_YPercentage = FALSE;
	m_GraphType = -1;
	m_YMaxType = -1;
	m_YMaxPercentDbl = 0.0;
	m_YMaxPixelsDbl = 0.0;
	m_radio_maxX = -1;
	m_radio_maxY = -1;
	//}}AFX_DATA_INIT
}


void CPictureHistogrammeSettingsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPictureHistogrammeSettingsDlg)
	DDX_Control(pDX, IDC_MAXX_PIXELS_USER, m_maxX_pixels);
	DDX_Control(pDX, IDC_MAXX_PERCENT_USER, m_maxX_percent);
	DDX_Control(pDX, IDC_MAXX_DIV_N, m_maxX_divN);
	DDX_Control(pDX, IDC_MAXY_PIXELS_USER, m_maxY_pixels);
	DDX_Control(pDX, IDC_MAXY_PERCENT_USER, m_maxY_percent);
	DDX_Control(pDX, IDC_MAXY_DIV_N, m_maxY_divN);
	DDX_Text(pDX, IDC_MAXX_PIXELS_USER, m_maxX_pixels_value);
	DDX_Text(pDX, IDC_MAXX_PERCENT_USER, m_maxX_percent_value);
	DDV_MinMaxDouble(pDX, m_maxX_percent_value, 0., 100.);
	DDX_Text(pDX, IDC_MAXX_DIV_N, m_maxX_divN_value);
	DDV_MinMaxDouble(pDX, m_maxX_divN_value, 1., 50.);
	DDX_Text(pDX, IDC_MAXY_PIXELS_USER, m_maxY_pixels_value);
	DDX_Text(pDX, IDC_MAXY_PERCENT_USER, m_maxY_percent_value);
	DDV_MinMaxDouble(pDX, m_maxY_percent_value, 0., 100.);
	DDX_Text(pDX, IDC_MAXY_DIV_N, m_maxY_divN_value);
	DDV_MinMaxDouble(pDX, m_maxY_divN_value, 1., 50.);
	DDX_Control(pDX, ID_PICHIST_SETTINGS_GRAPH_XTTL, m_XTitle);
	DDX_Control(pDX, ID_PICHIST_SETTINGS_GRAPH_YTTL, m_YTitle);
	DDX_Control(pDX, ID_PICHIST_SETTINGS_GRAPH_TTL, m_GraphTitle);
	DDX_Control(pDX, ID_PICHIST_SETTINGS_MAXY_USER_PERCENT, m_YMaxPercent);
	DDX_Control(pDX, ID_PICHIST_SETTINGS_MAXY_USER_PIXELS, m_YMaxPixels);
	DDX_Text(pDX, ID_PICHIST_SETTINGS_GRAPH_XTTL, m_XTitleText);
	DDX_Text(pDX, ID_PICHIST_SETTINGS_GRAPH_YTTL, m_YTitleText);
	DDX_Text(pDX, ID_PICHIST_SETTINGS_GRAPH_TTL, m_GraphTitleText);
	DDX_Check(pDX, ID_PICHIST_SETTINGS_BLUE, m_ComposanteBleu);
	DDX_Check(pDX, ID_PICHIST_SETTINGS_GREEN, m_ComposanteVerte);
	DDX_Check(pDX, ID_PICHIST_SETTINGS_RED, m_ComposanteRouge);
	DDX_Check(pDX, ID_PICHIST_SETTINGS_GRAPH_TTL_STATE, m_GraphTitleEnabled);
	DDX_Check(pDX, ID_PICHIST_SETTINGS_GRAPH_XTTL_STATE, m_XTitleEnabled);
	DDX_Check(pDX, ID_PICHIST_SETTINGS_GRAPH_YTTL_STATE, m_YTitleEnabled);
	DDX_Check(pDX, ID_PICHIST_SETTINGS_XQUADRILLAGE, m_QuadrillageX);
	DDX_Check(pDX, ID_PICHIST_SETTINGS_YQUADRILLAGE, m_QuadrillageY);
	DDX_Check(pDX, ID_PICHIST_SETTINGS_SCLX, m_XsclEnabled);
	DDX_Check(pDX, ID_PICHIST_SETTINGS_SCLY, m_YsclEnabled);
	DDX_Check(pDX, ID_PICHIST_SETTINGS_PERCENTAGE_SCLY, m_YPercentage);
	DDX_Radio(pDX, ID_PICHIST_SETTINGS_GRAPH_TYPE_COURBE, m_GraphType);
	DDX_Radio(pDX, ID_PICHIST_SETTINGS_MAXY_RGB, m_YMaxType);
	DDX_Text(pDX, ID_PICHIST_SETTINGS_MAXY_USER_PERCENT, m_YMaxPercentDbl);
	DDV_MinMaxDouble(pDX, m_YMaxPercentDbl, 0., 100.);
	DDX_Text(pDX, ID_PICHIST_SETTINGS_MAXY_USER_PIXELS, m_YMaxPixelsDbl);
	DDX_Radio(pDX, IDC_RADIO_MAXX_DIVN, m_radio_maxX);
	DDX_Radio(pDX, IDC_RADIO_MAXY_DIVN, m_radio_maxY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPictureHistogrammeSettingsDlg, CDialog)
	//{{AFX_MSG_MAP(CPictureHistogrammeSettingsDlg)
	ON_BN_CLICKED(ID_PICHIST_SETTINGS_RED, OnPichistSettingsRed)
	ON_BN_CLICKED(ID_PICHIST_SETTINGS_BLUE, OnPichistSettingsBlue)
	ON_BN_CLICKED(ID_PICHIST_SETTINGS_GREEN, OnPichistSettingsGreen)
	ON_BN_CLICKED(ID_PICHIST_SETTINGS_GRAPH_TTL_STATE, OnPichistSettingsGraphTtlState)
	ON_BN_CLICKED(ID_PICHIST_SETTINGS_GRAPH_XTTL_STATE, OnPichistSettingsGraphXttlState)
	ON_BN_CLICKED(ID_PICHIST_SETTINGS_GRAPH_YTTL_STATE, OnPichistSettingsGraphYttlState)
	ON_BN_CLICKED(ID_PICHIST_SETTINGS_MAXY_USER_PERCENT_RADIO, OnPichistSettingsMaxyUserPercentRadio)
	ON_BN_CLICKED(ID_PICHIST_SETTINGS_MAXY_USER_PIXEL_RADIO, OnPichistSettingsMaxyUserPixelRadio)
	ON_BN_CLICKED(ID_PICHIST_SETTINGS_MAXY_RGB, OnPichistSettingsMaxyRgb)
	ON_BN_CLICKED(IDC_RADIO_MAXY_DIVN, OnRadioMaxyDivn)
	ON_BN_CLICKED(IDC_RADIO_MAXY_PERCENT_USER, OnRadioMaxyPercentUser)
	ON_BN_CLICKED(IDC_RADIO_MAXY_PIXELS_USER, OnRadioMaxyPixelsUser)
	ON_BN_CLICKED(IDC_RADIO_MAXX_DIVN, OnRadioMaxxDivn)
	ON_BN_CLICKED(IDC_RADIO_MAXX_PERCENT_USER, OnRadioMaxxPercentUser)
	ON_BN_CLICKED(IDC_RADIO_MAXX_PIXELS_USER, OnRadioMaxxPixelsUser)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPictureHistogrammeSettingsDlg message handlers

void CPictureHistogrammeSettingsDlg::OnPichistSettingsRed() 
{
	
}

void CPictureHistogrammeSettingsDlg::OnPichistSettingsBlue() 
{
	
}

void CPictureHistogrammeSettingsDlg::OnPichistSettingsGreen() 
{
	
}

void CPictureHistogrammeSettingsDlg::OnPichistSettingsGraphTtlState() 
{
	UpdateData();
	m_GraphTitle.SetReadOnly(!m_GraphTitleEnabled);
	UpdateData(FALSE);
}

void CPictureHistogrammeSettingsDlg::OnPichistSettingsGraphXttlState() 
{
	UpdateData();
	m_XTitle.SetReadOnly(!m_XTitleEnabled);
	UpdateData(FALSE);
}

void CPictureHistogrammeSettingsDlg::OnPichistSettingsGraphYttlState() 
{
	UpdateData();
	m_YTitle.SetReadOnly(!m_YTitleEnabled);
	UpdateData(FALSE);
}

void CPictureHistogrammeSettingsDlg::OnPichistSettingsMaxyUserPercentRadio() 
{
	SetMaxYtype();
}

void CPictureHistogrammeSettingsDlg::OnPichistSettingsMaxyUserPixelRadio() 
{
	SetMaxYtype();
}

void CPictureHistogrammeSettingsDlg::OnPichistSettingsMaxyRgb() 
{
	SetMaxYtype();			
}

BOOL CPictureHistogrammeSettingsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	UpdateData();

	m_GraphTitle.SetReadOnly(!m_GraphTitleEnabled);
	m_XTitle.SetReadOnly(!m_XTitleEnabled);
	m_YTitle.SetReadOnly(!m_YTitleEnabled);

	m_maxY_divN.SetReadOnly(!(m_radio_maxY == 0));
	m_maxY_percent.SetReadOnly(!(m_radio_maxY == 1));
	m_maxY_pixels.SetReadOnly(!(m_radio_maxY == 2));

	m_maxX_divN.SetReadOnly(!(m_radio_maxX == 0));
	m_maxX_percent.SetReadOnly(!(m_radio_maxX == 1));
	m_maxX_pixels.SetReadOnly(!(m_radio_maxX == 2));

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPictureHistogrammeSettingsDlg::OnRadioMaxyDivn() 
{
	SetMaxY_EditBox_State();
}

void CPictureHistogrammeSettingsDlg::OnRadioMaxyPercentUser() 
{
	SetMaxY_EditBox_State();
}

void CPictureHistogrammeSettingsDlg::OnRadioMaxyPixelsUser() 
{
	SetMaxY_EditBox_State();	
}

void CPictureHistogrammeSettingsDlg::OnRadioMaxxDivn() 
{
	SetMaxX_EditBox_State();	
}

void CPictureHistogrammeSettingsDlg::OnRadioMaxxPercentUser() 
{
	SetMaxX_EditBox_State();
}

void CPictureHistogrammeSettingsDlg::OnRadioMaxxPixelsUser() 
{
	SetMaxX_EditBox_State();	
}

void CPictureHistogrammeSettingsDlg::SetMaxX_EditBox_State()
{
	UpdateData();
	m_maxX_divN.SetReadOnly(!(m_radio_maxX == 0));
	m_maxX_percent.SetReadOnly(!(m_radio_maxX == 1));
	m_maxX_pixels.SetReadOnly(!(m_radio_maxX == 2));
	UpdateData(FALSE);
}

void CPictureHistogrammeSettingsDlg::SetMaxY_EditBox_State()
{
	UpdateData();
	m_maxY_divN.SetReadOnly(!(m_radio_maxY == 0));
	m_maxY_percent.SetReadOnly(!(m_radio_maxY == 1));
	m_maxY_pixels.SetReadOnly(!(m_radio_maxY == 2));
	UpdateData(FALSE);
}

void CPictureHistogrammeSettingsDlg::SetMaxYtype()
{
	UpdateData();
	m_YMaxPercent.SetReadOnly(!(m_YMaxType == 1));
	m_YMaxPixels.SetReadOnly(!(m_YMaxType == 2));
	UpdateData(FALSE);
}
