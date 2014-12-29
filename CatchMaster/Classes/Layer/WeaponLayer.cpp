//
//  WeaponLayer.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#include "WeaponLayer.h"

// on "init" you need to initialize your instance
bool WeaponLayer::init()
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
	
    auto label = LabelTTF::create("WeaponLayer", "Arial", 24);
    label->setPosition(windowSize.width / 2, windowSize.height / 2);
    this->addChild(label);
    
    Sprite *buttonNormal = Sprite::create("CloseNormal.png");
    Sprite *buttonClose  = Sprite::create("CloseSelected.png");
    
    auto menuItem  = MenuItemSprite::create(buttonNormal,buttonClose,NULL,CC_CALLBACK_1(WeaponLayer::menuCallback, this));
    menuItem->setPosition(Point(origin.x + windowSize.width/2 ,origin.y + windowSize.height*2/5));
    
    auto menu = Menu::create(menuItem, NULL);
    menu->setPosition(Point(origin.x ,origin.y));
    this->addChild(menu, 1);

    return true;
}

void WeaponLayer::menuCallback(Ref* pSender)
{
    auto scene = GameScene::create();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}

