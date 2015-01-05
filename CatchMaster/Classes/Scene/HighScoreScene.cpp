//
//  HighScoreScene.cpp
//  CatchMaster
//
//  Created by sxz on 2015/01/01.
//  Copyright 2015年 __MyCompanyName__. All rights reserved.
//

#include "HighScoreScene.h"

bool HighScoreScene::init()
{
    if ( !Scene::init() ) return false;

    auto layer = HighScoreLayer::create();
    this->addChild(layer);

    return true;
}
