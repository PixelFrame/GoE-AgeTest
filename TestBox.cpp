// TestBox.cpp : implementation file
//

#include "stdafx.h"
#include "GoE AgeTest.h"
#include "TestBox.h"
#include "Public.h"
#include "Result.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestBox dialog


CTestBox::CTestBox(CWnd* pParent /*=NULL*/)
	: CDialog(CTestBox::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestBox)
	m_iRadio = -1;
	currentQues=CPublic::qlist.quesList[QuesNum];
	//}}AFX_DATA_INIT
}

int CTestBox::QuesNum=0;

void CTestBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestBox)
	DDX_Radio(pDX, IDC_RADIO1, m_iRadio);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestBox, CDialog)
	//{{AFX_MSG_MAP(CTestBox)
	ON_BN_CLICKED(ID_NEXT, OnNext)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(ID_LAST, OnLast)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestBox message handlers

void CTestBox::OnNext() 
{
	if(m_iRadio==-1) MessageBox("请选择选项","GoE AgeTest",MB_OK);
	else if(QuesNum<CPublic::qlist.num-1)
	{
		currentQues=CPublic::qlist.quesList[++QuesNum];
		CDialog::OnOK();
		CTestBox newBox;
		newBox.DoModal();
	}
	else
	{
		CDialog::OnOK();
		QuesNum=0;
		CResult resBox;
		resBox.DoModal();
	}
}

void CTestBox::OnRadio1() 
{
	m_iRadio=0;
	CPublic::list.m_currentUser.m_iTestResult+=currentQues.m_iScore[0];
	m_iScore[QuesNum]=currentQues.m_iScore[0];
}

void CTestBox::OnRadio2() 
{
	m_iRadio=1;
	CPublic::list.m_currentUser.m_iTestResult+=currentQues.m_iScore[1];
	m_iScore[QuesNum]=currentQues.m_iScore[1];
}

void CTestBox::OnRadio3() 
{
	m_iRadio=2;
	CPublic::list.m_currentUser.m_iTestResult+=currentQues.m_iScore[2];
	m_iScore[QuesNum]=currentQues.m_iScore[2];
}

void CTestBox::OnLast() 
{
	if(QuesNum<1) MessageBox("无上一题","?",MB_ICONQUESTION);
	else
	{
		CDialog::OnCancel();
		CPublic::list.m_currentUser.m_iTestResult-=m_iScore[QuesNum--];
		CTestBox newBox;
		newBox.DoModal();
	}
}

BOOL CTestBox::OnInitDialog()
{
	CString quesStr,radio1Str,radio2Str,radio3Str;
	quesStr=currentQues.m_strQues.c_str();
	radio1Str=currentQues.m_strChoice[0].c_str();
	radio2Str=currentQues.m_strChoice[1].c_str();
	radio3Str=currentQues.m_strChoice[2].c_str();
	GetDlgItem(IDC_QUES)->SetWindowText(quesStr);
	GetDlgItem(IDC_RADIO1)->SetWindowText(radio1Str);
	GetDlgItem(IDC_RADIO2)->SetWindowText(radio2Str);
	GetDlgItem(IDC_RADIO3)->SetWindowText(radio3Str);
	return TRUE;
}
