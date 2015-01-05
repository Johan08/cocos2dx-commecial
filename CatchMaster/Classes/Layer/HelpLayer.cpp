//
//  HelpLayer.cpp
//  CatchMaster
//
//  Created by sxz on 2015/01/01.
//  Copyright 2015年 hibiya.tech@gmail.com . All rights reserved.
//

#include "HelpLayer.h"

bool HelpLayer::init()
{
    /////////////////////////////////////////
    // 1.super init first
    if ( !Layer::init() ) return false;

    //Welcome Message
    Size windowSize = Director::getInstance()->getVisibleSize();
    Vec2 origin     = Director::getInstance()->getVisibleOrigin();
    
    auto background = Sprite::create("help_background.png");
    background->setAnchorPoint(Point::ZERO);
    background->setPosition(Vec2(0, 40));
    background->setScale(windowSize.width / background->getBoundingBox().size.width,
                         (windowSize.height - 40)/ background->getBoundingBox().size.height);
    this->addChild(background, 0);

    auto closeButton = Sprite::create("exit.png");
    auto menuCloseItem  = MenuItemSprite::create(closeButton, closeButton, NULL,CC_CALLBACK_1(HelpLayer::menuCallback, this));
    menuCloseItem->setPosition(Vec2(270, 40 + 19));
    
    auto menu = Menu::create(menuCloseItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    return true;
}

void HelpLayer::menuCallback(Ref* pSender)
{
    auto scene = MenuView::create();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}