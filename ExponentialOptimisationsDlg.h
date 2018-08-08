// ExponentialOptimisationsDlg.h: interface for the CExponentialOptimisationsDlg class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ExponentialOptimisationsDlg_H__F078B146_5E09_11D4_B2D5_00400550E7C9__INCLUDED_)
#define AFX_ExponentialOptimisationsDlg_H__F078B146_5E09_11D4_B2D5_00400550E7C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OptimisationsDlg.h"

class CExponentialOptimisationsDlg : public COptimisationsDlg  
{
public:
	CExponentialOptimisationsDlg();
	virtual ~CExponentialOptimisationsDlg();
protected:
	void Recalc();
	void OnChangeMaxPoints();
};

#endif // !defined(AFX_ExponentialOptimisationsDlg_H__F078B146_5E09_11D4_B2D5_00400550E7C9__INCLUDED_)
