// RmtSensingDoc.h : interface of the CRmtSensingDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RMTSENSINGDOC_H__FAA7769D_4D88_11D4_B2BC_00400550E7C9__INCLUDED_)
#define AFX_RMTSENSINGDOC_H__FAA7769D_4D88_11D4_B2BC_00400550E7C9__INCLUDED_

#include "BitmapManipulations.h"
// #include "PictureHistogrammeView.h"	// Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRmtSensingDoc : public CDocument
{
protected: // create from serialization only
	CRmtSensingDoc();
	DECLARE_DYNCREATE(CRmtSensingDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRmtSensingDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
	protected:
	virtual BOOL SaveModified();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRmtSensingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
public:
	BOOL RComponent;
	BOOL GComponent;
	BOOL BComponent;
	BOOL histoPlotted;
	void FindRGBMax();
	int *cumData;
	int *picData;
	CString oFile;
	void Informations();
	CString iFile;
	CBitmapManipulations bmpManip;
	int bYmax;
	int gYmax;
	int rYmax;
protected:
	//{{AFX_MSG(CRmtSensingDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RMTSENSINGDOC_H__FAA7769D_4D88_11D4_B2BC_00400550E7C9__INCLUDED_)
