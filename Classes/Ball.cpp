//
//  Ball.cpp
//  test
//
//  Created by ren zhen on 14-5-8.
//
//

#include "Ball.h"

Ball* g_arrayBall[5];

// 列排序，从下向上
bool arrayState[BALL_COUNT]={
true,true,true,true,false,false,true
};

int arrayX[1] = {
500
};

int arrayY[BALL_COUNT] = {
60,120,180,240,300,360,420
};

CCPoint g_arrayBallPosition [BALL_COUNT]={
ccp(arrayX[0],arrayY[0]),ccp(arrayX[0],arrayY[1]),ccp(arrayX[0],arrayY[2]),ccp(arrayX[0],arrayY[3]),
ccp(arrayX[0],arrayY[4]),ccp(arrayX[0],arrayY[5]),ccp(arrayX[0],arrayY[6])
};

void touchBall(unsigned int ballIndex)
{
	bool isIgnore=false;
	switch (ballIndex)
	{
	case 6:
		arrayState[6]=false;
		arrayState[5]=true;
		break;
	case 5:
		arrayState[6]=true;
		arrayState[5]=false;
		break;
	case 4:
		arrayState[4]=false;
		arrayState[3]=true;
		arrayState[2]=true;
		arrayState[1]=true;
		arrayState[0]=true;
		break;
	case 3:
		arrayState[4]=true;
		arrayState[3]=false;
		arrayState[2]=true;
		arrayState[1]=true;
		arrayState[0]=true;
		break;
	case 2:
		arrayState[4]=true;
		arrayState[3]=true;
		arrayState[2]=false;
		arrayState[1]=true;
		arrayState[0]=true;
		break;
	case 1:
		arrayState[4]=true;
		arrayState[3]=true;
		arrayState[2]=true;
		arrayState[1]=false;
		arrayState[0]=true;
		break;
	case 0:
		arrayState[4]=true;
		arrayState[3]=true;
		arrayState[2]=true;
		arrayState[1]=true;
		arrayState[0]=false;
		break;
	default:
		isIgnore=true;
	}
	if(isIgnore)
	{
		return;
	}
	// update balls position
	int index=0;
	for(int i=0;i<BALL_COUNT;i++)
	{
		if(arrayState[i])
		{
			g_arrayBall[index]->m_index=i;
			g_arrayBall[index]->setPosition(getBallPositionByIndex(i));
			index++;
		}
	}
}

bool getBallStateByIndex(unsigned int ballIndex)
{
	unsigned int index=0;
	if(ballIndex<BALL_COUNT)
	{
		index=ballIndex;
	}
	return arrayState[index];
}

CCPoint getBallPositionByIndex(unsigned int ballIndex)
{
	unsigned int index=0;
	if(ballIndex<BALL_COUNT)
	{
		index=ballIndex;
	}

	CCPoint p =g_arrayBallPosition[index];
	return p;	
}


//using namespace cocos2d;

Ball* Ball::create(const char *pszFileName)
{
    Ball *pobSprite = new Ball();
    if (pobSprite && pobSprite->initWithFile(pszFileName))
    {
        pobSprite->autorelease();
		
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

bool Ball::ccTouchBegan(CCTouch* touch, CCEvent* event)
{

    CCPoint sLocalPos = convertToNodeSpace(touch->getLocation());
    CCRect sRC = CCRect(getPositionX() - getContentSize().width * getAnchorPoint().x,
						getPositionY() - getContentSize().height * getAnchorPoint().y,
						getContentSize().width, getContentSize().height);
    
    
    sRC.origin = CCPointZero;
    bool isTouched = sRC.containsPoint(sLocalPos);
    if(isTouched)
    {
        //CCLog("点中了!! x:%d y:%d", (int)sLocalPos.x, (int)sLocalPos.y);
		CCLog("点中 [%d]", this->m_index);
		touchBall( this->m_index);
		return true;
    }
    else
    {
       // CCLog("没点中了!! x:%d y:%d", (int)sLocalPos.x, (int)sLocalPos.y);
        return false;
    }
}

void Ball::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
    CCSprite::onEnter();
}

void Ball::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    CCSprite::onExit();
}

