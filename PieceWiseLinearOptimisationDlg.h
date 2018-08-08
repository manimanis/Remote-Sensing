#if !defined(AFX_PieceWiseLinearOptimisationDlg_H__E2F54AA6_5B29_11D4_9E82_0000E8EA8C1A__INCLUDED_)
#define AFX_PieceWiseLinearOptimisationDlg_H__E2F54AA6_5B29_11D4_9E82_0000E8EA8C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PieceWiseLinearOptimisationDlg.h : header file
//

#include "OptimisationsDlg.h"

class CPieceWiseLinearOptimisationDlg : public COptimisationsDlg  
{
public:
	CPieceWiseLinearOptimisationDlg();
	virtual ~CPieceWiseLinearOptimisationDlg();
protected:
	void Recalc();
	void OnChangeMaxPoints();
};


#endif // !defined(AFX_PieceWiseLinearOptimisationDlg_H__E2F54AA6_5B29_11D4_9E82_0000E8EA8C1A__INCLUDED_)
