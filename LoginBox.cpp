// LoginBox.cpp : implementation file
//

#include "stdafx.h"

#include "GoE AgeTest.h"
#include "LoginBox.h"
#include "Public.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginBox dialog


CLoginBox::CLoginBox(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginBox::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginBox)
	m_strPassword = _T("");
	m_strUsername = _T("");
	//}}AFX_DATA_INIT
}


void CLoginBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginBox)
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_editPassword);
	DDX_Control(pDX, IDC_CHECK, m_bottonCheck);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassword);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_strUsername);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginBox, CDialog)
	//{{AFX_MSG_MAP(CLoginBox)
	ON_BN_CLICKED(ID_GUS_LOGIN, OnGusLogin)
	ON_BN_CLICKED(ID_REGISTER, OnRegister)
	ON_BN_CLICKED(IDC_CHECK, OnCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginBox message handlers

void CLoginBox::OnOK() 
{
	GetDlgItem(IDC_EDIT_USERNAME)->GetWindowText(m_strUsername);
	GetDlgItem(IDC_EDIT_PASSWORD)->GetWindowText(m_strPassword);
	if(CPublic::list.Search(m_strUsername,m_strPassword)) 
	{
		CPublic::UserStatus=1;
		CDialog::OnOK();
	}
	else MessageBox("密码或用户名错误","警告",MB_ICONWARNING);
}
void CLoginBox::OnGusLogin() 
{
	CDialog::OnOK();
}

void CLoginBox::OnCancel() 
{
	exit(0);
	CDialog::OnCancel();
}

void CLoginBox::OnRegister() 
{
	GetDlgItem(IDC_EDIT_USERNAME)->GetWindowText(m_strUsername);
	GetDlgItem(IDC_EDIT_PASSWORD)->GetWindowText(m_strPassword);
	if(CPublic::list.searchUsername(m_strUsername)) MessageBox("用户名已被使用！","警告",MB_ICONWARNING);
	else if(m_strUsername=="") MessageBox("用户名不能为空！","警告",MB_ICONWARNING);
	else if(m_strUsername.GetLength()>50||m_strPassword.GetLength()>50) MessageBox("用户名或密码过长！","警告",MB_ICONWARNING);
	else 
	{
		if(m_strUsername=="我爱学习"&&m_strPassword=="学习使我快乐") MessageBox("Bingo！","",MB_OK);
		CPublic::UserStatus=2;
		CPublic::list.m_currentUser.editUser(m_strUsername.GetBuffer(50),m_strPassword.GetBuffer(50),FALSE,0,0);
		CDialog::OnOK();
	}
}

BOOL CLoginBox::OnInitDialog()
{
	CPublic::mus.play();
	HICON m_hIcon;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, TRUE); 
	return TRUE;
}

CLoginBox::~CLoginBox()
{
}

BOOL CLoginBox::PreTranslateMessage(MSG *pMsg)
{
	if (WM_KEYFIRST <= pMsg->message && pMsg->message <= WM_KEYLAST)
	{
		if (GetKeyState(VK_CAPITAL) & 0x0001)
		{
			GetDlgItem(IDC_CAPSLOCK)->SetWindowText("大写锁定已打开");
		}
		else
		{
			GetDlgItem(IDC_CAPSLOCK)->SetWindowText("");
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CLoginBox::OnCheck() 
{
	int state;
	UpdateData(true);
	state=m_bottonCheck.GetCheck();
	if(BST_CHECKED==state)
	{
		m_editPassword.SetPasswordChar(NULL);
		m_editPassword.SetFocus();
	}
	else
	{
		m_editPassword.SetPasswordChar('*');
		m_editPassword.SetFocus();
	}
}
