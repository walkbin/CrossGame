/********************************************************************
	created:	2013/01/24   13:58
	filename: 	TacLayer.cpp
	author:		richie.wang
	
	purpose:	
*********************************************************************/
#include "TacLayer.h"

TacLayer::TacLayer()
{

}

TacLayer::~TacLayer()
{
	m_vMenualBtns.clear();
}

void TacLayer::setCouldTouch(bool flag)
{
	TacLayerInfo pAy[] = {TacLayerInfo(this,false)};
	std::vector<TacLayerInfo> vArray(pAy,pAy+1);
	setCouldTouchWithArray(vArray,flag);
}

void TacLayer::setCouldTouchWithArray(std::vector<TacLayerInfo> vArray,bool flag)
{
	if(vArray.empty())
		return;

	size_t len = vArray.size();

	for (size_t i = 0; i < len; i++)
	{
        CCAssert(vArray[i].pLayer,"layer valid");
		if(vArray[i].bIsTacLayer == true)
		{
			((TacLayer*)(vArray[i].pLayer))->setCouldTouch(flag);
		}
		else
		{
			if(!flag)
			{
				if(vArray[i].pLayer->isTouchEnabled())
				{
					vArray[i].pLayer->setTouchEnabled(false);
					m_vMenualBtns.push_back(vArray[i].pLayer);
				}
			}
			else
			{
				std::vector<cocos2d::CCLayer*>::iterator it;
                for (it = m_vMenualBtns.begin(); it != m_vMenualBtns.end(); i++)
                {
                       if(*it == vArray[i].pLayer)
                           break;
                }
                
				if(it != m_vMenualBtns.end())
				{
					(*it)->setTouchEnabled(true);
					m_vMenualBtns.erase(it);
				}
			}
		}
	}
}

cocos2d::SEL_MenuHandler TacLayer::onResolveCCBCCMenuItemSelector( cocos2d::CCObject * pTarget, const char * pSelectorName )
{
	CC_UNUSED_PARAM(pTarget);
	CC_UNUSED_PARAM(pSelectorName);
	return NULL;
}

cocos2d::extension::SEL_CCControlHandler TacLayer::onResolveCCBCCControlSelector( cocos2d::CCObject * pTarget, const char * pSelectorName )
{
	CC_UNUSED_PARAM(pTarget);
	CC_UNUSED_PARAM(pSelectorName);
	return NULL;
}

bool TacLayer::onAssignCCBMemberVariable( cocos2d::CCObject * pTarget, const char * pMemberVariableName, cocos2d::CCNode * pNode )
{
	CC_UNUSED_PARAM(pTarget);
	CC_UNUSED_PARAM(pMemberVariableName);
	CC_UNUSED_PARAM(pNode);
	return false;
}

void TacLayer::onNodeLoaded( cocos2d::CCNode * pNode, cocos2d::extension::CCNodeLoader * pNodeLoader )
{
	CC_UNUSED_PARAM(pNodeLoader);
	CC_UNUSED_PARAM(pNode);
}

void TacLayer::dealNotify( int notifyId,void* param )
{
    CC_UNUSED_PARAM(notifyId);
    CC_UNUSED_PARAM(param);
}
