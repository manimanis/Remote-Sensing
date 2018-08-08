// ComposanteR.h: interface for the CComposanteR class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPOSANTER_H__EC805CC8_62C0_11D4_B2DA_00400550E7C9__INCLUDED_)
#define AFX_COMPOSANTER_H__EC805CC8_62C0_11D4_B2DA_00400550E7C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ComposantesRGB.h"

class CComposanteR : public CComposantesRGB  
{
	DECLARE_DYNCREATE(CComposanteR)
public:
	CComposanteR();
	virtual ~CComposanteR();

	afx_msg void OnDestroy();

	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_COMPOSANTER_H__EC805CC8_62C0_11D4_B2DA_00400550E7C9__INCLUDED_)
