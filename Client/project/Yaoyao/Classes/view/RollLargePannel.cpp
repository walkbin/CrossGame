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

	created:	2013/03/25
	filename: 	RollLargePannel.cpp
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#include "RollLargePannel.h"

NS_WALKBIN_BEGIN

RollLargePannel::RollLargePannel()
{
    for (size_t i = 0; i < m_aTxts.size(); i++)
    {
        m_aTxts[i] = NULL;
    }
}

RollLargePannel::~RollLargePannel()
{
    for (size_t i = 0; i < m_aTxts.size(); i++)
    {
        CC_SAFE_RELEASE(m_aTxts[i]);
    }
}

void RollLargePannel::onEnter()
{
    RollPannel::onEnter();
    setb2World();
    setIsClockwise(true);
    setMotionParam(2.0f,1.0f,10.0f);
}

bool RollLargePannel::onAssignCCBMemberVariable( CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode )
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mTxt1",CCLabelTTF*,m_aTxts[0]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mTxt2",CCLabelTTF*,m_aTxts[1]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mTxt3",CCLabelTTF*,m_aTxts[2]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mTxt4",CCLabelTTF*,m_aTxts[3]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mTxt5",CCLabelTTF*,m_aTxts[4]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mTxt6",CCLabelTTF*,m_aTxts[5]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mLarge",CCSprite*,m_pSprite);
    return false;
}

NS_WALKBIN_END