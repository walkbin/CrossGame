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
#include "RollLargePannel.h"
#include "RollSmallPannel.h"

NS_WALKBIN_BEGIN

LayerMain::LayerMain()
:m_pLargePanel(NULL)
,m_pSmallPanel(NULL)
,m_pBtnStart(NULL)
{

}

LayerMain::~LayerMain()
{
    CC_SAFE_RELEASE(m_pLargePanel);
    CC_SAFE_RELEASE(m_pSmallPanel);
    CC_SAFE_RELEASE(m_pBtnStart);
}

void LayerMain::onEnter()
{
    BaseLayer::onEnter();
}

bool LayerMain::onAssignCCBMemberVariable( CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode )
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mLarge",RollLargePannel*,m_pLargePanel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mSmall",RollSmallPannel*,m_pSmallPanel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mBtn",CCControlButton*,m_pBtnStart);
    return false;
}

cocos2d::extension::SEL_CCControlHandler LayerMain::onResolveCCBCCControlSelector( CCObject * pTarget, const char * pSelectorName )
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this,"onStartClicked",LayerMain::onBtnStartClicked);
    return NULL;
}

void LayerMain::onBtnStartClicked(CCObject* pSender, CCControlEvent event)
{
    m_pLargePanel->startRoll();
    m_pSmallPanel->startRoll();
}

NS_WALKBIN_END