//
//  WeaponView.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#include "WeaponView.h"

// on "init" you need to initiallize your instance
bool WeaponView::init()
{
    //////////////////////////////////////
    // 1. super init first
    if ( !Scene::init() ) 
    {
        return false;
    }

    auto layer = WeaponLayer::create();
    this->addChild(layer);
    
    return true;
}

