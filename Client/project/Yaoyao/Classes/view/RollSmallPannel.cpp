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
	filename: 	RollSmallPannel.cpp
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#include "RollSmallPannel.h"

NS_WALKBIN_BEGIN

RollSmallPannel::RollSmallPannel()
{
    for (size_t i = 0; i < m_aTxts.size(); i++)
    {
        m_aTxts[i] = NULL;
    }
}

RollSmallPannel::~RollSmallPannel()
{
    for (size_t i = 0; i < m_aTxts.size(); i++)
    {
        CC_SAFE_RELEASE(m_aTxts[i]);
    }
}

bool RollSmallPannel::onAssignCCBMemberVariable( CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode )
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mTxt1",CCLabelTTF*,m_aTxts[0]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mTxt2",CCLabelTTF*,m_aTxts[1]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mTxt3",CCLabelTTF*,m_aTxts[2]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mTxt4",CCLabelTTF*,m_aTxts[3]);
    //CCB_MEMBERVARIABLEASSIGNER_GLUE(this,"mSmall",CCSprite*,m_pSprite);
    return false;
}

NS_WALKBIN_END