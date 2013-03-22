/********************************************************************
	文件名: 	TacScene.h
	作者:		chuckey.tang
	创建时间:	12:12:2012   19:21
	
	说明:		
*********************************************************************/
#pragma once

// cocos2d
#include "layers_scenes_transitions_nodes/CCScene.h"
#include "../Base/TacNodeLoaderLibrary.h"

// project
#include "LIB/TacHandler.h"
#include "LIB/TacActivity.h"

// boost
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>

class TacScene :
	public cocos2d::CCScene
{
protected:

public:
	CC_DEPRECATED_ATTRIBUTE static TacScene *node(void);
	static TacScene *create(void);

	TacScene(void);
	virtual ~TacScene(void);

	virtual bool init();
	virtual void update(float dt);
};