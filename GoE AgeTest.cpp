// GoE AgeTest.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "GoE AgeTest.h"

#include "MainFrm.h"
#include "GoE AgeTestDoc.h"
#include "GoE AgeTestView.h"
#include "Public.h"
#include "TestBox.h"
#include "ManageBox.h"
#include "Statistic.h"
#include "Splash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGoEAgeTestApp

BEGIN_MESSAGE_MAP(CGoEAgeTestApp, CWinApp)
	//{{AFX_MSG_MAP(CGoEAgeTestApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_MENU_EXIT, OnMenuExit)
	ON_COMMAND(ID_MENU_SWITCH, OnMenuSwitch)
	ON_COMMAND(ID_MENU_TEST, OnMenuTest)
	ON_COMMAND(ID_MENU_MANAGE, OnMenuManage)
	ON_UPDATE_COMMAND_UI(ID_MENU_MANAGE, OnUpdateMenuManage)
	ON_COMMAND(ID_MENU_STAT, OnMenuStat)
	ON_UPDATE_COMMAND_UI(ID_MENU_STAT, OnUpdateMenuStat)
	ON_COMMAND(ID_MENU_STOP, OnMenuStop)
	ON_COMMAND(ID_MENU_PLAY, OnMenuPlay)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGoEAgeTestApp construction

CGoEAgeTestApp::CGoEAgeTestApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CGoEAgeTestApp object

CGoEAgeTestApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CGoEAgeTestApp initialization

BOOL CGoEAgeTestApp::InitInstance()
{
	AfxEnableControlContainer();
	CSplash splash;
	splash.DoModal();
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings(7);  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CGoEAgeTestDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CGoEAgeTestView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	m_pMainWnd->SetWindowText("Guardians of Emperor AgeTest");

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSpecial();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_BN_CLICKED(IDC_SPECIAL, OnSpecial)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CGoEAgeTestApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CGoEAgeTestApp message handlers


void CGoEAgeTestApp::OnMenuTest() 
{
	CPublic::list.m_currentUser.m_iTestResult=0;
	CTestBox tBox;
	tBox.DoModal();
}

void CGoEAgeTestApp::OnMenuSwitch() 
{
	if(MessageBox(AfxGetMainWnd()->GetSafeHwnd(),"确定要退出当前登录吗？","GoE AgeTest",MB_YESNO|MB_ICONQUESTION)==IDYES)
	{
		char buf[256];
		::GetModuleFileName(NULL,buf,sizeof(buf));
		CString strPath = buf;
		WinExec(strPath, SW_SHOW);
		exit(0);
	}
}

void CGoEAgeTestApp::OnMenuExit() 
{
	if (MessageBox(AfxGetMainWnd()->GetSafeHwnd(),"确定要退出吗？","提示",MB_YESNO)==IDYES)
	{
		exit(0);
	}
}
void CGoEAgeTestApp::OnMenuManage() 
{
	CManageBox mBox;
	mBox.DoModal();
}

void CGoEAgeTestApp::OnUpdateMenuManage(CCmdUI* pCmdUI) 
{
	if(CPublic::list.m_currentUser.m_bIsAdmin==TRUE)
		pCmdUI->Enable(TRUE);
	else pCmdUI->Enable(FALSE);
}

void CGoEAgeTestApp::OnMenuStat() 
{
	CStatistic sBox;
	sBox.DoModal();
}

void CGoEAgeTestApp::OnUpdateMenuStat(CCmdUI* pCmdUI) 
{
	if(CPublic::list.m_currentUser.m_bIsAdmin==TRUE)
		pCmdUI->Enable(TRUE);
	else pCmdUI->Enable(FALSE);
}

void CGoEAgeTestApp::OnMenuStop() 
{	
	CPublic::mus.stop();
}

void CGoEAgeTestApp::OnMenuPlay() 
{
	CPublic::mus.play();
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if(CPublic::list.m_currentUser.m_strUsername=="我爱学习"&&CPublic::list.m_currentUser.m_strPassword=="学习使我快乐")
		GetDlgItem(IDC_SPECIAL)->ShowWindow(TRUE);
	else GetDlgItem(IDC_SPECIAL)->ShowWindow(FALSE);
	
	return TRUE;
}

void CAboutDlg::OnSpecial() 
{
	GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC2)->ShowWindow(FALSE);
	GetDlgItem(IDC_COPYRIGHT)->ShowWindow(FALSE);
	GetDlgItem(IDC_ICONPIC)->ShowWindow(FALSE);
	GetDlgItem(IDC_SPEC)->ShowWindow(TRUE);
}
