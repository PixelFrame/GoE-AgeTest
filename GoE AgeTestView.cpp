// GoE AgeTestView.cpp : implementation of the CGoEAgeTestView class
//

#include "stdafx.h"
#include "GoE AgeTest.h"

#include "GoE AgeTestDoc.h"
#include "GoE AgeTestView.h"

#include "Public.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGoEAgeTestView

IMPLEMENT_DYNCREATE(CGoEAgeTestView, CScrollView)

BEGIN_MESSAGE_MAP(CGoEAgeTestView, CScrollView)
	//{{AFX_MSG_MAP(CGoEAgeTestView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGoEAgeTestView construction/destruction

CGoEAgeTestView::CGoEAgeTestView()
{
	// TODO: add construction code here
	
}

CDC CGoEAgeTestView::dcMem;
CBitmap CGoEAgeTestView::bitmap;

CGoEAgeTestView::~CGoEAgeTestView()
{
}

BOOL CGoEAgeTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGoEAgeTestView drawing

void CGoEAgeTestView::OnDraw(CDC* pDC)
{
	CGoEAgeTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	dcMem.CreateCompatibleDC(pDC);
	bitmap.LoadBitmap(IDB_BITMAP2);

	BITMAP bit;
	bitmap.GetBitmap(&bit);   
	CBitmap *pbmpOld=dcMem.SelectObject(&bitmap);
	BITMAP bmp;
	bitmap.GetBitmap(&bmp);
	CRect rect;
	GetClientRect(rect);
	pDC->SetStretchBltMode(COLORONCOLOR);
	pDC->StretchBlt(0,0,rect.Width(),rect.Height()*3.8,&dcMem,0,0,bit.bmWidth,bit.bmHeight,SRCCOPY);
	bitmap.DeleteObject();
	dcMem.DeleteDC();

	CFont MSYH;
	MSYH.CreateFont(19,0,0,0,800,FALSE,FALSE,0,ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS,_T("΢���ź�"));
	pDC->SelectObject(&MSYH);
	pDC->SetBkMode(TRANSPARENT);
	int i=1,height=16;
	pDC->TextOut(0,0,"�û���");
	pDC->TextOut(200,0,"��������");
	pDC->TextOut(400,0,"ʵ������");
	if(CPublic::list.m_currentUser.m_bIsAdmin)
	{
		CString str;
		for(i=0;i<CPublic::list.userNum;++i)
		{
			if (CPublic::list.userList[i].m_iTestResult>75)
			{
				str="60������";
				pDC->SetTextColor(RGB(255,0,0));
			}
			else if (CPublic::list.userList[i].m_iTestResult>65)
			{
				str="50-59��";
				pDC->SetTextColor(RGB(255,100,0));
			}
			else if (CPublic::list.userList[i].m_iTestResult>50)
			{
				str="40-49��";
				pDC->SetTextColor(RGB(255,255,0));
			}
			else if (CPublic::list.userList[i].m_iTestResult>30)
			{
				str="30-39��";
				pDC->SetTextColor(RGB(29,226,92));
			}
			else if (CPublic::list.userList[i].m_iTestResult>0)
			{
				str="20-29��";
				pDC->SetTextColor(RGB(0,115,255));
			}
			else 
			{
				pDC->SetTextColor(RGB(0,0,0));
				str="?";
			}
			if(CPublic::list.userList[i].m_bIsAdmin==TRUE) pDC->SetTextColor(RGB(255,255,255));
			pDC->TextOut(0,height*i+height,CPublic::list.userList[i].m_strUsername);
			pDC->TextOut(200,height*i+height,str);
			str.Format("%d",CPublic::list.userList[i].m_iActualAge);
			pDC->TextOut(400,height*i+height,str);
		}
	}
	else
	{
		CString str;
		if(CPublic::list.m_currentUser.m_iTestResult!=0) 
		{
			if(CPublic::list.m_currentUser.m_iTestResult>75) 
			{
				pDC->SetTextColor(RGB(255,0,0));
				str="60������";
			}
			else if(CPublic::list.m_currentUser.m_iTestResult>65) 
			{
				pDC->SetTextColor(RGB(255,100,0));
				str="50-59��";
			}
			else if(CPublic::list.m_currentUser.m_iTestResult>50) 
			{
				pDC->SetTextColor(RGB(255,255,0));
				str="40-49��";
			}
			else if(CPublic::list.m_currentUser.m_iTestResult>30) 
			{
				pDC->SetTextColor(RGB(29,226,92));
				str="30-39��";
			}
			else 
			{
				pDC->SetTextColor(RGB(0,115,255));
				str="20-29��";
			}
		}
		else str="?";
		pDC->TextOut(0,height,CPublic::list.m_currentUser.m_strUsername);
		pDC->TextOut(200,height,str);
		str.Format("%d",CPublic::list.m_currentUser.m_iActualAge);
		pDC->TextOut(400,height,str);
	}
	pDC->SetTextColor(RGB(0,0,0));
	CFont BLACK;
	BLACK.CreateFont(15,0,0,0,800,FALSE,FALSE,0,ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS,_T("΢���ź�"));
	pDC->SelectObject(&BLACK);
	i+=5;
	pDC->TextOut(0,height+height*++i,"GoE Dev.");
	pDC->SetTextColor(RGB(91,99,247));
	pDC->TextOut(0,height+height*++i,"����D �û�ϵͳ");pDC->TextOut(230,height+height*i,"25%");
	pDC->SetTextColor(RGB(0,0,0));
	pDC->TextOut(0,height+height*++i,"��� ���ϵͳ & ��¼���ӹ���");pDC->TextOut(230,height+height*i,"20%");
	pDC->TextOut(0,height+height*++i,"������ �Ի������ & ��ť����");pDC->TextOut(230,height+height*i,"15%");
	pDC->TextOut(0,height+height*++i,"���κ� ������ & ����");pDC->TextOut(230,height+height*i,"15%");
	pDC->TextOut(0,height+height*++i,"������ ������� & �����ӹ���");pDC->TextOut(230,height+height*i,"25%");
	pDC->TextOut(0,height+height*++i,"GoE AgeTest v1.60");
}

/////////////////////////////////////////////////////////////////////////////
// CGoEAgeTestView diagnostics

#ifdef _DEBUG
void CGoEAgeTestView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CGoEAgeTestView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CGoEAgeTestDoc* CGoEAgeTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGoEAgeTestDoc)));
	return (CGoEAgeTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGoEAgeTestView message handlers


void CGoEAgeTestView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();
	SetScrollSizes(MM_TEXT, CSize( 500, 1000 ) );
}

void CGoEAgeTestView::CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType) 
{
	CScrollView::CalcWindowRect(lpClientRect, nAdjustType);
}