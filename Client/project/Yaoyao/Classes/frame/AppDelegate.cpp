#include "AppDelegate.h"
#include <vector>
#include <string>

#include "config/AppMacros.h"
#include "controller/UIMgr.h"

USING_NS_CC;
using namespace std;
using namespace walkbin;

AppDelegate::AppDelegate()
    :m_pUIMgr(UIMgr::instance())
    ,m_pLangMgr(LangMgr::instance())
    ,m_pLogic(new MainLogic)
{
}

AppDelegate::~AppDelegate() 
{
    CC_SAFE_DELETE(m_pUIMgr);
    CC_SAFE_DELETE(m_pLangMgr);
    CC_SAFE_DELETE(m_pLogic);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
    // Set the design resolution
    pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
	CCSize frameSize = pEGLView->getFrameSize();
    vector<string> searchPath;

    // In this demo, we select resource according to the frame's height.
    // If the resource size is different from design resolution size, you need to set contentScaleFactor.
    // We use the ratio of resource's height to the height of design resolution,
    // this can make sure that the resource's height could fit for the height of design resolution.
    Resource  resourceInfo;

    if(1)
    {
        resourceInfo = mediumResource;
    }
    else
    {
        // if the frame's height is larger than the height of medium resource size, select large resource.
        if (frameSize.height > mediumResource.size.height)
            resourceInfo = largeResource;
        // if the frame's height is larger than the height of small resource size, select medium resource.
        else if (frameSize.height > smallResource.size.height)
            resourceInfo = mediumResource;
        // if the frame's height is smaller than the height of medium resource size, select small resource.
        else
            resourceInfo = smallResource;
    }
    searchPath.push_back(resourceInfo.directory);
    pDirector->setContentScaleFactor(MIN(resourceInfo.size.height/designResolutionSize.height, resourceInfo.size.width/designResolutionSize.width));
    // set searching path
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);
    // turn on display FPS
    pDirector->setDisplayStats(true);
    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
    // create a scene. it's an autorelease object
    CCScene *pScene = m_pUIMgr->getScene();
    // run
    m_pUIMgr->bindLogic(m_pLogic);
    pDirector->runWithScene(pScene);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
