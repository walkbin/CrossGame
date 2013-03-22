/********************************************************************
	created:	2013/01/24   13:49
	filename: 	TacLayer.h
	author:		richie.wang
	
	purpose:	
*********************************************************************/
#pragma once

#include "cocos2d.h"
#include "cocos-ext.h"
#include <vector>

USING_NS_CC;
USING_NS_CC_EXT;

struct TacLayerInfo
{
	CCLayer* pLayer;
	bool bIsTacLayer;
	TacLayerInfo(CCLayer* pl,bool b){pLayer = pl;bIsTacLayer = b;}
};

class TacLayer : public CCLayer
	, public CCBSelectorResolver
	, public CCBMemberVariableAssigner
	, public cocos2d::extension::CCNodeLoaderListener
{
public:
	TacLayer();
	virtual ~TacLayer();

	virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName);
	virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char * pSelectorName);
	virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode);
	virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    virtual void dealNotify(int notifyId,void* param);
	virtual void setCouldTouch(bool flag);
	void setCouldTouchWithArray(std::vector<TacLayerInfo> vArray,bool flag);

private:
	std::vector<CCLayer*> m_vMenualBtns;
};