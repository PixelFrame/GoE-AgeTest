#if !defined(AFX_STATISTIC_H__FE030861_B9A4_46AB_970D_83F6FCEEF788__INCLUDED_)
#define AFX_STATISTIC_H__FE030861_B9A4_46AB_970D_83F6FCEEF788__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BarChart\\BarChart.h"

// Statistic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStatistic dialog

class CStatistic : public CDialog
{
// Construction
public:
	CStatistic(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStatistic)
	enum { IDD = IDD_STATISTIC };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatistic)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int actNum[6];
	int testNum[6];
	int adminNum;
	void numCount();
	BOOL OnInitDialog();

	CBarChart m_chart1;
	CBarChart m_chart2;

	// Generated message map functions
	//{{AFX_MSG(CStatistic)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATISTIC_H__FE030861_B9A4_46AB_970D_83F6FCEEF788__INCLUDED_)
