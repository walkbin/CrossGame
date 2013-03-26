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
	filename: 	MainLogic.cpp
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#include "MainLogic.h"

NS_WALKBIN_BEGIN

MainLogic* MainLogic::s_pLogic = NULL;

MainLogic::MainLogic()
:m_nState(STATE_NONE)
{

}

MainLogic::~MainLogic()
{

}

bool MainLogic::init()
{
    return true;
}

LogicState MainLogic::getState()
{
    return m_nState;
}

void MainLogic::setState(LogicState state)
{
    if(m_nState == state)
        return;

    m_nState = state;

    switch (m_nState)
    {
    case STATE_NONE:
        break;
    case STATE_LOGO:
        CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(MainLogic::changeToLoading),this,2.0f,0,0,false);
        break;
    case STATE_LOADING:
        CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(MainLogic::changeToMain),this,2.0f,0,0,false);
        break;
    case STATE_MAIN:
        break;
    default:
        break;
    }
}

MainLogic* MainLogic::instance()
{
    if(!s_pLogic)
    {
        s_pLogic = new MainLogic;
        if(s_pLogic && s_pLogic->init())
        {
            return s_pLogic;
        }
        else
        {
            CC_SAFE_DELETE(s_pLogic);
            return NULL;
        }
    }

    return s_pLogic;
}

void MainLogic::killInstance()
{
    CC_SAFE_DELETE(s_pLogic);
}

void MainLogic::changeToLoading(float dt)
{
    setState(STATE_LOADING);
}

void MainLogic::changeToMain( float dt )
{
    setState(STATE_MAIN);
}



NS_WALKBIN_END