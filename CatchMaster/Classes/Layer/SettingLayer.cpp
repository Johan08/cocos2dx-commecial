//
//  SettingLayer.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#include "SettingLayer.h"

// on "init" you need to initialize your instance
bool SettingLayer::init()
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

    auto background = Sprite::create("set_background.png");
    background->setAnchorPoint(Point::ZERO);
    background->setPosition(Vec2(0, 40));
    background->setScale(windowSize.width / background->getBoundingBox().size.width,
                         (windowSize.height - 40)/ background->getBoundingBox().size.height);
    this->addChild(background, 0);
    
    // set music on
    auto musicSwitch = Sprite::create(SaveData::loadBool("MUSIC_SWITH") ? "openMusic.png" : "closeMusic.png");
    musicSwitch->setAnchorPoint(Point::ZERO);
    musicSwitch->setPosition(Vec2(150, 300 - 5));
    this->addChild(musicSwitch);
    
    auto closeButton = Sprite::create("exit.png");
    auto menuCloseItem  = MenuItemSprite::create(closeButton, closeButton, NULL,CC_CALLBACK_1(SettingLayer::menuCallback, this));
    menuCloseItem->setPosition(Vec2(270, 40 + 19));
    
    auto menu = Menu::create(menuCloseItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    return true;
}

void SettingLayer::menuCallback(Ref* pSender)
{
    auto scene = MenuView::create();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}

