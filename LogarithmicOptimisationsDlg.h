#if !defined(AFX_LOGARITHMICOPTIMISATIONSDLG_H__A34B87D3_5C78_11D4_B2D3_00400550E7C9__INCLUDED_)
#define AFX_LOGARITHMICOPTIMISATIONSDLG_H__A34B87D3_5C78_11D4_B2D3_00400550E7C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OptimisationsDlg.h"

class CLogarithmicOptimisationsDlg : public COptimisationsDlg  
{
public:
	CLogarithmicOptimisationsDlg();
	virtual ~CLogarithmicOptimisationsDlg();
protected:
	void Recalc();
	void OnChangeMaxPoints();
};

#endif // !defined(AFX_LOGARITHMICOPTIMISATIONSDLG_H__A34B87D3_5C78_11D4_B2D3_00400550E7C9__INCLUDED_)
