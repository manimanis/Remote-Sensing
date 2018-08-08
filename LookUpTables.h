// LookUpTables.h: interface for the CLookUpTables class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOOKUPTABLES_H__D7CAB134_57CF_11D4_B2CB_00400550E7C9__INCLUDED_)
#define AFX_LOOKUPTABLES_H__D7CAB134_57CF_11D4_B2CB_00400550E7C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OptimisationsDlg.h"

class CLookUpTables  
{
public:
	virtual BOOL PreDlgShow(int* inTable);
	virtual int DoModal();
	virtual void InitInstance();
	virtual unsigned char * GetTable();
	// Remplir la table de conversion à partir des données présentés dans la table inTable
	virtual BOOL FillLookUpTable(int dCount, int *inTable);
	// Consulter la table LookUpTable
	virtual unsigned char GetLookUpTable(int x) = 0; 
	CLookUpTables();
	virtual ~CLookUpTables();
protected:
	unsigned char *LookUpTable;
	int dataCount;
	int result;
	int rvbLook;
	COptimisationsDlg* linExpDlg;
};

#endif // !defined(AFX_LOOKUPTABLES_H__D7CAB134_57CF_11D4_B2CB_00400550E7C9__INCLUDED_)
