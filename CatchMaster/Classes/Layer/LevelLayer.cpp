//
//  LevelLayer.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#include "LevelLayer.h"

// on "init" you need to initialize your instance
bool LevelLayer::init()
{
    /////////////////////////////////////////
    // 1.super init first
    if ( !Layer::init() )
    {
	return false;
    }

    //Welcome Message
    Size windowSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
    auto label = LabelTTF::create("LevelLayer", "Arial", 24);
    label->setPosition(windowSize.width / 2, windowSize.height / 2);
    this->addChild(label);

    return true;
}

