// QuesList.cpp: implementation of the CQuesList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "goe agetest.h"
#include "QuesList.h"

#include <fstream>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CQuesList::CQuesList()
{
	num=0;
	if(loadQues());
	else MessageBox(0,"无题库数据！\n只能在测试模式运行！","警告",MB_ICONWARNING);
}

CQuesList::~CQuesList()
{

}

BOOL CQuesList::loadQues()
{
	std::ifstream ifile("QuesList.dat");
	if(ifile)																	//CStdioFile实现过于繁琐
	{																			//使用标准文件流
		while(!ifile.eof())
		{
			ifile>>quesList[num].m_strQues
				>>quesList[num].m_strChoice[0]>>quesList[num].m_iScore[0]
				>>quesList[num].m_strChoice[1]>>quesList[num].m_iScore[1]
				>>quesList[num].m_strChoice[2]>>quesList[num].m_iScore[2];
			++num;
			if(num==255) 
			{
				MessageBox(0,"题库数目过多！\n多于256题的部分已被忽略！ ","Error",MB_ICONWARNING);
				break;			
			}
		}
		ifile.close();
		return TRUE;
	}
	else
	{
		ifile.close();
		return FALSE;
	}
}
