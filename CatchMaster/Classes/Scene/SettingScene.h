//
//  SettingScene.h
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_SettingScene_H
#define CatchMaster_SettingScene_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "../Layer/SettingLayer.h"


using namespace cocos2d;
using namespace CocosDenshion;

class SettingScene : public Scene {
public:
    
    virtual bool init();

    CREATE_FUNC(SettingScene);
};

#endif
