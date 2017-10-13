// Statistic.cpp : implementation file
//

#include "stdafx.h"
#include "goe agetest.h"
#include "Statistic.h"

#include "Public.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatistic dialog


CStatistic::CStatistic(CWnd* pParent /*=NULL*/)
	: CDialog(CStatistic::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStatistic)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	adminNum=0;
	for(int i=0;i<6;++i) { actNum[i]=0; testNum[i]=0;}
}


void CStatistic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStatistic)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStatistic, CDialog)
	//{{AFX_MSG_MAP(CStatistic)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatistic message handlers

BOOL CStatistic::OnInitDialog()
{
	numCount();

	CString str;
	str.Format("%d",CPublic::list.userNum);
	GetDlgItem(IDC_USERNUM)->SetWindowText(str);

	str.Format("%d",adminNum);
	GetDlgItem(IDC_ADMINNUM)->SetWindowText(str);
	str.Format("%d",CPublic::list.userNum-adminNum);
	GetDlgItem(IDC_NONADMINNUM)->SetWindowText(str);

	CRect rect; 
	GetDlgItem(IDC_CHART1)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	if (!m_chart1.Create(rect, this, 1050 )) 
	{ 
		if (!m_chart1.GetSafeHwnd()) 
		{ 
			AfxMessageBox(_T("不能创建图表控件！")); 
			return FALSE; 
		}
		m_chart1.Reset(); 
		m_chart1.SetAutoScale(FALSE); 
	}
	m_chart1.SetTitle(_T("用户实际年龄分布")); 
	m_chart1.SetBKColor(RGB(255, 255, 240)); 
	m_chart1.ShowTooltip(FALSE); 
	m_chart1.AddBar(actNum[0],_T("<20"),RGB(40,200,255)); 
	m_chart1.AddBar(actNum[1],_T("20-29"), RGB(0,115,255)); 
	m_chart1.AddBar(actNum[2],_T("30-39"), RGB(0,255,0)); 
	m_chart1.AddBar(actNum[3],_T("40-49"), RGB(255,255,0)); 
	m_chart1.AddBar(actNum[4],_T("50-59"), RGB(255,100,0)); 
	m_chart1.AddBar(actNum[5],_T(">60"), RGB(255,0,0),TRUE); 

	GetDlgItem(IDC_CHART2)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	if (!m_chart2.Create(rect, this, 1050 )) 
	{ 
		if (!m_chart2.GetSafeHwnd()) 
		{ 
			AfxMessageBox(_T("不能创建图表控件！")); 
			return FALSE; 
		}
		m_chart2.Reset(); 
		m_chart2.SetAutoScale(FALSE); 
	}
	m_chart2.SetTitle(_T("用户测试年龄分布")); 
	m_chart2.SetBKColor(RGB(255, 255, 240)); 
	m_chart2.ShowTooltip(FALSE); 
	m_chart2.AddBar(testNum[0],_T("<20"),RGB(40,200,255)); 
	m_chart2.AddBar(testNum[1],_T("20-29"), RGB(0,115,255)); 
	m_chart2.AddBar(testNum[2],_T("30-39"), RGB(0,255,0)); 
	m_chart2.AddBar(testNum[3],_T("40-49"), RGB(255,255,0)); 
	m_chart2.AddBar(testNum[4],_T("50-59"), RGB(255,100,0)); 
	m_chart2.AddBar(testNum[5],_T(">60"), RGB(255,0,0),TRUE);

	return TRUE;
}

void CStatistic::numCount()
{
	for(int i=0;i<CPublic::list.userNum;++i)
	{
		if(CPublic::list.userList[i].m_bIsAdmin==TRUE)
			++adminNum;
		if(CPublic::list.userList[i].m_iActualAge<20)
			++actNum[0];
		else if(CPublic::list.userList[i].m_iActualAge<30)
			++actNum[1];
		else if(CPublic::list.userList[i].m_iActualAge<40)
			++actNum[2];
		else if(CPublic::list.userList[i].m_iActualAge<50)
			++actNum[3];
		else if(CPublic::list.userList[i].m_iActualAge<60)
			++actNum[4];
		else ++actNum[5];
		if (CPublic::list.userList[i].m_iTestResult>75)
			++testNum[5];
		else if (CPublic::list.userList[i].m_iTestResult>65)
			++testNum[4];
		else if (CPublic::list.userList[i].m_iTestResult>50)
			++testNum[3];
		else if (CPublic::list.userList[i].m_iTestResult>30)
			++testNum[2];
		else if (CPublic::list.userList[i].m_iTestResult>0)
			++testNum[1];
		else ++testNum[0];
	}
}
