// SaturatingLinearExpansion.h: interface for the CSaturatingLinearExpansion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SATURATINGLINEAREXPANSION_H__9A64D373_5BAE_11D4_B2D2_00400550E7C9__INCLUDED_)
#define AFX_SATURATINGLINEAREXPANSION_H__9A64D373_5BAE_11D4_B2D2_00400550E7C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LookUpTables.h"

class CSaturatingLinearExpansion : public CLookUpTables  
{
public:
	CSaturatingLinearExpansion();
	virtual ~CSaturatingLinearExpansion();
	unsigned char GetLookUpTable(int x);
};

#endif // !defined(AFX_SATURATINGLINEAREXPANSION_H__9A64D373_5BAE_11D4_B2D2_00400550E7C9__INCLUDED_)
