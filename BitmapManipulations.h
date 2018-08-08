// BitmapManipulations.h: interface for the CBitmapManipulations class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BITMAPMANIPULATIONS_H__9DBA0C60_58F3_11D4_9E82_0000E8EA8C1A__INCLUDED_)
#define AFX_BITMAPMANIPULATIONS_H__9DBA0C60_58F3_11D4_9E82_0000E8EA8C1A__INCLUDED_

#include "LookUpTables.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBitmapManipulations  
{
	BOOL IsOpened;
public:
	CBitmap* GetCBitmap();
	BITMAPFILEHEADER* GetBitmapFileHeader();
	BITMAPINFOHEADER* GetBitmapInfoHeader();
	void DrawEx(CDC *pDC, CRect &rect, COLORREF couleur);
	HBITMAP GetBitmapHandle();
	BOOL InitBitmap(CString inFile);
	BOOL GetRGBComponents();
	int *GetPictureHistogrammeInfo();
	int *GetCumulatifHistogrammeInfo();
	BOOL RestoreFromTempCopy(CString iFileName);
	BOOL MakeModification(CLookUpTables* lkUpTable);
	void GetHistogrammeInfo();
	void Draw(CDC *pDC, CRect &rect);
	int GetWidthBytes();
	BOOL CreateTempCopy(CString oFileName);
	BOOL IsCompressed();
	WORD GetBitCount();
	int GetHeight();
	int GetWidth();
	BOOL IsValidBitmap();
	void Close();
	BOOL Open(CString FileName);
	CBitmapManipulations();
	virtual ~CBitmapManipulations();
protected:
	CDC memDC;
	CBitmap bmp;
	int cumData[3][256];
	int picData[3][256];
	CFile FileStream;
	CString iFile;
	BITMAPFILEHEADER bmpFileHeader;
	BITMAPINFOHEADER bmpInfoHeader;
private:
	BOOL firstDrawCall;
	void FillCumulatifInfo();
	void FillPictureInfo(int nbrScanLines, unsigned char* p);
};

#endif // !defined(AFX_BITMAPMANIPULATIONS_H__9DBA0C60_58F3_11D4_9E82_0000E8EA8C1A__INCLUDED_)
