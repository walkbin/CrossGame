/********************************************************************
	文件名: 	TacControlButtonLoader.h
	作者:		chuckey.tang
	创建时间:	12:12:2012   19:17
	
	说明:		
*********************************************************************/
#pragma once

// cocos2d
#include "ccbreader\CCControlButtonLoader.h"

USING_NS_CC;
USING_NS_CC_EXT;

class TacControlButtonLoader :
	public CCControlButtonLoader
{
public:
	CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TacControlButtonLoader, loader);

	TacControlButtonLoader(void);
	virtual ~TacControlButtonLoader(void);

	virtual void onHandlePropTypeString(CCNode * pNode, CCNode * pParent, const char * pPropertyName, const char * pString, CCBReader * pCCBReader);
};

