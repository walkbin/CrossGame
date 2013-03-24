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
	filename: 	FileHelper.cpp
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#include "FileHelper.h"

xmlDocPtr walkbin::FileHelper::openXml( const char* filename )
{
    xmlDocPtr pDoc = NULL;

    std::string str = cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(filename);
    unsigned long size = 0;
    unsigned char* pBuffer = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(str.c_str(),"rb",&size);
    if(!pBuffer)
        return NULL;

    pDoc = xmlReadMemory((const char*)pBuffer,size,str.c_str(), "utf-8", 256);
    CC_SAFE_FREE(pBuffer);
    return pDoc;
}

bool walkbin::FileHelper::closeXml( xmlDocPtr pDoc )
{
    if(pDoc)
    {
        xmlFreeDoc(pDoc);
        return true;
    }

    return false;
}