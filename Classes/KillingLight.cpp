//
//  KillingLight.cpp
//  test
//
//  Created by ren zhen on 13-7-25.
//
//

#include "KillingLight.h"

//using namespace cocos2d;

KillingLight* KillingLight::create(const char *pszFileName)
{
    KillingLight *pobSprite = new KillingLight();
    if (pobSprite && pobSprite->initWithFile(pszFileName))
    {
        pobSprite->autorelease();
		
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

bool KillingLight::ccTouchBegan(CCTouch* touch, CCEvent* event)
{

    CCPoint sLocalPos = convertToNodeSpace(touch->getLocation());
    CCRect sRC = CCRect(getPositionX() - getContentSize().width * getAnchorPoint().x,
						getPositionY() - getContentSize().height * getAnchorPoint().y,
						getContentSize().width, getContentSize().height);
    
    
    sRC.origin = CCPointZero;
    bool isTouched = sRC.containsPoint(sLocalPos);
    if(isTouched)
    {
        CCLog("点中了!! x:%d y:%d", (int)sLocalPos.x, (int)sLocalPos.y);
        return true;
    }
    else
    {
        CCLog("没点中了!! x:%d y:%d", (int)sLocalPos.x, (int)sLocalPos.y);
        return false;
    }
	

}

void KillingLight::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
	//CCPoint touchPoint = convertToNodeSpace(touch->getLocation());
	
	CCPoint location = touch->getLocationInView();
    CCPoint convertedLoation = CCDirector::sharedDirector()->convertToGL(location);
	
	this->setPosition( CCPointMake(convertedLoation.x, convertedLoation.y));
}

void KillingLight::ccTouchEnded(CCTouch* pTouch, CCEvent* event)
{

}

/*
void KillingLight::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{

}

void KillingLight::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{

}

void KillingLight::ccTouchesBegin(CCSet *pTouches, CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)( pTouches->anyObject() );
	
	CCPoint location = touch->getLocationInView();
	
	location = CCDirector::sharedDirector()->convertToGL(location);
	
	CCLOG("x=%d,y=%d",(int)location.x,(int)location.y);
	
}
*/
void KillingLight::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
    CCSprite::onEnter();
}

void KillingLight::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    CCSprite::onExit();
}

