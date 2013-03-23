/********************************************************************
	文件名: 	TacNodeLoaderLibrary.h
	作者:		chuckey.tang
	创建时间:	12:12:2012   19:17
	
	说明:		
*********************************************************************/
#pragma once

// cocos2d
#include "ccbreader\ccnodeloaderlibrary.h"

USING_NS_CC_EXT;

class TacNodeLoaderLibrary :
	public CCNodeLoaderLibrary
{
public:
	CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TacNodeLoaderLibrary, library);
	static TacNodeLoaderLibrary * newDefaultCCNodeLoaderLibrary();

	TacNodeLoaderLibrary(void);
	virtual ~TacNodeLoaderLibrary(void);

	void registerDefaultCCNodeLoaders();
};

