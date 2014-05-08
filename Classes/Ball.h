//
//  Ball.h
//  test
//
//  Created by ren zhen on 14-5-8.
//
//

#ifndef __BALL_H__
#define __BALL_H__

#include "cocos2d.h"

using namespace cocos2d;

#define BALL_NUMBER 5
#define BALL_COUNT 7
CCPoint getBallPositionByIndex(unsigned int ballIndex);
bool getBallStateByIndex(unsigned int ballIndex);


class Ball : public cocos2d::CCSprite,public cocos2d::CCTouchDelegate
{
	
public:
    static Ball*  create(const char *pszFileName);
	
public:
    virtual void onEnter();
    virtual void onExit();

	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);

	unsigned int m_index;
/*
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
	void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	void ccTouchesBegin(CCSet *pTouches, CCEvent *pEvent);
*/
};

extern Ball* g_arrayBall[];

#endif /* defined(__Ball_H__) */
