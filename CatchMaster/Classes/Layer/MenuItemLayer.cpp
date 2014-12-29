//
//  MenuItemLayer.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#include "MenuItemLayer.h"

// on "init" you need to initialize your instance
bool MenuItemLayer::init()
{
    /////////////////////////////////////////
    // 1.super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    log(">>>>>>>> MenuItemLayer init...");
    
    //Welcome Message
    Size visiableSize = Director::getInstance()->getVisibleSize();
    Vec2 origin       = Director::getInstance()->getVisibleOrigin();

    Layout* layout = Layout::create();
    layout->setLayoutType(Layout::Type::VERTICAL);
    layout->setBackGroundColor(Color3B(67, 56, 128));
    layout->setBackGroundImage("background.png");
    
    layout->setAnchorPoint(Point::ZERO);
    layout->setContentSize(Size(160, 240));
    layout->setPosition(Vec2(visiableSize.width - 160, visiableSize.height - 240 - 10));
    this->addChild(layout, 0);
    
    auto button01 = Sprite::create("arrow01.png");
    button01->setAnchorPoint(Point::ZERO);
    //button01->setPosition(Vec2(layout->get .width / 2, layout->getSize().height / 2));
    layout->addChild(button01);
    
    return true;
}


void MenuItemLayer::gamePause(Ref* pSender)
{
    log("gamePause");
}

void MenuItemLayer::settings(Ref* pSender)
{
    log("settings");
}
