// ManageBox.cpp : implementation file
//

#include "stdafx.h"
#include "goe agetest.h"
#include "ManageBox.h"
#include "Public.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManageBox dialog


CManageBox::CManageBox(CWnd* pParent /*=NULL*/)
	: CDialog(CManageBox::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManageBox)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CManageBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManageBox)
	DDX_Control(pDX, IDC_LIST, m_ctlList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManageBox, CDialog)
	//{{AFX_MSG_MAP(CManageBox)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_SET_ADMIN, OnSetAdmin)
	ON_BN_CLICKED(IDC_CANCEL_ADMIN, OnCancelAdmin)
	ON_BN_CLICKED(IDC_SAVE_EDIT, OnSaveEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManageBox message handlers

BOOL CManageBox::OnInitDialog()
{
	RECT rect;
	this->GetClientRect(&rect);
	rect.bottom-=60;
	m_ctlList.Create(WS_VISIBLE,rect,this,0);
	
	SetWindowLong(m_ctlList.m_hWnd,GWL_STYLE,GetWindowLong(m_ctlList.m_hWnd,GWL_STYLE)|LVS_REPORT);
	m_ctlList.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);

	m_ctlList.InsertColumn(0,"用户名",LVCFMT_LEFT,100);
	m_ctlList.InsertColumn(1,"密码",LVCFMT_LEFT,100);
	m_ctlList.InsertColumn(2,"管理员",LVCFMT_LEFT,70);
	m_ctlList.InsertColumn(3,"测试结果",LVCFMT_LEFT,70);
	m_ctlList.InsertColumn(4,"实际年龄",LVCFMT_LEFT,50);

	for(int i=CPublic::list.userNum-1;i>-1;--i)
	{
		m_ctlList.InsertItem(0,CPublic::list.userList[i].m_strUsername);
		m_ctlList.SetItemText(0,1,CPublic::list.userList[i].m_strPassword);
		if(CPublic::list.userList[i].m_bIsAdmin) m_ctlList.SetItemText(0,2,"是");
		else m_ctlList.SetItemText(0,2,"否");
		CString str;
		str.Format("%d",CPublic::list.userList[i].m_iTestResult);
		m_ctlList.SetItemText(0,3,str);
		str.Format("%d",CPublic::list.userList[i].m_iActualAge);
		m_ctlList.SetItemText(0,4,str);
	}
	return TRUE;
}


void CManageBox::OnDelete() 
{
	int i=m_ctlList.GetSelectionMark();
	if(i==-1) MessageBox("未选择用户","错误",MB_ICONHAND);
	else if(i!=0)
	{
		CPublic::list.deleteUser(i);
		m_ctlList.SetItemText(i,0,"");
		m_ctlList.SetItemText(i,1,"");
		m_ctlList.SetItemText(i,2,"");
		m_ctlList.SetItemText(i,3,"");
		m_ctlList.SetItemText(i,4,"");
	}
	else MessageBox("不可删除内建管理员！","错误",MB_ICONHAND);
}

void CManageBox::OnSetAdmin() 
{
	int i=m_ctlList.GetSelectionMark();
	if(i==-1) MessageBox("未选择用户","错误",MB_ICONHAND);
	else
	{
		CPublic::list.userList[i].m_bIsAdmin=TRUE;
		m_ctlList.SetItemText(i,2,"是");
	}
}

void CManageBox::OnCancelAdmin() 
{
	int i=m_ctlList.GetSelectionMark();
	if(i==-1) MessageBox("未选择用户","错误",MB_ICONHAND);
	else if(i!=0)
	{
		CPublic::list.userList[i].m_bIsAdmin=FALSE;
		m_ctlList.SetItemText(i,2,"否");
	}
	else MessageBox("不可取消内建管理员！","错误",MB_ICONHAND);
}
void CManageBox::OnSaveEdit() 
{
	if(MessageBox("确实要保存修改吗？","警告",MB_YESNO|MB_ICONWARNING)==IDYES)
		CPublic::list.saveList();

}
void CManageBox::OnCancel() 
{
	CPublic::list.loadUser();	
	CDialog::OnCancel();
	AfxGetMainWnd()->Invalidate();
}
