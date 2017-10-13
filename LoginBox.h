#if !defined(AFX_LOGINBOX_H__A2E4138F_AE6E_4577_A298_9BDDE4F7A7F9__INCLUDED_)
#define AFX_LOGINBOX_H__A2E4138F_AE6E_4577_A298_9BDDE4F7A7F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginBox dialog

class CLoginBox : public CDialog
{
// Construction
public:
	~CLoginBox();
	CLoginBox(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoginBox)
	enum { IDD = IDD_LOGINBOX };
	CEdit	m_editPassword;
	CButton	m_bottonCheck;
	CString	m_strPassword;
	CString	m_strUsername;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginBox)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL PreTranslateMessage(MSG* pMsg);
	// Generated message map functions
	//{{AFX_MSG(CLoginBox)
	virtual void OnOK();
	afx_msg void OnGusLogin();
	virtual void OnCancel();
	afx_msg void OnRegister();
	afx_msg void OnCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	BOOL OnInitDialog();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINBOX_H__A2E4138F_AE6E_4577_A298_9BDDE4F7A7F9__INCLUDED_)
