// GoE AgeTestDoc.h : interface of the CGoEAgeTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GOEAGETESTDOC_H__37B46AFE_1EDC_4B61_9C0C_90D55AA9A01A__INCLUDED_)
#define AFX_GOEAGETESTDOC_H__37B46AFE_1EDC_4B61_9C0C_90D55AA9A01A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGoEAgeTestDoc : public CDocument
{
protected: // create from serialization only
	CGoEAgeTestDoc();
	DECLARE_DYNCREATE(CGoEAgeTestDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGoEAgeTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGoEAgeTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGoEAgeTestDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOEAGETESTDOC_H__37B46AFE_1EDC_4B61_9C0C_90D55AA9A01A__INCLUDED_)
