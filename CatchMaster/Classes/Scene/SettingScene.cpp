//
//  SettingScene.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#include "SettingScene.h"

// on "init" you need to initiallize your instance
bool SettingScene::init()
{
    //////////////////////////////////////
    // 1. super init first
    if ( !Scene::init() ) return false;
    
    auto layer = SettingLayer::create();

    this->addChild(layer);
    
    return true;
}

