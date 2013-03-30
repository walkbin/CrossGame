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

	created:	2013/03/25
	filename: 	RollPannel.cpp
	author:		Richie.Wang@walkbin
	
	purpose:	
*********************************************************************/
#include "RollPannel.h"

NS_WALKBIN_BEGIN

RollPannel::RollPannel()
:m_pWorld(NULL)
,m_pSprite(NULL)
,m_fSpeed(0)
,m_bClockwise(true)
,m_fAccelerationUp(0)
,m_fAccelerationDown(0)
,m_fTopVelocity(0)
,m_bStartRollUp(false)
,m_bStartRollDown(false)
{

}

RollPannel::~RollPannel()
{
    CC_SAFE_RELEASE(m_pSprite);
    CC_SAFE_DELETE(m_pWorld);
}

void RollPannel::startRoll()
{
    if(m_bStartRollUp || m_bStartRollDown)
        return;

    m_bStartRollUp = true;
    m_bStartRollDown = false;
}

void RollPannel::stopRoll()
{
    m_bStartRollUp = false;
}

void RollPannel::onEnter()
{
    BaseLayer::onEnter();
    scheduleUpdate();
}

void RollPannel::setb2World()
{
    m_pWorld = new b2World(b2Vec2(0.0f, -10.0f));  //创建b2世界
    m_pWorld->SetAllowSleeping(true);//设置可否睡眠
    m_pWorld->SetContinuousPhysics(true);//可持续物理效应

    m_fRTMRatio = 64.0f;

    b2Body* ground = NULL;
    b2BodyDef bd;
    ground = m_pWorld->CreateBody(&bd);

    bd.type = b2_dynamicBody;
    bd.position.Set(this->getPositionX()/m_fRTMRatio, this->getPositionY()/m_fRTMRatio);  
    bd.userData = this;
    b2Body* ball = m_pWorld->CreateBody(&bd);

    b2CircleShape shape;
    shape.m_radius = m_pSprite->getContentSize().width/m_fRTMRatio;
    ball->CreateFixture(&shape,1.0f);

    b2RevoluteJointDef jd;
    jd.bodyA = ground;
    jd.bodyB = ball;
    jd.localAnchorA.Set(this->getPositionX()/m_fRTMRatio, this->getPositionY()/m_fRTMRatio);
    jd.localAnchorB.Set(0.0f, 0.0f);
    jd.referenceAngle = 0.0f;
    jd.motorSpeed = m_fSpeed * b2_pi;
    jd.maxMotorTorque = 1e8f;
    jd.enableMotor = true;
    m_pJoint = (b2RevoluteJoint*)m_pWorld->CreateJoint(&jd);
}

void RollPannel::update( float delta )
{
    if(!m_pWorld)
        return;

    m_pWorld->Step(delta, 2, 2);  
    for(b2Body *b = m_pWorld->GetBodyList(); b; b=b->GetNext()) 
    {   
        if (b->GetUserData() != NULL)
        {
            RollPannel *ballData = (RollPannel *)b->GetUserData();  
            ballData->setPosition(ccp(b->GetPosition().x * m_fRTMRatio, b->GetPosition().y * m_fRTMRatio));  
            ballData->setRotation( (m_bClockwise ? 1 : -1) * CC_RADIANS_TO_DEGREES(b->GetAngle()));

            //改变速度
            if(m_bStartRollUp && m_fSpeed < m_fTopVelocity)
            {
                m_fSpeed += m_fAccelerationUp*delta;
                if(m_fSpeed > m_fTopVelocity)
                {
                    m_bStartRollUp = false;
                    m_bStartRollDown = true;
                }
            }
            else if(m_bStartRollDown && m_fSpeed > 0)
            {
                m_fSpeed -= m_fAccelerationDown*delta;
                if(m_fSpeed < 0)
                {
                    m_fSpeed = 0;
                    setSpeed(0);
                    m_bStartRollDown = false;
                }
            }

            if(m_bStartRollUp || m_bStartRollDown)
                setSpeed(m_fSpeed);
        }   
    } 
}

void RollPannel::setSpeed( float speed )
{
    m_fSpeed = speed;
    m_pJoint->SetMotorSpeed(m_fSpeed*b2_pi);
}

float RollPannel::getSpeed()
{
    return m_fSpeed;
}

void RollPannel::setIsClockwise( bool flag )
{
    m_bClockwise = flag;
}

void RollPannel::setMotionParam(float aUp,float aDown,float vTop)
{
    m_fAccelerationUp = aUp;
    m_fAccelerationDown = aDown;
    m_fTopVelocity = vTop;
}


NS_WALKBIN_END