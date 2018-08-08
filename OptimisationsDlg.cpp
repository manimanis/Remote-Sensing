// OptimisationsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RmtSensing.h"
#include "OptimisationsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptimisationsDlg dialog


COptimisationsDlg::COptimisationsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COptimisationsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COptimisationsDlg)
	m_xCoords = 0;
	m_yCoords = 0;
	m_curPoint = 0;
	m_maxPoints = 1;
	m_rEqualVB = FALSE;
	//}}AFX_DATA_INIT
	currentTab = 0;
	for (int j = 0 ; j < 3 ; j++)
		for (int i = 0 ; i < 256 ; i++)
			LookUpTable[j][i] = i;

	for (j = 0 ; j < 3 ; j++)
		for (int i = 0 ; i < 30 ; i++)
			pt[j][i] = CPoint(0, 0);
}


void COptimisationsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptimisationsDlg)
	DDX_Control(pDX, IDC_PROPERTY_SHEET, m_propertySheet);
	DDX_Text(pDX, IDC_X_COORDS, m_xCoords);
	DDX_Text(pDX, IDC_Y_COORDS, m_yCoords);
	DDX_Text(pDX, IDC_CURRENT_POINT, m_curPoint);
	DDV_MinMaxInt(pDX, m_curPoint, 0, 29);
	DDX_Text(pDX, IDC_MAX_POINTS, m_maxPoints);
	DDV_MinMaxInt(pDX, m_maxPoints, 1, 30);
	DDX_Check(pDX, IDC_R_EQUAL_V_B, m_rEqualVB);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptimisationsDlg, CDialog)
	//{{AFX_MSG_MAP(COptimisationsDlg)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_NOTIFY(TCN_SELCHANGE, IDC_PROPERTY_SHEET, OnSelchangePropertySheet)
	ON_BN_CLICKED(IDC_R_EQUAL_V_B, OnREqualVB)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_EN_CHANGE(IDC_X_COORDS, OnChangeXCoords)
	ON_EN_CHANGE(IDC_Y_COORDS, OnChangeYCoords)
	ON_EN_CHANGE(IDC_CURRENT_POINT, OnChangeCurrentPoint)
	ON_EN_CHANGE(IDC_MAX_POINTS, OnChangeMaxPoints)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptimisationsDlg message handlers

BOOL COptimisationsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	tcItem[0].mask = TCIF_TEXT;
	tcItem[0].pszText = "Rouge";
	m_propertySheet.InsertItem(1, tcItem);

	tcItem[1].mask = TCIF_TEXT;
	tcItem[1].pszText = "Vert";
	m_propertySheet.InsertItem(2, (tcItem + 1));

	tcItem[2].mask = TCIF_TEXT;
	tcItem[2].pszText = "Bleu";
	m_propertySheet.InsertItem(3, (tcItem + 2));

	hst.SetXmin(0);
	hst.SetXmax(255);

	hst.SetYmin(255);
	hst.SetYmax(0);

	hst.SetXscl(25);
	hst.SetYscl(25);

	hst.SetXSclFormat("%3.0f");
	hst.SetYSclFormat("%3.0f");

	hst.SetXScaleValueState(TRUE);
	hst.SetYScaleValueState(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COptimisationsDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	SetTimer(120, 5, NULL);
}

BOOL COptimisationsDlg::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	return CDialog::OnNotify(wParam, lParam, pResult);
}

void COptimisationsDlg::OnMouseMove(UINT nFlags, CPoint point) 
{	
	if (GetCapture() == this)
	{
		CClientDC dc(&m_propertySheet);

		dc.SetMapMode(MM_HIMETRIC);

		point.x -= 8;
		point.y -= 8;

		dc.DPtoLP(&point);
		m_propertySheet.GetWindowRect(itemRect);
		ScreenToClient(&itemRect);
		dc.DPtoLP(&itemRect);
	
		if (hst.IsInDrawingRect(point))
		{
			HistoPointData hpData;

			hpData = hst.DPtoLP(point);
			m_xCoords = hpData.x;
			m_yCoords = hpData.y;

			hst.NearPlot(&dc, point, 0);
		}

		UpdateData(FALSE);
	}
}

