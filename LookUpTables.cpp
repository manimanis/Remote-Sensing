// LookUpTables.cpp: implementation of the CLookUpTables class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "LookUpTables.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLookUpTables::CLookUpTables()
{

}

CLookUpTables::~CLookUpTables()
{
	if (LookUpTable) delete [] LookUpTable;	
}

unsigned char *CLookUpTables::GetTable()
{
	return LookUpTable;
}

void CLookUpTables::InitInstance()
{
	dataCount = 256;
	LookUpTable = new unsigned char [dataCount];
	rvbLook = 2;
}

BOOL CLookUpTables::FillLookUpTable(int dCount, int *inTable)
{
	if (result != IDOK) return FALSE;

	for (int i = 0 ; i < dCount ; i++)
			LookUpTable[i] = linExpDlg->LookUpTable[rvbLook][i];
	
	if (!linExpDlg->m_rEqualVB)
	{
		switch (rvbLook) 
		{
		case 0 : rvbLook = 2; break;
		case 1 : rvbLook = 0; break;
		case 2 : rvbLook = 1; break;
		}
	} else rvbLook = 0;

	return TRUE;
}

int CLookUpTables::DoModal()
{
	result = linExpDlg->DoModal();
	rvbLook = (linExpDlg->m_rEqualVB) ? 0 : 2;

	return result;
}

BOOL CLookUpTables::PreDlgShow(int* inTable)
{
	return TRUE;
}