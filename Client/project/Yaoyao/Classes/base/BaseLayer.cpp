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
	filename: 	Layer.cpp
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#include "BaseLayer.h"

NS_WALKBIN_BEGIN

BaseLayer::BaseLayer()
{

}

BaseLayer::~BaseLayer()
{
    m_vMenualBtns.clear();
}

void BaseLayer::setCouldTouch(bool flag)
{
    BaseLayerInfo pAy[] = {BaseLayerInfo(this,false)};
    std::vector<BaseLayerInfo> vArray(pAy,pAy+1);
    setCouldTouchWithArray(vArray,flag);
}

void BaseLayer::setCouldTouchWithArray(std::vector<BaseLayerInfo> vArray,bool flag)
{
    if(vArray.empty())
        return;

    size_t len = vArray.size();

    for (size_t i = 0; i < len; i++)
    {
        CCAssert(vArray[i].pLayer,"layer valid");
        if(vArray[i].bIsBaseLayer == true)
        {
            ((BaseLayer*)(vArray[i].pLayer))->setCouldTouch(flag);
        }
        else
        {
            if(!flag)
            {
                if(vArray[i].pLayer->isTouchEnabled())
                {
                    vArray[i].pLayer->setTouchEnabled(false);
                    m_vMenualBtns.push_back(vArray[i].pLayer);
                }
            }
            else
            {
                std::vector<cocos2d::CCLayer*>::iterator it;
                for (it = m_vMenualBtns.begin(); it != m_vMenualBtns.end(); i++)
                {
                    if(*it == vArray[i].pLayer)
                        break;
                }

                if(it != m_vMenualBtns.end())
                {
                    (*it)->setTouchEnabled(true);
                    m_vMenualBtns.erase(it);
                }
            }
        }
    }
}

cocos2d::SEL_MenuHandler BaseLayer::onResolveCCBCCMenuItemSelector( cocos2d::CCObject * pTarget, const char * pSelectorName )
{
    CC_UNUSED_PARAM(pTarget);
    CC_UNUSED_PARAM(pSelectorName);
    return NULL;
}

cocos2d::extension::SEL_CCControlHandler BaseLayer::onResolveCCBCCControlSelector( cocos2d::CCObject * pTarget, const char * pSelectorName )
{
    CC_UNUSED_PARAM(pTarget);
    CC_UNUSED_PARAM(pSelectorName);
    return NULL;
}

bool BaseLayer::onAssignCCBMemberVariable( cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode )
{
    CC_UNUSED_PARAM(pTarget);
    CC_UNUSED_PARAM(pMemberVariableName);
    CC_UNUSED_PARAM(pNode);
    return false;
}

void BaseLayer::onNodeLoaded( cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader )
{
    CC_UNUSED_PARAM(pNodeLoader);
    CC_UNUSED_PARAM(pNode);
}

void BaseLayer::dealNotify( int notifyId,void* param )
{
    CC_UNUSED_PARAM(notifyId);
    CC_UNUSED_PARAM(param);
}

NS_WALKBIN_END