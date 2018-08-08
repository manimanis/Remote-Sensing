// LogarithmicExpansion.h: interface for the CLogarithmicExpansion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGARITHMICEXPANSION_H__A34B87D4_5C78_11D4_B2D3_00400550E7C9__INCLUDED_)
#define AFX_LOGARITHMICEXPANSION_H__A34B87D4_5C78_11D4_B2D3_00400550E7C9__INCLUDED_

#include "LogarithmicOptimisationsDlg.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LookUpTables.h"

class CLogarithmicExpansion : public CLookUpTables  
{
public:
	CLogarithmicExpansion();
	virtual ~CLogarithmicExpansion();
	unsigned char GetLookUpTable(int x);
};

#endif // !defined(AFX_LOGARITHMICEXPANSION_H__A34B87D4_5C78_11D4_B2D3_00400550E7C9__INCLUDED_)
