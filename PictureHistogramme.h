// PictureHistogramme.h: interface for the CPictureHistogramme class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PICTUREHISTOGRAMME_H__5258D2A5_4D8C_11D4_B2BC_00400550E7C9__INCLUDED_)
#define AFX_PICTUREHISTOGRAMME_H__5258D2A5_4D8C_11D4_B2BC_00400550E7C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Operations.h"

class CPictureHistogramme : public COperations  
{
public:
	CRect GetBmpRect();
	char GetBitsPixels();
	CString GetOutputFileName();
	void SetOutputFileName(CString filename);
	CString GetInputFileName();
	void SetInputFileName(CString filename);
	void DoOperation();
	CPictureHistogramme();
	virtual ~CPictureHistogramme();

private:
	void GetDataFromBitmap(BITMAP *bm);

protected:
	BOOL operationDone;
	CString oFileName;
	CString iFileName;
	char BitsPixel;
	CRect BmpRect;
};

#endif // !defined(AFX_PICTUREHISTOGRAMME_H__5258D2A5_4D8C_11D4_B2BC_00400550E7C9__INCLUDED_)
