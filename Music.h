// Music.h: interface for the CMusic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MUSIC_H__6D3968B6_CDA6_4248_B326_DEAA24B7236F__INCLUDED_)
#define AFX_MUSIC_H__6D3968B6_CDA6_4248_B326_DEAA24B7236F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <mmsystem.h>
#pragma comment(lib,"WINMM.lib")

class CMusic  
{
public:
	CMusic();
	virtual ~CMusic();
	void play();
	void stop();

private:
	TCHAR mcicmd[300];
	BOOL ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName);
};

#endif // !defined(AFX_MUSIC_H__6D3968B6_CDA6_4248_B326_DEAA24B7236F__INCLUDED_)
