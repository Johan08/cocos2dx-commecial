//
//  LoadingScene.h
//  CatchMaster
//
//  Created by sxz on 2014/12/21.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_LoadingScene_H
#define CatchMaster_LoadingScene_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

class LoadingScene : public Scene
{
public:
    
    virtual bool init();

    CREATE_FUNC(LoadingScene);
    
    void onEnter() override;
};

#endif
