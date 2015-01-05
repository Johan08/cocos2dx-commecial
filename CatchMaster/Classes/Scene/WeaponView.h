//
//  WeaponView.h
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_WeaponView_H
#define CatchMaster_WeaponView_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "../Layer/WeaponLayer.h"

using namespace cocos2d;
using namespace CocosDenshion;

class WeaponView : public Scene
{
    public:
    
    virtual bool init();
    
    CREATE_FUNC(WeaponView);
};

#endif
