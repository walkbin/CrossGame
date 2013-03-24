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
	filename: 	UIMgr.cpp
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#include "UIMgr.h"
#include "base/NodeLoaderLibrary.h"
#include "base/BaseScene.h"
#include "base/BaseLayer.h"

#include "model/MainLogic.h"

#include "view/LayerLogo.h"
#include "view/LayerLoading.h"

NS_WALKBIN_BEGIN

UIMgr::UIMgr()
    :m_pScheduler(CCDirector::sharedDirector()->getScheduler())
    ,m_pScene(NULL)
    ,m_nCurFullScrLayer(UI_NONE)
    ,m_pLogic(NULL)
{
}

UIMgr::~UIMgr()
{
}

bool UIMgr::init()
{
    bool ret = false;

    m_pScheduler->scheduleSelector(schedule_selector(UIMgr::update),this,0.05f,false);
    if(!m_pScene)
    {
        m_pScene = BaseScene::create();
        if(m_pScene)
            ret = true;
    }
    return ret;
}

bool UIMgr::addUI(UIMsg msg)
{
    if(!m_vLayers.empty() && msg.view == m_vLayers.back())
        return false;

    if(msg.view < UI_FULL_SCR_LAYER_MAX)
    {
        m_pScene->removeAllChildrenWithCleanup(true);
        m_vLayers.clear();
        m_vMsg.clear();
        m_nCurFullScrLayer = msg.view;
    }
    else
    {
        //BaseLayer
        CCNode* pNode = (CCNode*)m_pScene->getChildren()->lastObject();
        ((BaseLayer*)pNode)->setCouldTouch(false);
    }

    //add ccbi layer
    CCNode* pNode = parseCCBI(msg.view);
    m_pScene->addChild(pNode,m_pScene->getChildrenCount());
    m_vLayers.push_back(msg.view);
    return true;
}

bool UIMgr::deleteUI(UIMsg msg)
{
    std::vector<UIView>::iterator it = std::find(m_vLayers.begin(), m_vLayers.end(), msg.view);
    if (it == m_vLayers.end())
        return false;

    if(*it == m_vLayers.back())
    {
        m_vLayers.pop_back();
        m_pScene->removeChild((CCNode*)(m_pScene->getChildren()->lastObject()));
        CCNode* pNode = (CCNode*)m_pScene->getChildren()->lastObject();
        ((BaseLayer*)pNode)->setCouldTouch(true);
        return true;
    }
    else
    {
        //»ñµÃidx
        std::vector<UIView>::iterator it2;
        int idx = 0;

        for (it2 = m_vLayers.begin(); it2 != m_vLayers.end(); it2++,idx++)
        {
            if(it2 == it)
                break;
        }

        m_vLayers.erase(it);
        m_pScene->removeChild((CCNode*)(m_pScene->getChildren()->objectAtIndex(idx)));
        return true;
    }
}

bool UIMgr::updateUI( UIMsg msg )
{
    CCArray* pa = m_pScene->getChildren();
    size_t cnts = pa->count();
    BaseLayer* pLayer = NULL;
    for (size_t i = 0; i < cnts; i++)
    {
        pLayer = dynamic_cast<BaseLayer*>(pa->objectAtIndex(i));
        if(pLayer)
        {
            pLayer->dealNotify(msg.exParam,msg.pSender);
        }
    }
    return true;
}

UIView UIMgr::getCurUI()
{
    if(m_vLayers.empty())
        return UI_NONE;
    else
        return m_vLayers.back();
}

void UIMgr::update( float dt )
{
    CC_UNUSED_PARAM(dt);
    syncUI();
    tryDealMsg();
}

CCNode* UIMgr::parseCCBI( const char* fileName )
{
    if(!fileName)
        return NULL;

    NodeLoaderLibrary * ccNodeLoaderLibrary = NodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    if(!ccNodeLoaderLibrary)
        return NULL;

    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    CCNode * node = ccbReader->readNodeGraphFromFile(fileName, this);
    ccbReader->release();
    return node;
}

cocos2d::CCNode* UIMgr::parseCCBI( UIView id )
{
    return parseCCBI(getFileNameById(id));
}

const char* UIMgr::getFileNameById( UIView layerId )
{
    switch (layerId)
    {
    case UI_LOGO:
        return "logolayer.ccbi";
    case UI_LOADING:
        return "LoadingScene.ccbi";
    default:
        CCAssert(1,"UIManager::getFileNameById");
        return NULL;
    }
}

void UIMgr::sendMsg( UIMsg msg )
{
    dealMsg(msg);
}

void UIMgr::postMsg( UIMsg msg )
{
    m_vMsg.push_back(msg);
}

void UIMgr::dealMsg( UIMsg msg )
{
    switch (msg.action)
    {
    case UI_ADD:
        addUI(msg);
        break;
    case UI_DELETE:
        deleteUI(msg);
        break;
    case UI_UPDATE:
        updateUI(msg);
        break;
    default:
        CCAssert(0,"<><><>wrong ui message");
        break;
    }
}

void UIMgr::tryDealMsg()
{
    if(m_vMsg.empty())
        return;

    UIMsg msg = m_vMsg.front();
    dealMsg(msg);
    m_vMsg.erase(m_vMsg.begin());
}

void UIMgr::syncUI()
{
    int gameState = (int)m_pLogic->getState();
    if(m_nGameState == gameState)
        return;

    switch (gameState)
    {
    case STATE_LOGO:
        addUI(UIMsg(UI_LOGO));
        break;
    case STATE_LOADING:
        addUI(UIMsg(UI_LOADING));
        break;
    default:
        break;
    }

    m_nGameState = gameState;
}

CCTexture2D* UIMgr::cacheImg( const char* path )
{
    return CCTextureCache::sharedTextureCache()->addImage(path);
}

void UIMgr::clearImgCache()
{
    CCTextureCache::purgeSharedTextureCache();
}

void UIMgr::bindLogic( MainLogic* pLogic )
{
    CCAssert(pLogic,"");
    m_pLogic = pLogic;
}

NS_WALKBIN_END