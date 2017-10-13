#if !defined(AFX_RESULT_H__01DDBAB6_AF34_4E05_BACD_69A7073A3AEE__INCLUDED_)
#define AFX_RESULT_H__01DDBAB6_AF34_4E05_BACD_69A7073A3AEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Result.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CResult dialog

class CResult : public CDialog
{
// Construction
public:
	CResult(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CResult)
	enum { IDD = IDD_RESBOX };
	int		m_editAge;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResult)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CResult)
	afx_msg void OnSave();
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	BOOL OnInitDialog();

private:
	CFont m_fStress;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESULT_H__01DDBAB6_AF34_4E05_BACD_69A7073A3AEE__INCLUDED_)
