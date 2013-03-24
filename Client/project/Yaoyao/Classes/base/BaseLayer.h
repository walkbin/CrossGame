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
	filename: 	Layer.h
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#pragma once

#include "config/Global.h"
#include <vector>

namespace walkbin
{
    struct BaseLayerInfo
    {
        CCLayer* pLayer;
        bool bIsBaseLayer;
        BaseLayerInfo(CCLayer* pl,bool b){pLayer = pl;bIsBaseLayer = b;}
    };

    class BaseLayer : public CCLayer
        , public CCBSelectorResolver
        , public CCBMemberVariableAssigner
        , public cocos2d::extension::CCNodeLoaderListener
    {
    public:
        BaseLayer();
        virtual ~BaseLayer();

        virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName);
        virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName);
        virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode);
        virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
        virtual void dealNotify(int notifyId,void* param);
        virtual void setCouldTouch(bool flag);
        void setCouldTouchWithArray(std::vector<BaseLayerInfo> vArray,bool flag);

    private:
        std::vector<CCLayer*> m_vMenualBtns;
    };
}