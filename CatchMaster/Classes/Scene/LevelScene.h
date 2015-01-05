//
//  LevelScene.h
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_LevelScene_H
#define CatchMaster_LevelScene_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

class LevelScene : public Scene {
public:
    
    virtual bool init();

    CREATE_FUNC(LevelScene);
    
    void onEnter() override;
};

#endif
