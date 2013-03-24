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
	filename: 	UIMgr.h
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#pragma once

#include "config/Global.h"
#include <vector>
#include <string>

#define UI_SEND_MSG(_msg) walkbin::UIManager::instance()->sendMsg(_msg)
#define UI_POST_MSG(_msg) walkbin::UIManager::instance()->postMsg(_msg)
#define UI_CACHE_IMG(_path) walkbin::UIManager::instance()->cacheImg(_path)

namespace walkbin
{
    class BaseScene;

    enum UINotify
    {
        UI_NOTIFY_BEGIN,

        UI_NOTIFY_FRESH_CALL_NUM,
        UI_NOTIFY_FRESH_RANK,
        UI_NOTIFY_ROUND_OVER,//Ò»¾Ö½áÊø
        UI_NOTIFY_PICK_PROP,
        UI_NOTIFY_CLEAR_PROP,
        UI_NOTIFY_PROP_POWER,
        UI_NOTIFY_WATERMARK_BORN,
        UI_NOTIFY_WATERMARK_DIED,
        UI_NOTIFY_SWITCH_COOLDOWN,
        UI_NOTIFY_SWITCH_STORE,
        UI_NOTIFY_SWITCH_NORMAL,
        UI_NOTIFY_GET_MONEY,

        UI_NOTIFY_END
    };

    typedef enum
    {
        UI_NONE,
        //full screen layers
        UI_LOADING,
        UI_LOGIN,
        UI_ROOM,
        UI_SELECT_CARD,
        UI_1_CARD,
        UI_2_CARDS,
        UI_RESULT,
        //add new full screen layer here if you want
        UI_FULL_SCR_LAYER_MAX = 0xffff,

        //small screen layers
        UI_LOGIN_BOARD = UI_FULL_SCR_LAYER_MAX + 1,
        UI_SIGNUP_BOARD_FB,
        UI_SIGNUP_BOARD,
        UI_PROFILE,
        UI_PROFILE_SETTING,
        UI_HEAD_SELECT,
        UI_PASSWORD,
        UI_STAR_SELECET,
        UI_CHAT,
        UI_WARNING,
        UI_SYS_LOADING,
        UI_DAILY_BONUS,
        UI_ROOM_UNLOCK,
        UI_LEVEL_UP,
        UI_STORE,
        UI_SETTING,
        UI_WAITING_BOARD,
        UI_RULE,
        UI_HELP,
        UI_PUBLICNOTICE,
        UI_BUYPOWERBALLDETAIL,
        //add new small screen layer here if you want
        UI_LAYER_MAX
    }UILayer;

    enum UIAction
    {
        UI_ADD,
        UI_DELETE,
        UI_UPDATE,
    };

    struct UIMsg
    {
        UIAction action;
        UILayer layer;
        void* pSender;
        std::string str;
        int exParam;
        SEL_CallFuncO param1;
        SEL_CallFuncO param2;

        UIMsg(UILayer l){layer = l;};
        UIMsg(UIAction a,UILayer l)
        {
            action = a; 
            layer = l;
            exParam = 0;
            pSender = NULL;
            str.assign("default");
            param1 = param2 = NULL;
        }

        UIMsg(UINotify notify,void* param,UIAction a = UI_UPDATE,UILayer l = UI_FULL_SCR_LAYER_MAX)
        {
            action = a;
            exParam = (int)notify;
            pSender = param;
            layer = UI_FULL_SCR_LAYER_MAX;
        }
    };

    class UIManager : public cocos2d::CCObject
    {
    public:
        static UIManager* instance();
        static void killInstance();

        virtual bool init();
        BaseScene* getScene(){return m_pScene;}
        void sendMsg(UIMsg msg);
        void postMsg(UIMsg msg);
        ~UIManager();
        CCTexture2D* cacheImg(const char* path);
        void clearImgCache();

    protected:
        UIManager();
        virtual void update(float dt);
        const char* getFileNameById(UILayer layerId);
        cocos2d::CCNode* parseCCBI(const char* fileName);
        cocos2d::CCNode* parseCCBI(UILayer id);
        bool addUI(UIMsg msg);
        bool deleteUI(UIMsg msg);
        bool updateUI(UIMsg msg);
        UILayer getCurUI();
        bool isFullScrUINeedBg(UILayer layerId);
        void dealMsg(UIMsg msg);
        void  tryDealMsg();
        void syncUI();

    private:
        static UIManager* s_ui_mgr;
        cocos2d::CCScheduler* m_pScheduler;
        BaseScene* m_pScene;
        std::vector<UILayer> m_vLayers;
        std::vector<UIMsg> m_vMsg;
        int m_nGameState;
        UILayer m_nCurFullScrLayer;
    };
}