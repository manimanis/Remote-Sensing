// BitmapManipulations.cpp: implementation of the CBitmapManipulations class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RmtSensing.h"
#include "BitmapManipulations.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBitmapManipulations::CBitmapManipulations()
{
	iFile = "";
	IsOpened = FALSE;
	firstDrawCall = TRUE;

	memset(picData, 0, sizeof(picData));
}

CBitmapManipulations::~CBitmapManipulations()
{
	memDC.DeleteDC();

	bmp.Detach();
	bmp.DeleteObject();
}

BOOL CBitmapManipulations::Open(CString FileName)
{
	iFile = FileName;
		
	IsOpened = FileStream.Open(iFile, CFile::modeReadWrite);

	if (IsOpened)
	{
		FileStream.Seek(0, CFile::begin);
		FileStream.Read(&bmpFileHeader, sizeof(bmpFileHeader));
		FileStream.Read(&bmpInfoHeader, sizeof(bmpInfoHeader));
	}

	return IsOpened;
}

void CBitmapManipulations::Close()
{
	FileStream.Close();
	IsOpened = FALSE;
}

BOOL CBitmapManipulations::IsValidBitmap()
{
	// Si l'entête de fichier est != de "BM" alors le bitmap n'est pas valide
	if (bmpFileHeader.bfType != 19778 /* = "BM" */) return FALSE;
	
	// Vérfie la taille de l'entête d'info
	if (bmpInfoHeader.biSize != 40) return FALSE;

	return TRUE;
}

int CBitmapManipulations::GetWidth()
{
	return bmpInfoHeader.biWidth;
}

int CBitmapManipulations::GetHeight()
{
	return bmpInfoHeader.biHeight;
}

WORD CBitmapManipulations::GetBitCount()
{
	return bmpInfoHeader.biBitCount;
}

BOOL CBitmapManipulations::IsCompressed()
{
	return (bmpInfoHeader.biCompression == BI_RGB);
}

// Crée une copie temporaire du fichier, ferme le fichier courant et ouvre le nouveau
BOOL CBitmapManipulations::CreateTempCopy(CString oFileName)
{
	CFile oFile;
	
	unsigned char *mem = new unsigned char [8192];
	if (!mem)
	{
		AfxMessageBox("Erreur : ne peut pas allouer de la mémoire dans\n"
						"BOOL CBitmapManipulations::CreateTempCopy()");
		return FALSE;
	}

	int FileLength = FileStream.GetLength(),
		Portions = FileLength / 8192,
		Reste = FileLength % 8192;

	FileStream.Close();
	FileStream.Open(iFile, CFile::modeRead);

	FileStream.Seek(0, CFile::begin);
	oFile.Open(oFileName, CFile::modeCreate | CFile :: modeWrite);
	
	for (int i = 0 ; i < Portions ; i++)
	{
		FileStream.Read(mem, 8192);
		oFile.Write(mem, 8192); 
	}

	if (Reste)
	{
		FileStream.Read(mem, Reste);
		oFile.Write(mem, Reste);
	}

	FileStream.Close();
	oFile.Close();

	FileStream.Open(iFile, CFile::modeReadWrite);

	delete [] mem;

	return TRUE;
}

int CBitmapManipulations::GetWidthBytes()
{
	int BmpWidth = bmpInfoHeader.biWidth * bmpInfoHeader.biBitCount; 

	return (((BmpWidth >> 5) + ((BmpWidth % 32) > 0)) << 2);
}

void CBitmapManipulations::Draw(CDC *pDC, CRect &rect)
{	
	if (firstDrawCall) 
	{
		firstDrawCall = FALSE;
		memDC.CreateCompatibleDC(pDC);	
	}
	
	memDC.SelectObject(&bmp);

	pDC->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, 0, 0, 
				bmpInfoHeader.biWidth, bmpInfoHeader.biHeight, SRCCOPY);
}


// !!!!!!!!!!!! Uniquement 24 bits !!!!!!!!!!!!!!!
void CBitmapManipulations::GetHistogrammeInfo()
{
	memset(picData, 0, sizeof(picData));


	if (bmpInfoHeader.biBitCount < 24)
	{
		AfxMessageBox("Le format de l'image n'est pas encore pris en charge par l'application");
		return;
	}

	BITMAP bm; bmp.GetBitmap(&bm);

	FillPictureInfo(bmpInfoHeader.biHeight, (unsigned char *)bm.bmBits);
	FillCumulatifInfo();
}

void CBitmapManipulations::FillPictureInfo(int nbrScanLines, unsigned char *p)
{
	unsigned char *p1 = p;
	int WidthBytes = GetWidthBytes(), i, j;

	for (j = 0 ; j < nbrScanLines ; j++)
	{
		for (i = 0 ; i < bmpInfoHeader.biWidth ; i++)
		{
			picData[0][*(p + 0)]++; // Blue
			picData[1][*(p + 1)]++; // Green
			picData[2][*(p + 2)]++; // Red

			p += 3;
		}
		p = p1 + WidthBytes;
		p1 = p;
	}	
}

void CBitmapManipulations::FillCumulatifInfo()
{
	memcpy(cumData, picData, sizeof(picData));

	for (int j = 0 ; j < 3 ; j++)
		for (int i = 1 ; i < 256 ; i++)
			cumData[j][i] += cumData[j][i - 1];
}

