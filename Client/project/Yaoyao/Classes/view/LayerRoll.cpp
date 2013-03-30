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
	filename: 	LayerRoll.cpp
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#include "LayerRoll.h"
#include "controller/UIMgr.h"
#include "model/MainLogic.h"
#include "RollLargePannel.h"
#include "RollSmallPannel.h"


NS_WALKBIN_BEGIN

LayerRoll::LayerRoll()
:m_pLarge(NULL)
,m_pSmall(NULL)
{

}

LayerRoll::~LayerRoll()
{
    CC_SAFE_RELEASE(m_pLarge);
    CC_SAFE_RELEASE(m_pSmall);
}

bool LayerRoll::init()
{
    return true;
}

bool LayerRoll::onAssignCCBMemberVariable( CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode )
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mLarge",RollLargePannel*,m_pLarge);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mSmall",RollSmallPannel*,m_pSmall);
    return false;
}

void LayerRoll::startRoll()
{
    m_pLarge->startRoll();
    m_pSmall->startRoll();
}

NS_WALKBIN_END