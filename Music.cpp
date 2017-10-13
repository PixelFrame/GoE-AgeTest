// Music.cpp: implementation of the CMusic class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "goe agetest.h"
#include "Music.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMusic::CMusic()
{
	TCHAR tmpwav[_MAX_PATH];
	::GetTempPath(_MAX_PATH,tmpwav);
	_tcscat(tmpwav, _T("GoE_bgm.mp3"));
	ExtractResource(tmpwav, "Music", MAKEINTRESOURCE(IDR_MUSIC1));
	_stprintf(mcicmd, _T("open %s alias mymusic"),tmpwav);
}

CMusic::~CMusic()
{

}

BOOL CMusic::ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType,LPCTSTR strResName)
{
	HANDLE hFile = ::CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
	if (hFile == INVALID_HANDLE_VALUE) return FALSE;
	
	HRSRC hRes = ::FindResource(NULL, strResName, strResType);
	HGLOBAL hMem = ::LoadResource(NULL, hRes);
	DWORD dwSize = ::SizeofResource(NULL, hRes);
	
	DWORD dwWrite = 0;
	::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
	::CloseHandle(hFile);
	return TRUE;
}

void CMusic::play()
{
	mciSendString(_T("close mymusic"), NULL, 0, NULL);
	mciSendString(mcicmd, NULL,0, NULL);
	mciSendString(_T("play mymusic repeat"),NULL, 0, NULL);        
}

void CMusic::stop()
{
	mciSendString(_T("stop mymusic"),NULL,0, NULL);
}