void COptimisationsDlg::OnTimer(UINT nIDEvent) 
{
	KillTimer(120);

	CClientDC dc(&m_propertySheet);

	dc.SetMapMode(MM_HIMETRIC);
	m_propertySheet.GetClientRect(itemRect);
	dc.DPtoLP(&itemRect);

	itemRect.left += 500;
	itemRect.right -= 500;
	itemRect.top -= 1000;
	itemRect.bottom += 500;

	dc.Rectangle(itemRect);

	hst.SetHistogrammeRect(itemRect);
	hst.SetDrawingRect(&dc);

	hst.InitDrawingRect(&dc);
	hst.PlotEx(&dc, 256, LookUpTable[currentTab], RGB(	(currentTab == 0) ? 255 : 0, 
														(currentTab == 1) ? 255 : 0,
														(currentTab == 2) ? 255 : 0));
	for (int i = 0 ; i < m_maxPoints ; i++)
	{
		HistoPointData hpData;
		CPoint point;

		hpData.x = int(pt[currentTab][i].x);
		hpData.y = int(pt[currentTab][i].y);

		point = hst.LPtoDP(hpData);

		hst.NearPlot(&dc, point, 0);
	}

	CDialog::OnTimer(nIDEvent);
}

void COptimisationsDlg::OnSelchangePropertySheet(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UpdateData();

	if (m_rEqualVB) 
	{
		currentTab = 0;
		m_propertySheet.SetCurSel(currentTab);
	}
	else currentTab = m_propertySheet.GetCurSel();

	m_xCoords = pt[currentTab][m_curPoint].x;
	m_yCoords = pt[currentTab][m_curPoint].y;

	Recalc();
	UpdateData(FALSE);
	Invalidate();
	*pResult = 0;
}

void COptimisationsDlg::OnREqualVB() 
{
	UpdateData();

	if (m_rEqualVB) 
	{
		currentTab = 0;
		m_propertySheet.SetCurSel(currentTab);
	}
	else currentTab = m_propertySheet.GetCurSel();


	UpdateData(FALSE);
	Invalidate();
}

void COptimisationsDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CClientDC dc(&m_propertySheet);
	HistoPointData hpData;
	CPoint pix;
	
	dc.SetMapMode(MM_HIMETRIC);

	point.x -= 8;
	point.y -= 8;

	dc.DPtoLP(&point);	
	
	for (int i = 0 ; i < m_maxPoints ; i++)
	{
		hpData.x = float(pt[currentTab][i].x);
		hpData.y = float(pt[currentTab][i].y);

		pix = hst.LPtoDP(hpData);
	
		if (point.x >= (pix.x - 200) && point.x <= (pix.x + 200) &&
			point.y >= (pix.y - 200) && point.y <= (pix.y + 200))
		{
			m_curPoint = i;
			
			m_xCoords = pt[currentTab][m_curPoint].x;
			m_yCoords = pt[currentTab][m_curPoint].y;

			SetCapture();
			UpdateData(FALSE);
		}
	}
}

void COptimisationsDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if (GetCapture() == this) 
	{
		ReleaseCapture();

		pt[currentTab][m_curPoint] = CPoint(m_xCoords, m_yCoords);

		sort(m_maxPoints, pt[currentTab], TRUE);

		m_xCoords = pt[currentTab][m_curPoint].x;
		m_yCoords = pt[currentTab][m_curPoint].y;

		Recalc();
		Invalidate();
	}
}

void COptimisationsDlg::OnChangeXCoords() 
{
	UpdateData();

	pt[currentTab][m_curPoint] = CPoint(m_xCoords, m_yCoords);
	
	UpdateData(FALSE);

	Recalc();
	Invalidate();
}

void COptimisationsDlg::OnChangeYCoords() 
{
	UpdateData();

	pt[currentTab][m_curPoint] = CPoint(m_xCoords, m_yCoords);
	
	UpdateData(FALSE);
	Recalc();
	Invalidate();
	
}

void COptimisationsDlg::OnChangeCurrentPoint() 
{
	UpdateData();
	
	if (m_curPoint >= m_maxPoints) m_curPoint = m_maxPoints - 1;
	
	m_xCoords = pt[currentTab][m_curPoint].x;
	m_yCoords = pt[currentTab][m_curPoint].y;

	UpdateData(FALSE);
}

