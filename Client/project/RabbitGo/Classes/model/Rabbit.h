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

	created:	2013/03/19
	filename: 	Rabbit.h
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#pragma once

#include "config/Global.h"

class Hole;

enum ActionType
{
    ACTION_ENTER_HOLE,
    ACTION_SHOW,
    ACTION_HITTED,
    ACTION_GOBACK,
};

enum RabbitType
{
    RABBIT_WHITE,
    RABBIT_BLUE,

    RABBIT_MAX
};

class Rabbit : public CCObject
{
public:
    Rabbit();
    ~Rabbit();

    bool selectHole(Hole hole);
    bool setAction(ActionType action);

private:
    int m_nSpeed;
    ActionType m_nAction;
    RabbitType m_nType;
};