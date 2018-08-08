// ExponentialExpansion.h: interface for the CExponentialExpansion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPONENTIALEXPANSION_H__C51EBAC1_5CD2_11D4_9E82_0000E8EA8C1A__INCLUDED_)
#define AFX_EXPONENTIALEXPANSION_H__C51EBAC1_5CD2_11D4_9E82_0000E8EA8C1A__INCLUDED_

#include "ExponentialOptimisationsDlg.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LookUpTables.h"

class CExponentialExpansion : public CLookUpTables  
{
public:
	CExponentialExpansion();
	virtual ~CExponentialExpansion();
	unsigned char GetLookUpTable(int x);
};

#endif // !defined(AFX_EXPONENTIALEXPANSION_H__C51EBAC1_5CD2_11D4_9E82_0000E8EA8C1A__INCLUDED_)
