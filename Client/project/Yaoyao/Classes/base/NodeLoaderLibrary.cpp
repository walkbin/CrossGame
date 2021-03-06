/********************************************************************
	文件名: 	TacNodeLoaderLibrary.cpp
	作者:		chuckey.tang
	创建时间:	12:12:2012   19:18
	
	说明:		
*********************************************************************/
#include "NodeLoaderLibrary.h"
#include "LabelBMFontLoader.h"
#include "LabelTTFLoader.h"
#include "ControlButtonLoader.h"

NS_WALKBIN_BEGIN

NodeLoaderLibrary::NodeLoaderLibrary(void)
{
}

NodeLoaderLibrary::~NodeLoaderLibrary(void)
{
}

void NodeLoaderLibrary::registerDefaultCCNodeLoaders()
{
    registerCCNodeLoader("CCLabelTTF", LabelTTFLoader::loader());
    registerCCNodeLoader("CCLabelBMFont", LabelBMFontLoader::loader());
    registerCCNodeLoader("CCControlButton", ControlButtonLoader::loader());

    CCNodeLoaderLibrary::registerDefaultCCNodeLoaders();
}

NS_WALKBIN_END