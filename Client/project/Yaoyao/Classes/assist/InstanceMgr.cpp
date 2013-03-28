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

	created:	2013/03/28
	filename: 	InstanceMgr.cpp
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#include "InstanceMgr.h"

NS_WALKBIN_BEGIN

LangMgr* InstanceMgr::langMgr = NULL;
LoaderHelper* InstanceMgr::loaderHelper = NULL;
UIMgr* InstanceMgr::uiMgr = NULL;
MainLogic* InstanceMgr::mainLogic = NULL;

void InstanceMgr::create()
{
    langMgr =             LangMgr::getInstance();
    loaderHelper =       LoaderHelper::getInstance();
    uiMgr =                 UIMgr::getInstance();
    mainLogic =          MainLogic::getInstance();
}

void InstanceMgr::destroy()
{
    LangMgr::freeInstance();
    LoaderHelper::freeInstance();
    UIMgr::freeInstance();
    MainLogic::freeInstance();
}

NS_WALKBIN_END