// GoE AgeTestView.h : interface of the CGoEAgeTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GOEAGETESTVIEW_H__7BCBAA55_8B45_4634_AD74_5C97837DC236__INCLUDED_)
#define AFX_GOEAGETESTVIEW_H__7BCBAA55_8B45_4634_AD74_5C97837DC236__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGoEAgeTestView : public CScrollView
{
protected: // create from serialization only
	CGoEAgeTestView();
	DECLARE_DYNCREATE(CGoEAgeTestView)

// Attributes
public:
	CGoEAgeTestDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGoEAgeTestView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual void CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType = adjustBorder);
	//}}AFX_VIRTUAL

// Implementation
public:
	static CDC dcMem;
	static CBitmap bitmap;
	BOOL OnEraseBkgnd(CDC* pDC);
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual ~CGoEAgeTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGoEAgeTestView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GoE AgeTestView.cpp
inline CGoEAgeTestDoc* CGoEAgeTestView::GetDocument()
   { return (CGoEAgeTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOEAGETESTVIEW_H__7BCBAA55_8B45_4634_AD74_5C97837DC236__INCLUDED_)
