//
//  TargetTouchScene.cpp
//  test
//
//  Created by ren zhen on 13-7-24.
//
//
#include "TargetTouchScene.h"
#include "SimpleAudioEngine.h"
#include "KillingLight.h"
#include "Ball.h"

using namespace cocos2d;
using namespace CocosDenshion;


CCScene* TargetTouchScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    TargetTouchScene *layer = TargetTouchScene::create();
	
    // add layer as a child to scene
    scene->addChild(layer);
	
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TargetTouchScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

	//////////////////////////////
    // 2. add title label
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	std::string title = "精灵测试";
	CCLabelTTF *pLabel = CCLabelTTF::create(title.c_str(),"Thonburi",30);

	pLabel->setPosition(ccp(size.width/2,size.height*0.9f));

	this->addChild(pLabel,1);


	//////////////////////////////
    // 3. add sprite item
    KillingLight* sprite = KillingLight::create("killer.png");
	
    this->addChild(sprite, 0);

	sprite->setPosition(ccp(240, 160));
	
	//1.生成动画数据  
	CCTexture2D* cache = CCTextureCache::sharedTextureCache()->addImage("killer.png");
	CCArray *arry=new CCArray();

	CCSpriteFrame *frame;
	for(int i=0;i<9;i++)
	{
		frame = CCSpriteFrame::createWithTexture(cache, *new CCRect((8 - i)*32,0,32,134));
		arry->addObject(frame);
	}

	CCAnimation *animation=CCAnimation::createWithSpriteFrames(arry,0.05f);
	animation->createWithSpriteFrames(arry);
	
	CCAnimate *animate;
	animate	= CCAnimate::create(animation);
	
//	CCRepeatForever *repeat=  CCRepeatForever::create( static_cast<CCSequence *>(CCSequence::create(animate, animate->reverse(), NULL)) );
	CCRepeatForever *repeat=  CCRepeatForever::create( (CCActionInterval*)(CCSequence::create(animate, animate->reverse(), NULL)) );	
	
	sprite->runAction(repeat);
	
	//////////////////////////////
    // 3. add ball item
	
	int ballIndex=0;
	for(int i=0;i<BALL_COUNT;i++)
	{
		if(getBallStateByIndex(i))
		{
			Ball* ball = Ball::create("ababall.png");
			ball->m_index=i;
			this->addChild(ball, 1);
			ball->setPosition(getBallPositionByIndex(i));
			g_arrayBall[ballIndex++]=ball;
		}
	}

 /*
	Ball* ball = Ball::create("ababall.png");
    this->addChild(ball, 1);

	CCPoint vPosition = CCDirector::sharedDirector()->getVisibleOrigin();
	CCSize vSize = CCDirector::sharedDirector()->getVisibleSize();
	ball->setPosition(ccp((vSize.width-vPosition.x)/2, (vSize.height-vPosition.y)/2));	
*/
	return true;
}

void TargetTouchScene::registerWithTouchDispatcher(void)
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, INT_MIN+1, true);
}

/*
void TargetTouchScene::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
	
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
*/