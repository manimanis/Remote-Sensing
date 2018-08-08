#if !defined(AFX_SaturatingLinearOptimisationDlg_H__E2F54AA6_5B29_11D4_9E82_0000E8EA8C1A__INCLUDED_)
#define AFX_SaturatingLinearOptimisationDlg_H__E2F54AA6_5B29_11D4_9E82_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SaturatingLinearOptimisationDlg.h : header file
//

#include "OptimisationsDlg.h"

class CSaturatingLinearOptimisationDlg : public COptimisationsDlg  
{
public:
	CSaturatingLinearOptimisationDlg();
	virtual ~CSaturatingLinearOptimisationDlg();
protected:
	void Recalc();
	void OnChangeMaxPoints();
};


#endif // !defined(AFX_SaturatingLinearOptimisationDlg_H__E2F54AA6_5B29_11D4_9E82_0000E8EA8C1A__INCLUDED_)
