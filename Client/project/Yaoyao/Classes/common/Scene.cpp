/********************************************************************
	文件名: 	TacScene.cpp
	作者:		chuckey.tang
	创建时间:	12:12:2012   19:21
	
	说明:		
*********************************************************************/
//project
#include "../Base/TacScene.h"
#include "../Game/UI/BingoCard.h"

USING_NS_CC;
USING_NS_CC_EXT;

TacScene *TacScene::node()
{
	return TacScene::create();
}

TacScene *TacScene::create()
{
	TacScene *pRet = new TacScene();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		CC_SAFE_RELEASE(pRet);
		return NULL;
	}
}

TacScene::TacScene(void)
{
}

TacScene::~TacScene(void)
{
}

bool TacScene::init()
{
	if(!CCScene::init())
		return false;

	this->scheduleUpdate();
	return true;
}

void TacScene::update(float dt)
{
 	TacMainMsgHandler::instance().update();
	return CCScene::update(dt);
}