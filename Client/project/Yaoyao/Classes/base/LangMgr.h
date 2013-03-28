/********************************************************************
Copyright (c) 2012-2013 walkbin.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

created:	2013/03/23
filename: 	LangMgr.h
author:		Richie.Wang@walkbin

purpose:	
*********************************************************************/
#pragma once

#include <map>
#include <string>
#include "config/Global.h"

NS_WALKBIN_BEGIN

enum LangType
{
    LANG_EN,
    LANG_ZH_S,
    LANG_ZH_T,
    LANG_JPN,
    LANG_FRA,
    LANG_MAX
};

typedef std::map<int, std::map<int, std::string> > LanMap;

class LangMgr
{
public:
    static LangMgr* getInstance();
    static void freeInstance();
    static void setLang(int langId);

    LangMgr(void);
    virtual ~LangMgr(void);
    virtual bool init(int curLan);
    std::string findTxt(int id);
    std::string findTxt(std::string englishTxt);
    std::string findTxt(int id, int language);
    std::string findTxt(std::string englishTxt, int language);
    bool isLangSupported(int language) const;
private:
    LanMap m_mapLanguages;
    int m_nCurLanguage;
    static LangMgr* s_pMgr;
};

NS_WALKBIN_END