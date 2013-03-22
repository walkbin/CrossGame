/********************************************************************
	文件名: 	TacControlButtonLoader.cpp
	作者:		chuckey.tang
	创建时间:	12:12:2012   19:18
	
	说明:		
*********************************************************************/
// project
#include "Base\TacConfig.h"
#include "Base\TacControlButtonLoader.h"
#include "Base\TacLanguageMan.h"

#define PROPERTY_TITLE_NORMAL "title|1"
#define PROPERTY_TITLE_HIGHLIGHTED "title|2"
#define PROPERTY_TITLE_DISABLED "title|3"

TacControlButtonLoader::TacControlButtonLoader(void)
{
}

TacControlButtonLoader::~TacControlButtonLoader(void)
{
}

void TacControlButtonLoader::onHandlePropTypeString(CCNode * pNode, CCNode * pParent, const char * pPropertyName, const char * pString, CCBReader * pCCBReader)
{
	std::string strStr = TacLanguageMan::instance().findTxt(pString);
	const char *convertedStr = strStr.c_str();
	if(strcmp(pPropertyName, PROPERTY_TITLE_NORMAL) == 0) {
		((CCControlButton *)pNode)->setTitleForState(CCString::create(convertedStr), CCControlStateNormal);
	} else if(strcmp(pPropertyName, PROPERTY_TITLE_HIGHLIGHTED) == 0) {
		((CCControlButton *)pNode)->setTitleForState(CCString::create(convertedStr), CCControlStateHighlighted);
	} else if(strcmp(pPropertyName, PROPERTY_TITLE_DISABLED) == 0) {
		((CCControlButton *)pNode)->setTitleForState(CCString::create(convertedStr), CCControlStateDisabled);
	} else {
		CCControlLoader::onHandlePropTypeString(pNode, pParent, pPropertyName, pString, pCCBReader);
	}
}