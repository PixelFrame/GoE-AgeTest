// UserList.cpp: implementation of the CUserList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GoE AgeTest.h"
#include "UserList.h"
#include "Public.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUserList::CUserList()
{
	if(loadUser());
	else 
	{
		userNum=1;
		CFile newFile("UserList.dat",CFile::modeCreate|CFile::modeWrite);
		if(newFile)
		{
			MessageBox(0,"无用户数据！\n已建立新的用户数据文件！","警告",MB_ICONQUESTION);
			userList[0].editUser("Admin","Admin",TRUE,0,0);
			newFile.Write((char*)&userNum,4);
			newFile.Write(userList[0].m_strUsername.GetBuffer(50),50);
			newFile.Write(userList[0].m_strPassword.GetBuffer(50),50);
			newFile.Write((char*)&userList[0].m_bIsAdmin,4);
			newFile.Write((char*)&userList[0].m_iTestResult,4);
			newFile.Write((char*)&userList[0].m_iActualAge,4);
			newFile.Close();
		}
		else MessageBox(0,"无用户数据！\n无法建立数据文件！\n只能使用游客模式！","警告",MB_ICONHAND);
	}
}

CUserList::~CUserList()
{

}

BOOL CUserList::loadUser()
{
	CFile Ifile;
	if(Ifile.Open("UserList.dat",CFile::modeRead))
	{
		Ifile.Read((char*)&userNum,4);
		if(userNum>256) userNum=256;
		for(int i=0;i<userNum;++i)
		{
			Ifile.Read(m_cNameBuf,50);
			Ifile.Read(m_cPassBuf,50);
			Ifile.Read((char*)&m_bIsAdmin,4);
			Ifile.Read((char*)&m_iTestRes,4);
			Ifile.Read((char*)&m_iActualAge,4);
			userList[i].editUser(m_cNameBuf,m_cPassBuf,m_bIsAdmin,m_iTestRes,m_iActualAge);
		}
		Ifile.Close();
		return TRUE;
	}
	else return FALSE;									//CFile对象关联失败，不需要也不可以Close()
}

BOOL CUserList::Search(CString& name, CString& pass)
{
	for(int i=0;i<userNum+1;++i)
		if(name==userList[i].m_strUsername&&pass==userList[i].m_strPassword)
		{
			m_currentUser=userList[i];
			return TRUE;
		}
	return FALSE;
}

void CUserList::updateCurrData()
{
	int i;
	switch(CPublic::UserStatus)
	{
	case 1:for(i=0;i<userNum;++i)
			if(m_currentUser.m_strUsername==userList[i].m_strUsername&&m_currentUser.m_strPassword==userList[i].m_strPassword)
				userList[i]=m_currentUser;
			break;
	case 2:addUser(m_currentUser);break;
	default:;
	}
}

BOOL CUserList::searchUsername(CString &name)
{
	for(int i=0;i<userNum;++i)
		if(name==userList[i].m_strUsername)
			return TRUE;
	return FALSE;
}

void CUserList::addUser(CUserSet& newUser)
{
	if(userNum==256) MessageBox(0,"用户已达最大上限！","Error",MB_ICONHAND);
	else userList[userNum++] = newUser;
}

void CUserList::deleteUser(int num)
{
	for(int i=num;i<userNum&&i<255;++i)
	{
		userList[i]=userList[i+1];
	}
	--userNum;
}

void CUserList::saveList()
{
	CFile Ofile;
	if(Ofile.Open("UserList.dat",CFile::modeWrite))
	{
		Ofile.Write((char*)&CPublic::list.userNum,4);
		for(int i=0;i<CPublic::list.userNum;++i)
		{
			Ofile.Write(CPublic::list.userList[i].m_strUsername.GetBuffer(50),50);
			Ofile.Write(CPublic::list.userList[i].m_strPassword.GetBuffer(50),50);
			Ofile.Write((char*)&CPublic::list.userList[i].m_bIsAdmin,4);
			Ofile.Write((char*)&CPublic::list.userList[i].m_iTestResult,4);
			Ofile.Write((char*)&CPublic::list.userList[i].m_iActualAge,4);
		}
		Ofile.Close();
	}
	else MessageBox(NULL,"无法保存用户数据文件！","错误",MB_ICONHAND);
}
