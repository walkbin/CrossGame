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
	filename: 	Ground.h
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#pragma once
#include "config/Global.h"

class Hole;

typedef  std::map<CCPoint,Hole*> GROUD_HOLE_PAIR;

class Ground : public CCObject
{
public:
    Ground();
    ~Ground();

    //-1.0f~1.0f
    bool addHole(CCPoint pos);
    int getHoleCnts();
    const Hole* getHole(int idx);
    const Hole* getHole(CCPoint pos);

private:
    GROUD_HOLE_PAIR m_mHoles;
};