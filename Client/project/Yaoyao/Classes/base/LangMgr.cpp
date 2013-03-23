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
	filename: 	LangMgr.cpp
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#include "LangMgr.h"
#include <libxml/parser.h>
#include "platform/CCFileUtils.h"

namespace walkbin
{
    LangMgr::LangMgr(void)
        :m_nCurLanguage(LANG_EN)
    {
    }

    LangMgr::~LangMgr(void)
    {
    }

    bool LangMgr::init(int curLan)
    {
        m_nCurLanguage = curLan;
        xmlDocPtr doc;   //定义解析文档指针
        xmlNodePtr curNode;  //定义结点指针(你需要它为了在各个结点间移动)
        std::string str = cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename("internalString.xml");
        unsigned long size = 0;
        unsigned char* pBuffer = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(str.c_str(),"rb",&size);
        if(!pBuffer)
            return false;

        doc = xmlReadMemory((const char*)pBuffer,size,str.c_str(), "utf-8", 256);
        if (NULL == doc)
        {  
            CC_SAFE_FREE(pBuffer);
            return false; 
        }

        curNode = xmlDocGetRootElement(doc); //确定文档根元素

        if (NULL == curNode)
        { 
            //根节点不正确
            CC_SAFE_FREE(pBuffer);
            xmlFreeDoc(doc);
            return false;
        }

        if (xmlStrcmp(curNode->name, BAD_CAST"Lanuage"))			//建筑物的解析
        {
            //配置不正确
            CC_SAFE_FREE(pBuffer);
            xmlFreeDoc(doc);
            return false;
        }

        curNode = curNode->xmlChildrenNode;
        std::map<int, std::string> txtItem;

        while(curNode != NULL)
        {
            //取出节点中的内容
            if ((xmlStrcmp(curNode->name, BAD_CAST"Txt")))
            {
                curNode = curNode->next;
                continue;
            }

            xmlNodePtr propNodePtr = curNode;
            int id = atoi((const char*)xmlGetProp(propNodePtr,BAD_CAST"id"));
            if (xmlHasProp(propNodePtr,BAD_CAST"id"))
            {
                m_mapLanguages[id] = txtItem;
            }
            else
            {
                CC_SAFE_FREE(pBuffer);
                //必须要有的参数
                xmlFreeDoc(doc);
                return false;
            }

            if (xmlHasProp(propNodePtr,BAD_CAST"english"))
            {
                m_mapLanguages[id][LANG_EN] = (const char*)xmlGetProp(propNodePtr,BAD_CAST"english");
            }

            if (xmlHasProp(propNodePtr,BAD_CAST"chinese"))
            {
                m_mapLanguages[id][LANG_ZH_S] = (const char*)xmlGetProp(propNodePtr,BAD_CAST"chinese");
            }

            if (xmlHasProp(propNodePtr,BAD_CAST"japanese"))
            {
                m_mapLanguages[id][LANG_JPN] = (const char*)xmlGetProp(propNodePtr,BAD_CAST"japanese");
            }

            curNode = curNode->next;
        }

        CC_SAFE_FREE(pBuffer);
        xmlFreeDoc(doc);
        return true;
    }

    std::string LangMgr::findTxt(int id)
    {
        return findTxt(id, m_nCurLanguage);
    }

    std::string LangMgr::findTxt(std::string englishTxt)
    {
        return findTxt(englishTxt, m_nCurLanguage);
    }

    std::string LangMgr::findTxt(int id, int language)
    {
        LanMap::iterator i = m_mapLanguages.find(id);
        if(i == m_mapLanguages.end())
            return "";

        if(!isLangSupported(language))
            return "";

        return (i->second.find(language))->second;
    }

    std::string LangMgr::findTxt(std::string englishTxt, int language)
    {
        // 先简单查找，等后期优化 !!! #issue 00001
        for(LanMap::iterator i=m_mapLanguages.begin(); i!=m_mapLanguages.end(); i++)
        {
            if(englishTxt == i->second.find(LANG_EN)->second)
                return i->second.find(language)->second;
        }
        return "";
    }

    bool LangMgr::isLangSupported(int language) const
    {
        // 程序代码的支持
        if(language < LANG_EN || language >= LANG_MAX)
            return false;
        return true;
    }
}