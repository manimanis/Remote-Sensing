// RmtSensingDoc.cpp : implementation of the CRmtSensingDoc class
//

#include "stdafx.h"
#include "RmtSensing.h"

#include "RmtSensingDoc.h"
// #include "PictureHistogrammeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingDoc

IMPLEMENT_DYNCREATE(CRmtSensingDoc, CDocument)

BEGIN_MESSAGE_MAP(CRmtSensingDoc, CDocument)
	//{{AFX_MSG_MAP(CRmtSensingDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingDoc construction/destruction

CRmtSensingDoc::CRmtSensingDoc()
{
	RComponent = GComponent = BComponent = histoPlotted = FALSE;
}

CRmtSensingDoc::~CRmtSensingDoc()
{
}

BOOL CRmtSensingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRmtSensingDoc serialization
void CRmtSensingDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		BITMAP bm; bmpManip.GetCBitmap()->GetBitmap(&bm);

		ar.Write(bmpManip.GetBitmapFileHeader(), sizeof(BITMAPFILEHEADER));
		ar.Write(bmpManip.GetBitmapInfoHeader(), sizeof(BITMAPINFOHEADER));
		ar.Write(bm.bmBits, bmpManip.GetHeight() * bmpManip.GetWidthBytes());
	}
	else
	{
		// TODO
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingDoc diagnostics

#ifdef _DEBUG
void CRmtSensingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRmtSensingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRmtSensingDoc commands

BOOL CRmtSensingDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	iFile = lpszPathName;

	if (!bmpManip.Open(iFile)) 
	{
		AfxMessageBox("Impossible d'ouvrir " + iFile + ".");
		bmpManip.Close();
		return FALSE;
	}

	if (!bmpManip.IsValidBitmap())
	{
		AfxMessageBox("Ce n'est pas un bitmap valide.");
		bmpManip.Close();
		return FALSE;
	}

	if (bmpManip.GetBitCount() < 24)
	{
		AfxMessageBox("Ce programme supporte uniquement les bitmap 24 bits.");
		Informations();
		bmpManip.Close();
		return FALSE;
	}

	oFile = iFile;
	iFile = iFile + ".tmp";

	bmpManip.CreateTempCopy(iFile);

	bmpManip.Close();

	bmpManip.InitBitmap(iFile);

	picData = bmpManip.GetPictureHistogrammeInfo();
	cumData = bmpManip.GetCumulatifHistogrammeInfo();

	return TRUE;
}

void CRmtSensingDoc::Informations()
{
	CString str;
	str.Format(	"Fichier\t=\t%s\nLongueur\t=\t%d pixels\nLargeur\t=\t%d pixels"
				"\nBits/pix\t=\t%d\nOctets/lig\t=\t%d", 
				oFile, bmpManip.GetWidth(), bmpManip.GetHeight(), 
				bmpManip.GetBitCount(), bmpManip.GetWidthBytes());
	
	AfxMessageBox(str, MB_ICONINFORMATION | MB_OK);
}

BOOL CRmtSensingDoc::SaveModified() 
{
	return CDocument::SaveModified();
}

BOOL CRmtSensingDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	return CDocument::OnSaveDocument(lpszPathName);
}

void CRmtSensingDoc::OnCloseDocument() 
{
	// AfxMessageBox("Je suis dans --> void CRmtSensingDoc::OnCloseDocument()!!!");
	
	CDocument::OnCloseDocument();
}


void CRmtSensingDoc::FindRGBMax()
{
	bYmax = picData[0];
	gYmax = picData[256];
	rYmax = picData[512];
	
	for (int i = 1 ; i < 256 ; i++)
	{
		if (picData[i] > bYmax) bYmax = picData[i];
		if (picData[256 + i] > gYmax) gYmax = picData[256 + i];
		if (picData[512 + i] > rYmax) rYmax = picData[512 + i];
	}
}
