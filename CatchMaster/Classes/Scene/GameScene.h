//
//  GameScene.h
//  CatchMaster
//
//  Created by sxz on 2014/12/21.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_GameScene_H
#define CatchMaster_GameScene_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "../Layer/GameLayer.h"

using namespace cocos2d;
using namespace CocosDenshion;

class GameScene : public Scene {
public:
    
    virtual bool init();

    CREATE_FUNC(GameScene);
    
    void restart();
};

#endif
