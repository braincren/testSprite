//
//  TargetTouchScene.h
//  test
//
//  Created by ren zhen on 13-7-24.
//
//
#ifndef __TARGETTOUCH_SCENE_H__
#define __TARGETTOUCH_SCENE_H__

#include "cocos2d.h"

class TargetTouchScene : public cocos2d::CCLayer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
	
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
	
	// a selector callback
 //   void menuCloseCallback(CCObject* pSender);
	virtual void registerWithTouchDispatcher(void);
	
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(TargetTouchScene);
};


#endif /* __TARGETTOUCH_SCENE_H__ */
