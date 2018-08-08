// ComposantesRGB.cpp: implementation of the CComposantesRGB class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "RmtSensingDoc.h"
#include "ComposantesRGB.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(CComposantesRGB, CRmtSensingView)

BEGIN_MESSAGE_MAP(CComposantesRGB, CRmtSensingView)
	//{{AFX_MSG_MAP(CComposantesRGB)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CComposantesRGB::CComposantesRGB()
{
	bmpAdjustXY = TRUE;
	bmpCentered = FALSE;
	AndColor = 0xffffff;
}

CComposantesRGB::~CComposantesRGB()
{

}

void CComposantesRGB::OnDraw(CDC *pDC)
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

	if (copyMode)	pDoc->bmpManip.DrawEx(pDC, CRect(0, 0, 
		pDoc->bmpManip.GetWidth(), pDoc->bmpManip.GetHeight()), AndColor);
			else pDoc->bmpManip.DrawEx(pDC, PicRect, AndColor);

	pDC->SelectObject(oldBrush);
	pDC->SelectObject(oldPen);

	brush.DeleteObject();
	pen.DeleteObject();
}
