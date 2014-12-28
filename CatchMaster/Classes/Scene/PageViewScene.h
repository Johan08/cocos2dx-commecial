//
//  PageViewScene.h
//  CatchMaster
//
//  Created by sxz on 2014/12/27.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_PageViewScene_H
#define CatchMaster_PageViewScene_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include <ui/CocosGUI.h>

#include "GameScene.h"

using namespace cocos2d;
using namespace ui;
using namespace CocosDenshion;

class PageViewScene : public Layer {
public:
    
     static Scene* createScene();
    
    virtual bool init();

    CREATE_FUNC(PageViewScene);
    
    void pageviewCallBack(Ref * psender, PageViewEventType type);
};

#endif
