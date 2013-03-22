/********************************************************************
	文件名: 	TacLabelTTFLoader.cpp
	作者:		chuckey.tang
	创建时间:	12:12:2012   19:18
	
	说明:		
*********************************************************************/
// project
#include "Base\TacConfig.h"
#include "Base\TacLabelTTFLoader.h"
#include "Base\TacLanguageMan.h"

#define PROPERTY_STRING "string"

TacLabelTTFLoader::TacLabelTTFLoader(void)
{
}

TacLabelTTFLoader::~TacLabelTTFLoader(void)
{
}

void TacLabelTTFLoader::onHandlePropTypeText(CCNode * pNode, CCNode * pParent, const char * pPropertyName, const char * pText, CCBReader * pCCBReader)
{
	if(strcmp(pPropertyName, PROPERTY_STRING) == 0) 
	{
		// 这里需要根据默认的英文版搜索系统对应语言的版本
		((CCLabelTTF *)pNode)->setString(TacLanguageMan::instance().findTxt(pText).c_str());
	} 
	else 
	{
		CCNodeLoader::onHandlePropTypeText(pNode, pParent, pPropertyName, pText, pCCBReader);
	}
}