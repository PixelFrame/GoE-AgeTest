#if !defined(AFX_TESTBOX_H__733DA35B_B31C_4FAD_A225_97EE82B32472__INCLUDED_)
#define AFX_TESTBOX_H__733DA35B_B31C_4FAD_A225_97EE82B32472__INCLUDED_

#include "QuesSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestBox.h : header file
//

#include "QuesSet.h"

/////////////////////////////////////////////////////////////////////////////
// CTestBox dialog

class CTestBox : public CDialog
{
// Construction
public:
	CQuesSet currentQues;
	CTestBox(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTestBox)
	enum { IDD = IDD_TESTBOX };
	int		m_iRadio;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestBox)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTestBox)
	afx_msg void OnNext();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnLast();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	BOOL OnInitDialog();

private:
	static int QuesNum;
	int m_iScore[256];
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTBOX_H__733DA35B_B31C_4FAD_A225_97EE82B32472__INCLUDED_)
