; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLoginBox
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "goe agetest.h"
LastPage=0

ClassCount=11
Class1=CGoEAgeTestApp
Class2=CAboutDlg
Class3=CGoEAgeTestDoc
Class4=CGoEAgeTestView
Class5=CLoginBox
Class6=CMainFrame
Class7=CManageBox
Class8=CResult
Class9=CTestBox

ResourceCount=8
Resource1=IDD_STATISTIC
Resource2=IDD_TESTBOX
Resource3=IDD_LOGINBOX
Resource4=IDD_MANAGE
Resource5=IDD_RESBOX
Resource6=IDD_ABOUTBOX
Class10=CStatistic
Resource7=IDR_MAINFRAME
Class11=CSplash
Resource8=IDD_SPLASH

[CLS:CGoEAgeTestApp]
Type=0
BaseClass=CWinApp
HeaderFile=GoE AgeTest.h
ImplementationFile=GoE AgeTest.cpp
LastObject=ID_MENU_STAT
Filter=N
VirtualFilter=AC

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=GoE AgeTest.cpp
ImplementationFile=GoE AgeTest.cpp
LastObject=IDC_SPECIAL
Filter=D
VirtualFilter=dWC

[CLS:CGoEAgeTestDoc]
Type=0
BaseClass=CDocument
HeaderFile=GoE AgeTestDoc.h
ImplementationFile=GoE AgeTestDoc.cpp

[CLS:CGoEAgeTestView]
Type=0
BaseClass=CScrollView
HeaderFile=GoE AgeTestView.h
ImplementationFile=GoE AgeTestView.cpp

[CLS:CLoginBox]
Type=0
BaseClass=CDialog
HeaderFile=LoginBox.h
ImplementationFile=LoginBox.cpp
LastObject=IDC_CHECK
Filter=D
VirtualFilter=dWC

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CManageBox]
Type=0
BaseClass=CDialog
HeaderFile=ManageBox.h
ImplementationFile=ManageBox.cpp

[CLS:CResult]
Type=0
BaseClass=CDialog
HeaderFile=Result.h
ImplementationFile=Result.cpp

[CLS:CTestBox]
Type=0
BaseClass=CDialog
HeaderFile=TestBox.h
ImplementationFile=TestBox.cpp
LastObject=CTestBox

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=7
Control1=IDC_ICONPIC,static,1342177294
Control2=IDC_STATIC1,static,1342308480
Control3=IDC_STATIC2,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_COPYRIGHT,static,1342308353
Control6=IDC_SPECIAL,button,1342177280
Control7=IDC_SPEC,static,1073741838

[DLG:IDD_LOGINBOX]
Type=1
Class=CLoginBox
ControlCount=13
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_USERNAME,edit,1350631552
Control6=IDC_EDIT_PASSWORD,edit,1350631584
Control7=ID_GUS_LOGIN,button,1342242816
Control8=ID_REGISTER,button,1342242816
Control9=IDC_STATIC,static,1342177294
Control10=IDC_STATIC,static,1342312449
Control11=IDC_STATIC,button,1342177287
Control12=IDC_CAPSLOCK,static,1342308352
Control13=IDC_CHECK,button,1342242819

[DLG:IDD_MANAGE]
Type=1
Class=CManageBox
ControlCount=6
Control1=IDCANCEL,button,1342242817
Control2=IDC_DELETE,button,1342242816
Control3=IDC_SET_ADMIN,button,1342242816
Control4=IDC_LIST,SysListView32,1350631425
Control5=IDC_CANCEL_ADMIN,button,1342242816
Control6=IDC_SAVE_EDIT,button,1342242816

[DLG:IDD_RESBOX]
Type=1
Class=CResult
ControlCount=6
Control1=ID_SAVE,button,1342242817
Control2=IDC_RESULT,static,1342308865
Control3=IDC_STATIC,static,1342308865
Control4=ID_CANCEL,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_AGE,edit,1350631552

[DLG:IDD_TESTBOX]
Type=1
Class=CTestBox
ControlCount=6
Control1=ID_NEXT,button,1342242817
Control2=ID_LAST,button,1342242816
Control3=IDC_QUES,static,1350697473
Control4=IDC_RADIO1,button,1342373897
Control5=IDC_RADIO2,button,1342242825
Control6=IDC_RADIO3,button,1342242825

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_MENU_STAT
Command2=ID_MENU_MANAGE
Command3=ID_MENU_SWITCH
Command4=ID_MENU_EXIT
Command5=ID_APP_ABOUT
Command6=ID_MENU_TEST
Command7=ID_MENU_PLAY
Command8=ID_MENU_STOP
CommandCount=8

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_STATISTIC]
Type=1
Class=CStatistic
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_USERNUM,static,1342308352
Control8=IDC_ADMINNUM,static,1342308352
Control9=IDC_NONADMINNUM,static,1342308352
Control10=IDC_CHART1,button,1342177287
Control11=IDC_CHART2,button,1342177287

[CLS:CStatistic]
Type=0
HeaderFile=Statistic.h
ImplementationFile=Statistic.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_MENU_STOP

[DLG:IDD_SPLASH]
Type=1
Class=CSplash
ControlCount=1
Control1=IDC_STATIC,static,1342177294

[CLS:CSplash]
Type=0
HeaderFile=Splash.h
ImplementationFile=Splash.cpp
BaseClass=CDialog
Filter=D
LastObject=CSplash
VirtualFilter=dWC

