//
//  MenuView.h
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_MenuView_H
#define CatchMaster_MenuView_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

class MenuView : public Scene {
public:
    
    virtual bool init();

    CREATE_FUNC(MenuView);
    
    void onEnter() override;
};

#endif
