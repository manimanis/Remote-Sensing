// PictureHistogramme.cpp: implementation of the CPictureHistogramme class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "PictureHistogramme.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPictureHistogramme::CPictureHistogramme()
{
	iFileName = "";
	oFileName = "";
	operationDone = FALSE;
}

CPictureHistogramme::~CPictureHistogramme()
{

}

void CPictureHistogramme::DoOperation()
{
	if (iFileName.IsEmpty()){ AfxMessageBox("Vous devez spécifier un nom de fichier avant"
										" de pouvoir appeler DoOperation()"); return; }
	
	if (oFileName.IsEmpty()) oFileName = iFileName + ".phst"; // phst = Picture Histogramme

	// Essaie d'ouvrir le fichier bitmap
	HBITMAP hBmp = (HBITMAP)LoadImage(NULL, iFileName, IMAGE_BITMAP, 0, 0, 
												LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	// Si l'ouverture a échoué ????
	if (!hBmp) { AfxMessageBox("Impossible d'ouvrir " + iFileName + "."); return; }

	CBitmap Bmp; Bmp.Attach(hBmp);
	BITMAP bm; Bmp.GetBitmap(&bm);

	BitsPixel = (char)bm.bmBitsPixel;
	BmpRect = CRect(0, 0, bm.bmWidth, bm.bmHeight);

	operationDone = TRUE;

	GetDataFromBitmap(&bm);
}

void CPictureHistogramme::GetDataFromBitmap(BITMAP *bm)
{
	CFile oFile;
	unsigned char *p, *p2, *pBmpData = p = p2 = (unsigned char *)bm->bmBits;
	int histoData[3][256];
	int bYmax, gYmax, rYmax, nbrPix;

	nbrPix = bYmax = gYmax = rYmax = 0;
	
	memset(histoData, 0, sizeof(histoData)); // On initialise à 0 le contenu de histoData

	for (int i = 0 ; i < bm->bmHeight ; i++)
	{
		for (int j = 0 ; j < bm->bmWidth ; j++)
		{
			if ((++histoData[0][*(p + 0)]) > bYmax) bYmax = histoData[0][*(p + 0)];	// BLUE
			if ((++histoData[1][*(p + 1)]) > gYmax) gYmax = histoData[1][*(p + 1)];	// GREEN
			if ((++histoData[2][*(p + 2)]) > rYmax) rYmax = histoData[2][*(p + 2)];	// RED
			
			p += 3;
		}
		p = p2;
		p = p2 = p + bm->bmWidthBytes;
	}
	
	nbrPix = bm->bmWidth * bm->bmHeight;

	oFile.Open(oFileName, CFile::modeCreate | CFile::modeWrite);
	
	oFile.Write(histoData, sizeof(histoData));

	oFile.Write(&bYmax, sizeof(bYmax));
	oFile.Write(&gYmax, sizeof(gYmax));
	oFile.Write(&rYmax, sizeof(rYmax));

	oFile.Write(&nbrPix, sizeof(nbrPix));

	oFile.Close();
}

void CPictureHistogramme::SetInputFileName(CString filename)
{
	iFileName = filename;
}

CString CPictureHistogramme::GetInputFileName()
{
	return iFileName;
}

void CPictureHistogramme::SetOutputFileName(CString filename)
{
	oFileName = filename;
}

CString CPictureHistogramme::GetOutputFileName()
{
	return oFileName;
}

char CPictureHistogramme::GetBitsPixels()
{
	if (operationDone) return BitsPixel; 
		else 
		{ 
			AfxMessageBox("Aucune information à retourner aucun fichier traité");
			return 0;
		}
}

CRect CPictureHistogramme::GetBmpRect()
{
	if (operationDone) return BmpRect;	
		else 
		{ 
			AfxMessageBox("Aucune information à retourner aucun fichier traité");
			return CRect(0, 0, 0, 0);
		}
}
