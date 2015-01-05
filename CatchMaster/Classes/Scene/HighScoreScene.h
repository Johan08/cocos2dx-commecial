//
//  HighScoreScene.h
//  CatchMaster
//
//  Created by sxz on 2015/01/01.
//  Copyright 2015年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_HighScoreScene_H
#define CatchMaster_HighScoreScene_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "../Layer/HighScoreLayer.h"

using namespace cocos2d;
using namespace CocosDenshion;

class HighScoreScene : public Scene {
public:
    
    virtual bool init();

    CREATE_FUNC(HighScoreScene);
};

#endif
