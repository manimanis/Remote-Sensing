// LinearExpansion.h: interface for the CLinearExpansion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINEAREXPANSION_H__D7CAB137_57CF_11D4_B2CB_00400550E7C9__INCLUDED_)
#define AFX_LINEAREXPANSION_H__D7CAB137_57CF_11D4_B2CB_00400550E7C9__INCLUDED_

#include "LookUpTables.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLinearExpansion : public CLookUpTables  
{
public:
	unsigned char GetLookUpTable(int x);
	CLinearExpansion();
	virtual ~CLinearExpansion();
	BOOL PreDlgShow(int* inTable);
};

#endif // !defined(AFX_LINEAREXPANSION_H__D7CAB137_57CF_11D4_B2CB_00400550E7C9__INCLUDED_)
