/********************************************************************
	文件名: 	TacLanguageMan.h
	作者:		chuckey.tang
	创建时间:	12:12:2012   19:17
	
	说明:		
*********************************************************************/
#pragma once

// project
#include "Base/TacConfig.h"
#include "Base/TacTypes.h"
#include "LIB/safe_singleton.hpp"
#include "Assist/GameRes.h"

// std
#include <map>
#include <string>

#define TAC_GET_STRING(id) (TacLanguageMan::instance().findTxt(id))

typedef std::map<int, std::map<int, std::string> > NFLanMap;

class TacLanguageMan : public safe_singleton<TacLanguageMan>
{
protected:
	NFLanMap m_mapLanguages;
	int m_nCurLanguage;

public:
	TacLanguageMan(void);
	virtual ~TacLanguageMan(void);

	virtual bool init(int curLan);
	std::string findTxt(int id);
	std::string findTxt(std::string englishTxt);
	std::string findTxt(int id, int language);
	std::string findTxt(std::string englishTxt, int language);

protected:
	bool isLangSupported(int language) const;
};

