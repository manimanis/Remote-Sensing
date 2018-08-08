#if !defined(AFX_LinearOptimisationDlg_H__E2F54AA6_5B29_11D4_9E82_0000E8EA8C1A__INCLUDED_)
#define AFX_LinearOptimisationDlg_H__E2F54AA6_5B29_11D4_9E82_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LinearOptimisationDlg.h : header file
//

#include "OptimisationsDlg.h"

class CLinearOptimisationDlg : public COptimisationsDlg  
{
public:
	CLinearOptimisationDlg();
	virtual ~CLinearOptimisationDlg();
	void Recalc();
protected:
	void OnChangeMaxPoints();
};


#endif // !defined(AFX_LinearOptimisationDlg_H__E2F54AA6_5B29_11D4_9E82_0000E8EA8C1A__INCLUDED_)
