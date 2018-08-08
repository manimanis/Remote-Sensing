// ComposanteG.h: interface for the CComposanteG class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPOSANTEG_H__EC805CC9_62C0_11D4_B2DA_00400550E7C9__INCLUDED_)
#define AFX_COMPOSANTEG_H__EC805CC9_62C0_11D4_B2DA_00400550E7C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ComposantesRGB.h"

class CComposanteG : public CComposantesRGB  
{
	DECLARE_DYNCREATE(CComposanteG)
public:
	CComposanteG();
	virtual ~CComposanteG();

	afx_msg void OnDestroy();

	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_COMPOSANTEG_H__EC805CC9_62C0_11D4_B2DA_00400550E7C9__INCLUDED_)
