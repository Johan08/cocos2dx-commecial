//
//  HelpScene.cpp
//  CatchMaster
//
//  Created by sxz on 2015/01/01.
//  Copyright 2015年 __MyCompanyName__. All rights reserved.
//

#include "HelpScene.h"

bool HelpScene::init()
{
    //////////////////////////////////////
    // 1. super init first
    if ( !Scene::init() ) return false;

    auto layer = HelpLayer::create();
    this->addChild(layer);
    
    return true;
}
