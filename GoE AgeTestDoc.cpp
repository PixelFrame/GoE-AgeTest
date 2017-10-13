// GoE AgeTestDoc.cpp : implementation of the CGoEAgeTestDoc class
//

#include "stdafx.h"
#include "GoE AgeTest.h"

#include "GoE AgeTestDoc.h"
#include "LoginBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGoEAgeTestDoc

IMPLEMENT_DYNCREATE(CGoEAgeTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CGoEAgeTestDoc, CDocument)
	//{{AFX_MSG_MAP(CGoEAgeTestDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGoEAgeTestDoc construction/destruction

CGoEAgeTestDoc::CGoEAgeTestDoc()
{
	CLoginBox lBox;
	lBox.DoModal();
}

CGoEAgeTestDoc::~CGoEAgeTestDoc()
{
}

BOOL CGoEAgeTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGoEAgeTestDoc serialization

void CGoEAgeTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGoEAgeTestDoc diagnostics

#ifdef _DEBUG
void CGoEAgeTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGoEAgeTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGoEAgeTestDoc commands



