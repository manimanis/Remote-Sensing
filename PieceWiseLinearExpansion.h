// PieceWiseLinearExpansion.h: interface for the CPieceWiseLinearExpansion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PieceWiseLinearEXPANSION_H__9A64D373_5BAE_11D4_B2D2_00400550E7C9__INCLUDED_)
#define AFX_PieceWiseLinearEXPANSION_H__9A64D373_5BAE_11D4_B2D2_00400550E7C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LookUpTables.h"

class CPieceWiseLinearExpansion : public CLookUpTables  
{
public:
	CPieceWiseLinearExpansion();
	virtual ~CPieceWiseLinearExpansion();
	unsigned char GetLookUpTable(int x);
};

#endif // !defined(AFX_PieceWiseLinearEXPANSION_H__9A64D373_5BAE_11D4_B2D2_00400550E7C9__INCLUDED_)
