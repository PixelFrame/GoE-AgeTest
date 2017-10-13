// GoE AgeTest.h : main header file for the GOE AGETEST application
//

#if !defined(AFX_GOEAGETEST_H__58531AEE_599F_4016_AD64_2B0E20B7DF6B__INCLUDED_)
#define AFX_GOEAGETEST_H__58531AEE_599F_4016_AD64_2B0E20B7DF6B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGoEAgeTestApp:
// See GoE AgeTest.cpp for the implementation of this class
//

class CGoEAgeTestApp : public CWinApp
{
public:
	CGoEAgeTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGoEAgeTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGoEAgeTestApp)
	afx_msg void OnAppAbout();
	afx_msg void OnMenuExit();
	afx_msg void OnMenuSwitch();
	afx_msg void OnMenuTest();
	afx_msg void OnMenuManage();
	afx_msg void OnUpdateMenuManage(CCmdUI* pCmdUI);
	afx_msg void OnMenuStat();
	afx_msg void OnUpdateMenuStat(CCmdUI* pCmdUI);
	afx_msg void OnMenuStop();
	afx_msg void OnMenuPlay();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOEAGETEST_H__58531AEE_599F_4016_AD64_2B0E20B7DF6B__INCLUDED_)
