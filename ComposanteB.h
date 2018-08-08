// ComposanteB.h: interface for the CComposanteB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPOSANTEB_H__EC805CCA_62C0_11D4_B2DA_00400550E7C9__INCLUDED_)
#define AFX_COMPOSANTEB_H__EC805CCA_62C0_11D4_B2DA_00400550E7C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ComposantesRGB.h"

class CComposanteB : public CComposantesRGB  
{
	DECLARE_DYNCREATE(CComposanteB)
public:
	CComposanteB();
	virtual ~CComposanteB();

	afx_msg void OnDestroy();

	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_COMPOSANTEB_H__EC805CCA_62C0_11D4_B2DA_00400550E7C9__INCLUDED_)
