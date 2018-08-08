// ComposantesRGB.h: interface for the CComposantesRGB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPOSANTESRGB_H__EC805CC6_62C0_11D4_B2DA_00400550E7C9__INCLUDED_)
#define AFX_COMPOSANTESRGB_H__EC805CC6_62C0_11D4_B2DA_00400550E7C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RmtSensingView.h"

class CComposantesRGB : public CRmtSensingView  
{
public:
	CComposantesRGB();
	virtual ~CComposantesRGB();
protected:
	DECLARE_DYNCREATE(CComposantesRGB)
protected:
	int AndColor;
	void OnDraw(CDC *pDC);
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_COMPOSANTESRGB_H__EC805CC6_62C0_11D4_B2DA_00400550E7C9__INCLUDED_)
