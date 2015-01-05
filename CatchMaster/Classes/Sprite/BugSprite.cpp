//
//  BugSprite.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/22.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#include "BugSprite.h"

BugSprite* BugSprite::shareBugSprite = nullptr;

BugSprite::BugSprite() {}

BugSprite::~BugSprite() {}

BugSprite* BugSprite::getInstance()
{
    if(shareBugSprite == NULL)
    {
        shareBugSprite = new BugSprite();
        
        if(!shareBugSprite->init())
        {
            delete(shareBugSprite);
            shareBugSprite = NULL;
            CCLOG("ERROR: Could not init shareBugSprite");
        }
    }
    
    return shareBugSprite;
}

bool BugSprite::init()
{
    this->isFirstTime = 3;
    return true;
}

bool BugSprite::createBug()
{
   
    Animate* action;
    Animation* animation = Animation::create();
    animation->setRestoreOriginalFrame(false);
    
    Sprite *sprite = Sprite::create("arrow01.png");
    
    for(int i=1; i < 4; i++)
    {
        char szName[200] = {0};
        sprintf(szName, "arrow%02d.png", i);
        log("file%s", szName);
        animation->addSpriteFrameWithFileName(szName);
    }
    animation->setDelayPerUnit(1);// 延迟时间（秒）
    action = CCAnimate::create(animation);
    sprite->runAction(CCRepeatForever::create (action));
    return true;
}

void BugSprite::idle()
{
    if (changeState(ACTION_STATE_IDLE))
    {
        this->runAction(idleAction);
        this->runAction(swingAction);
    }
}

void BugSprite::fly()
{
    if(changeState(ACTION_STATE_FLY))
    {
        this->stopAction(swingAction);
        this->getPhysicsBody()->setGravityEnable(true);
    }
}

void BugSprite::die()
{
    if(changeState(ACTION_STATE_DIE))
    {
        this->stopAllActions();
    }
}

bool BugSprite::changeState(ActionState state)
{
    //this->stopAllActions();
    currentStatus = state;
    return true;
}