BOOL CBitmapManipulations::MakeModification(CLookUpTables *lkUpTable)
{
	unsigned char rvblkUpTable[3][256];

	// On initialise la première instance de CLookUpTable
	lkUpTable->InitInstance();

	// On effectue une petite initialisations avant l'affichage
	lkUpTable->PreDlgShow((int *)picData);

	if (lkUpTable->DoModal() == IDCANCEL) return FALSE;

	// On traite les bleus
	lkUpTable->FillLookUpTable(256, picData[0]);
	memcpy(rvblkUpTable[0], lkUpTable->GetTable(), 256);
			

	// On traite les Verts
	lkUpTable->FillLookUpTable(256, picData[1]);
	memcpy(rvblkUpTable[1], lkUpTable->GetTable(), 256);

	// On traite les rouges
	lkUpTable->FillLookUpTable(256, picData[2]);
	memcpy(rvblkUpTable[2], lkUpTable->GetTable(), 256);
	
	if (bmpInfoHeader.biBitCount < 24)
	{
		AfxMessageBox("Le format de l'image n'est pas encore pris en charge par l'application");
		return FALSE;
	}

	BITMAP bm; bmp.GetBitmap(&bm);
	int widthBytes = GetWidthBytes();
	unsigned char *mem1, *mem = mem1 = (unsigned char *)bm.bmBits;

	for (int j = 0 ; j < bmpInfoHeader.biHeight ; j++)
	{
		mem = mem1;
		for (int i = 0 ; i < bmpInfoHeader.biWidth ; i++)
		{
			*(mem + 0) = rvblkUpTable[0][*(mem + 0)];		
			*(mem + 1) = rvblkUpTable[1][*(mem + 1)];
			*(mem + 2) = rvblkUpTable[2][*(mem + 2)];

			mem += 3;
		}
		mem1 += widthBytes;
	}
	
	return TRUE;
}

BOOL CBitmapManipulations::RestoreFromTempCopy(CString iFileName)
{
	bmp.Detach();

	// Essaie d'ouvrir le fichier bitmap
	HBITMAP hBmp = (HBITMAP)LoadImage(NULL, iFileName, IMAGE_BITMAP, 0, 0, 
											LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	// Si l'ouverture a échoué ????
	if (!hBmp) 
	{ 
		AfxMessageBox("Impossible d'ouvrir " + iFileName + ".");
		return FALSE;
	}

	bmp.Attach(hBmp);

	return TRUE;
}

int *CBitmapManipulations::GetPictureHistogrammeInfo()
{
	return (int *)picData;
}

int *CBitmapManipulations::GetCumulatifHistogrammeInfo()
{
	return (int *)cumData;
}

BOOL CBitmapManipulations::GetRGBComponents()
{
	if (!IsOpened) return FALSE;
	if (bmpInfoHeader.biBitCount < 24)
	{
		AfxMessageBox("Le format de l'image n'est pas encore pris en charge par l'application");
		return FALSE;
	}
/*
	unsigned char *mem =  new unsigned char [GetWidthBytes() * 10];
	if (!mem)
	{
		AfxMessageBox("Erreur : ne peut pas allouer de la mémoire dans\n"
						"void CBitmapManipulations::MakeModification(CLookUpTables *lkUpTable)");
		return FALSE;
	}

	CFile RougeFile, VertFile, BleuFile;

	RougeFile.Open("Rouge " + iFile, CFile::modeCreate | CFile::modeWrite);
	VertFile.Open("Vert " + iFile, CFile::modeCreate | CFile::modeWrite);
	BleuFile.Open("Bleu " + iFile, CFile::modeCreate | CFile::modeWrite);
	

	int seekPos = bmpFileHeader.bfOffBits,
		widthBytes = GetWidthBytes(),
		bToSeek = FileStream.GetLength() - seekPos + 1,
		portions = bToSeek / (widthBytes * 10),
		reste = bToSeek % (widthBytes * 10);

	FileStream.Seek(0, CFile::begin);

	delete [] mem;
*/
	return TRUE;
}

BOOL CBitmapManipulations::InitBitmap(CString inFile)
{
	// Essaie d'ouvrir le fichier bitmap
	HBITMAP hBmp = (HBITMAP)LoadImage(NULL, inFile, IMAGE_BITMAP, 0, 0, 
											LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	// Si l'ouverture a échoué ????
	if (!hBmp) 
	{ 
		AfxMessageBox("Impossible d'ouvrir " + inFile + ".");
		return FALSE;
	}
	
	// Attacher l'objet CBitmap de son handle HBITMAP sinon ----> WinGdi erreur
	if (firstDrawCall) bmp.Attach(hBmp);

	Open(inFile);
	Close();

	return TRUE;
}

HBITMAP CBitmapManipulations::GetBitmapHandle()
{
	return HBITMAP(bmp);
}

void CBitmapManipulations::DrawEx(CDC *pDC, CRect &rect, COLORREF couleur)
{
	if (firstDrawCall) 
	{
		firstDrawCall = FALSE;
		memDC.CreateCompatibleDC(pDC);	
	}

	CBrush brush(couleur), *oldBrush;

	oldBrush = (CBrush*)pDC->SelectObject(&brush);
	pDC->Rectangle(rect);
	
	memDC.SelectObject(&bmp);

	pDC->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, 0, 0, 
				bmpInfoHeader.biWidth, bmpInfoHeader.biHeight, SRCAND);

	pDC->SelectObject(oldBrush);
	brush.DeleteObject();
}

BITMAPINFOHEADER* CBitmapManipulations::GetBitmapInfoHeader()
{
	return (&bmpInfoHeader);
}

BITMAPFILEHEADER* CBitmapManipulations::GetBitmapFileHeader()
{
	return (&bmpFileHeader);
}

CBitmap* CBitmapManipulations::GetCBitmap()
{
	return (&bmp);
}
