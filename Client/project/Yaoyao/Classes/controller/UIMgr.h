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

#include <vector>
#include <string>
#include "base/BaseScene.h"

#define UI_SEND_MSG(_msg) walkbin::UIMgr::instance()->sendMsg(_msg)
#define UI_POST_MSG(_msg) walkbin::UIMgr::instance()->postMsg(_msg)
#define UI_CACHE_IMG(_path) walkbin::UIMgr::instance()->cacheImg(_path)

NS_WALKBIN_BEGIN

class MainLogic;

enum UINotify
{
    UI_NOTIFY_BEGIN,
    UI_NOTIFY_FRESH_CALL_NUM,
    UI_NOTIFY_END
};

typedef enum
{
    UI_NONE,
    //full screen layers
    UI_LOGO,
    UI_LOADING,
    UI_LOGIN,
    //add new full screen layer here if you want
    UI_FULL_SCR_LAYER_MAX = 0xffff,

    //small screen layers
    UI_LOGIN_BOARD = UI_FULL_SCR_LAYER_MAX + 1,
    //add new small screen layer here if you want
    UI_LAYER_MAX
}UIView;

enum UIAction
{
    UI_ADD,
    UI_DELETE,
    UI_UPDATE,
};

struct UIMsg
{
    UIAction action;
    UIView view;
    void* pSender;
    std::string str;
    int exParam;
    SEL_CallFuncO param1;
    SEL_CallFuncO param2;

    UIMsg(UIView l){view = l;};
    UIMsg(UIAction a,UIView l)
    {
        action = a; 
        view = l;
        exParam = 0;
        pSender = NULL;
        str.assign("default");
        param1 = param2 = NULL;
    }

    UIMsg(UINotify notify,void* param,UIAction a = UI_UPDATE,UIView l = UI_FULL_SCR_LAYER_MAX)
    {
        action = a;
        exParam = (int)notify;
        pSender = param;
        view = UI_FULL_SCR_LAYER_MAX;
    }
};

class UIMgr : public CCObject
{
public:

    static UIMgr* instance();
    static void killInstance();

    UIMgr();
    virtual ~UIMgr();

    virtual bool init();
    void bindLogic(MainLogic* pLogic);
    BaseScene* getScene(){return m_pScene;}
    void sendMsg(UIMsg msg);
    void postMsg(UIMsg msg);
    CCTexture2D* cacheImg(const char* path);
    void clearImgCache();

protected:
    virtual void update(float dt);
    const char* getFileNameById(UIView layerId);
    cocos2d::CCNode* parseCCBI(const char* fileName);
    cocos2d::CCNode* parseCCBI(UIView id);
    bool addUI(UIMsg msg);
    bool deleteUI(UIMsg msg);
    bool updateUI(UIMsg msg);
    UIView getCurUI();
    void dealMsg(UIMsg msg);
    void  tryDealMsg();
    void syncUI();

private:
    static UIMgr* s_pUIMgr;
    MainLogic* m_pLogic;
    cocos2d::CCScheduler* m_pScheduler;
    BaseScene* m_pScene;
    std::vector<UIView> m_vLayers;
    std::vector<UIMsg> m_vMsg;
    int m_nGameState;
    UIView m_nCurFullScrLayer;
};

NS_WALKBIN_END