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

namespace walkbin
{
    UIManager* UIManager::s_ui_mgr = NULL;

    UIManager* UIManager::instance()
    {
        if(!s_ui_mgr)
        {
            s_ui_mgr = new UIManager();
            if(!s_ui_mgr->init())
            {
                CC_SAFE_DELETE(s_ui_mgr);
            }
        }

        return s_ui_mgr;
    }

    void UIManager::killInstance()
    {
        CC_SAFE_DELETE(s_ui_mgr);
    }

    UIManager::~UIManager()
    {
        m_pScheduler->unscheduleSelector(schedule_selector(UIManager::update),this);
    }

    UIManager::UIManager()
        :m_pScheduler(CCDirector::sharedDirector()->getScheduler())
        ,m_pScene(NULL)
        //,m_nGameState(GAME_STATE_NONE)
        ,m_nCurFullScrLayer(UI_NONE)
    {

    }

    bool UIManager::init()
    {
        bool ret = false;

        m_pScheduler->scheduleSelector(schedule_selector(UIManager::update),this,0.05f,false);
        if(!m_pScene)
        {
            m_pScene = BaseScene::create();
            if(m_pScene)
                ret = true;
        }
        return ret;
    }

    bool UIManager::addUI(UIMsg msg)
    {
        if(!m_vLayers.empty() && msg.layer == m_vLayers.back())
            return false;

        if(msg.layer < UI_FULL_SCR_LAYER_MAX)
        {
            m_pScene->removeAllChildrenWithCleanup(true);
            m_vLayers.clear();
            m_vMsg.clear();
            m_nCurFullScrLayer = msg.layer;
        }
        else
        {
            //BaseLayer
            CCNode* pNode = (CCNode*)m_pScene->getChildren()->lastObject();
            ((BaseLayer*)pNode)->setCouldTouch(false);
        }

        //add ccbi layer
        CCNode* pNode = parseCCBI(msg.layer);
        m_pScene->addChild(pNode,m_pScene->getChildrenCount());
        m_vLayers.push_back(msg.layer);
        return true;
    }

    bool UIManager::deleteUI(UIMsg msg)
    {
        std::vector<UILayer>::iterator it = std::find(m_vLayers.begin(), m_vLayers.end(), msg.layer);
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
            //获得idx
            std::vector<UILayer>::iterator it2;
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

    bool UIManager::updateUI( UIMsg msg )
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

    UILayer UIManager::getCurUI()
    {
        if(m_vLayers.empty())
            return UI_NONE;
        else
            return m_vLayers.back();
    }

    void UIManager::update( float dt )
    {
        CC_UNUSED_PARAM(dt);
        syncUI();
        tryDealMsg();
    }

    CCNode* UIManager::parseCCBI( const char* fileName )
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

    cocos2d::CCNode* UIManager::parseCCBI( UILayer id )
    {
        return parseCCBI(getFileNameById(id));
    }

    const char* UIManager::getFileNameById( UILayer layerId )
    {
        switch (layerId)
        {
        case UI_LOADING:
            return "LoadingScene.ccbi";
        default:
            CCAssert(1,"UIManager::getFileNameById");
            return NULL;
        }
    }

    void UIManager::sendMsg( UIMsg msg )
    {
        dealMsg(msg);
    }

    void UIManager::postMsg( UIMsg msg )
    {
        m_vMsg.push_back(msg);
    }

    void UIManager::dealMsg( UIMsg msg )
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

    void UIManager::tryDealMsg()
    {
        if(m_vMsg.empty())
            return;

        UIMsg msg = m_vMsg.front();
        dealMsg(msg);
        m_vMsg.erase(m_vMsg.begin());
    }

    void UIManager::syncUI()
    {
        //int gameState = TacGameLogic::getInstance()->getState();
        //if(m_nGameState == gameState)
        //    return;
        ////这里要等待roomlayer的fadeout动画做完之后，才能切换界面
        //if(m_nGameState == GAME_STATE_ROOM_SELECT && gameState == GAME_STATE_SELECT_CARD)
        //{
        //    RoomLayer* pLayer = dynamic_cast<RoomLayer*>(m_pScene->getChildren()->objectAtIndex(0));
        //    if(pLayer && pLayer->ifInFadeOut())
        //        return;
        //}

        //switch (gameState)
        //{
        //case GAME_STATE_LOADING:
        //    addUI(UIMsg(UI_LOADING));
        //    break;
        //case GAME_STATE_LOADING_SUCCESS:
        //    addUI(UIMsg(UI_LOGIN));
        //    break;
        //case GAME_STATE_ROOM_SELECT:
        //    addUI(UIMsg(UI_ROOM));
        //    break;
        //case GAME_STATE_SELECT_CARD:
        //    addUI(UIMsg(UI_SELECT_CARD));
        //    break;
        //case GAME_STATE_GAME_RUNNING:
        //    if (TacGameLogic::getInstance()->getCardCount() == BINGO_GAME_1_CARD)
        //        addUI(UIMsg(UI_1_CARD));
        //    else
        //        addUI(UIMsg(UI_2_CARDS));
        //    break;
        //case GAME_STATE_GAME_OVER:
        //    addUI(UIMsg(UI_RESULT));
        //    break;
        //default:
        //    break;
        //}

        //m_nGameState = gameState;
    }

    bool UIManager::isFullScrUINeedBg( UILayer layerId )
    {
        return (layerId >= UI_SELECT_CARD && layerId <= UI_RESULT) ? true : false;
    }

    CCTexture2D* UIManager::cacheImg( const char* path )
    {
        return CCTextureCache::sharedTextureCache()->addImage(path);
    }

    void UIManager::clearImgCache()
    {
        CCTextureCache::purgeSharedTextureCache();
    }
}