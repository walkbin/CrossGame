/********************************************************************
	文件名: 	TacLanguageMan.cpp
	作者:		chuckey.tang
	创建时间:	12:12:2012   19:18
	
	说明:		
*********************************************************************/
//project
#include "Base/TacLanguageMan.h"

// libxml2
#include <libxml/parser.h>

// cocos2d
#include "platform/CCFileUtils.h"

TacLanguageMan::TacLanguageMan(void)
	:m_nCurLanguage(TacLangEn)
{
}

TacLanguageMan::~TacLanguageMan(void)
{
}

bool TacLanguageMan::init(int curLan)
{
	m_nCurLanguage = curLan;
	xmlDocPtr doc;   //定义解析文档指针
	xmlNodePtr curNode;  //定义结点指针(你需要它为了在各个结点间移动)
	std::string str = cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename("nf_conf_language.xml");
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
			m_mapLanguages[id][TacLangEn] = (const char*)xmlGetProp(propNodePtr,BAD_CAST"english");
		}

		if (xmlHasProp(propNodePtr,BAD_CAST"chinese"))
		{
			m_mapLanguages[id][TacLangCh] = (const char*)xmlGetProp(propNodePtr,BAD_CAST"chinese");
		}

		if (xmlHasProp(propNodePtr,BAD_CAST"japanese"))
		{
			m_mapLanguages[id][TacLangJp] = (const char*)xmlGetProp(propNodePtr,BAD_CAST"japanese");
		}

		curNode = curNode->next;
	}

	CC_SAFE_FREE(pBuffer);
	xmlFreeDoc(doc);
	return true;
}

std::string TacLanguageMan::findTxt(int id)
{
	return findTxt(id, m_nCurLanguage);
}

std::string TacLanguageMan::findTxt(std::string englishTxt)
{
	return findTxt(englishTxt, m_nCurLanguage);
}

std::string TacLanguageMan::findTxt(int id, int language)
{
	NFLanMap::iterator i = m_mapLanguages.find(id);
	if(i == m_mapLanguages.end())
		return "";

	if(!isLangSupported(language))
		return "";

	return (i->second.find(language))->second;
}

std::string TacLanguageMan::findTxt(std::string englishTxt, int language)
{
	// 先简单查找，等后期优化 !!! #issue 00001
	for(NFLanMap::iterator i=m_mapLanguages.begin(); i!=m_mapLanguages.end(); i++)
	{
		if(englishTxt == i->second.find(TacLangEn)->second)
			return i->second.find(language)->second;
	}
	return "";
}

bool TacLanguageMan::isLangSupported(int language) const
{
	// 程序代码的支持
	if(language < TacLangEn || language >= TacLangNum)
		return false;
	return true;
}