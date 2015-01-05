//
//  BugSprite.h
//  CatchMaster
//
//  Created by sxz on 2014/12/22.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_BugSprite_H
#define CatchMaster_BugSprite_H

#include "cocos2d.h"
#include <string>
#include <iostream>
#include <sstream>

USING_NS_CC;

using namespace std;

typedef enum{
    ACTION_STATE_IDLE,
    ACTION_STATE_FLY,
    ACTION_STATE_DIE
} ActionState;

const int BUG_SPRITE_TAG = 10003;

class BugSprite : public Sprite
{
public:
    
    BugSprite();
    
    ~BugSprite();
    
    static BugSprite* getInstance();
    
    bool virtual init();
    
    bool createBug();
    
    void idle();
    
    void fly();
    
    void die();
    
private:
    static BugSprite* shareBugSprite;
    /**
     * This method change current status. called by fly and idle etc.
     */
    bool changeState(ActionState state);
    
    Action* idleAction;
    
    Action* flyAction;
    
    Action* swingAction;
    
    ActionState currentStatus;
    
    string bugName;
    
    string bugNameFormat;
    
    //record the first time into the game.
    unsigned int isFirstTime;
};

#endif /* defined(CatchMaster_BugSprite_H) */
