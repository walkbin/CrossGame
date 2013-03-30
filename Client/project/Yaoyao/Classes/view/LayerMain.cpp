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

	created:	2013/03/24
	filename: 	LayerMain.cpp
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#include "LayerMain.h"
#include "LayerRoll.h"

NS_WALKBIN_BEGIN

LayerMain::LayerMain()
:m_pBtnStart(NULL)
,m_pRoll(NULL)
{

}

LayerMain::~LayerMain()
{
    CC_SAFE_RELEASE(m_pRoll);
    CC_SAFE_RELEASE(m_pBtnStart);
}

void LayerMain::onEnter()
{
    BaseLayer::onEnter();
}

bool LayerMain::onAssignCCBMemberVariable( CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode )
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mRoll",LayerRoll*,m_pRoll);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mBtnStart",CCControlButton*,m_pBtnStart);
    return false;
}

cocos2d::extension::SEL_CCControlHandler LayerMain::onResolveCCBCCControlSelector( CCObject * pTarget, const char * pSelectorName )
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this,"onStartClicked",LayerMain::onBtnStartClicked);
    return NULL;
}

void LayerMain::onBtnStartClicked(CCObject* pSender, CCControlEvent event)
{
    m_pRoll->startRoll();
}

void LayerMain::setCouldTouch( bool flag )
{
    BaseLayerInfo pAy[] = {BaseLayerInfo(this,false),
                                        BaseLayerInfo(m_pBtnStart,false)};
    std::vector<BaseLayerInfo> vArray(pAy,pAy+1);
    setCouldTouchWithArray(vArray,flag);
}

NS_WALKBIN_END