//
//  KillingLight.h
//  test
//
//  Created by ren zhen on 13-7-25.
//
//

#ifndef __KILLINGLIGHT_H__
#define __KILLINGLIGHT_H__

#include "cocos2d.h"

using namespace cocos2d;

class KillingLight : public cocos2d::CCSprite,public cocos2d::CCTouchDelegate
{
	
public:
    static KillingLight*  create(const char *pszFileName);
	
public:
    virtual void onEnter();
    virtual void onExit();

	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);

/*
	void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	void ccTouchesBegin(CCSet *pTouches, CCEvent *pEvent);
*/
};

#endif /* defined(__KILLINGLIGHT_H__) */
