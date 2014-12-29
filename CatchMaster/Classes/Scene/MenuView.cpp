//
//  MenuView.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#include "MenuView.h"

// on "init" you need to initiallize your instance
bool MenuView::init()
{
    //////////////////////////////////////
    // 1. super init first
    if ( !Scene::init() ) 
    {
        return false;
    }
    
    auto layer = MenuLayer::create();
    
    this->addChild(layer);

    return true;
}
