// Result.cpp : implementation file
//

#include "stdafx.h"
#include "goe agetest.h"
#include "Result.h"
#include "Public.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResult dialog


CResult::CResult(CWnd* pParent /*=NULL*/)
	: CDialog(CResult::IDD, pParent)
{
	//{{AFX_DATA_INIT(CResult)
	m_editAge = 0;
	//}}AFX_DATA_INIT
}


void CResult::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CResult)
	DDX_Text(pDX, IDC_EDIT_AGE, m_editAge);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CResult, CDialog)
	//{{AFX_MSG_MAP(CResult)
	ON_BN_CLICKED(ID_SAVE, OnSave)
	ON_BN_CLICKED(ID_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResult message handlers

BOOL CResult::OnInitDialog()
{
	CString str;
	if(CPublic::list.m_currentUser.m_iTestResult>75) str="60岁以上";
	else if(CPublic::list.m_currentUser.m_iTestResult>65) str="50-59岁";
	else if(CPublic::list.m_currentUser.m_iTestResult>50) str="40-49岁";
	else if(CPublic::list.m_currentUser.m_iTestResult>30) str="30-39岁";
	else str="20-29岁";
	m_fStress.CreateFont(50,0,0,0,800,FALSE,FALSE,0,ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS,_T("微软雅黑"));
	GetDlgItem(IDC_RESULT)->SetFont(&m_fStress);
	GetDlgItem(IDC_RESULT)->SetWindowText(str);
	return TRUE;
}
void CResult::OnSave() 
{
	if(GetDlgItemInt(IDC_EDIT_AGE))
	{
		CPublic::list.m_currentUser.m_iActualAge=GetDlgItemInt(IDC_EDIT_AGE);
		CDialog::OnOK();
		AfxGetMainWnd()->Invalidate();
		CPublic::list.updateCurrData();
		CPublic::list.saveList();
	}
	else MessageBox("请输入实际年龄","GoE AgeTest",MB_ICONQUESTION);
}
void CResult::OnCancel() 
{
	CDialog::OnCancel();
}
