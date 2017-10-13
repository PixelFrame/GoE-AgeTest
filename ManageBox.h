#if !defined(AFX_MANAGEBOX_H__63283E18_7D11_48CE_8142_B2029E7BE20F__INCLUDED_)
#define AFX_MANAGEBOX_H__63283E18_7D11_48CE_8142_B2029E7BE20F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ManageBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CManageBox dialog

class CManageBox : public CDialog
{
// Construction
public:
	
	CManageBox(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CManageBox)
	enum { IDD = IDD_MANAGE };
	CListCtrl	m_ctlList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManageBox)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CManageBox)
	afx_msg void OnDelete();
	afx_msg void OnSetAdmin();
	afx_msg void OnCancelAdmin();
	afx_msg void OnSaveEdit();
	virtual void OnCancel();
	//}}AFX_MSG
	BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
private:
	int m_iSelected;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGEBOX_H__63283E18_7D11_48CE_8142_B2029E7BE20F__INCLUDED_)
