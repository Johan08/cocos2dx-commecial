//
//  HelpScene.h
//  CatchMaster
//
//  Created by sxz on 2015/01/01.
//  Copyright 2015年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_HelpScene_H
#define CatchMaster_HelpScene_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "../Layer/HelpLayer.h"

using namespace cocos2d;
using namespace CocosDenshion;

class HelpScene : public Scene {
public:
    
    virtual bool init();

    CREATE_FUNC(HelpScene);
    
    //void onEnter() override;
};

#endif
