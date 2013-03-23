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
	filename: 	ControlButtonLoader.cpp
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#include "ControlButtonLoader.h"
#include "LangMgr.h"

#define PROPERTY_TITLE_NORMAL "title|1"
#define PROPERTY_TITLE_HIGHLIGHTED "title|2"
#define PROPERTY_TITLE_DISABLED "title|3"

USING_NS_CC;
USING_NS_CC_EXT;

namespace walkbin
{
    ControlButtonLoader::ControlButtonLoader(void)
    {
    }

    ControlButtonLoader::~ControlButtonLoader(void)
    {
    }

    void ControlButtonLoader::onHandlePropTypeString(CCNode * pNode, CCNode * pParent, const char * pPropertyName, const char * pString, CCBReader * pCCBReader)
    {
        std::string strStr = LangMgr::instance().findTxt(pString);
        const char *convertedStr = strStr.c_str();
        if(strcmp(pPropertyName, PROPERTY_TITLE_NORMAL) == 0) {
            ((CCControlButton *)pNode)->setTitleForState(CCString::create(convertedStr), CCControlStateNormal);
        } else if(strcmp(pPropertyName, PROPERTY_TITLE_HIGHLIGHTED) == 0) {
            ((CCControlButton *)pNode)->setTitleForState(CCString::create(convertedStr), CCControlStateHighlighted);
        } else if(strcmp(pPropertyName, PROPERTY_TITLE_DISABLED) == 0) {
            ((CCControlButton *)pNode)->setTitleForState(CCString::create(convertedStr), CCControlStateDisabled);
        } else {
            CCControlLoader::onHandlePropTypeString(pNode, pParent, pPropertyName, pString, pCCBReader);
        }
    }
}