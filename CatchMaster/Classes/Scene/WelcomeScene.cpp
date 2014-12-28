//
//  WelcomeScene.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/21.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#include "WelcomeScene.h"
#include "../Layer/WelcomeLayer.h"

// on "init" you need to initiallize your instance
bool WelcomeScene::init()
{
    bool bRet = false;
    
    do {
          CC_BREAK_IF(!Scene::init());
          auto welcomeLayer = WelcomeLayer::create();
          CC_BREAK_IF(!welcomeLayer);
          this->addChild(welcomeLayer);
          bRet = true;
    } while (0);
    
    return bRet;
}

