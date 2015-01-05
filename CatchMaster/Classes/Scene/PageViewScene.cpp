//
//  PageViewScene.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/27.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.

#include "PageViewScene.h"

// on "init" you need to initiallize your instance
bool PageViewScene::init()
{
    //初期化
    if ( !Scene::init() ) return false;
    
    // PageViewLayerを追加
    auto layer = PageViewLayer::create();
    this->addChild(layer);
    
    return true;
}

