//
//  PopUpLayer.cpp
//  CatchMaster
//
//  Created by sxz on 2015/01/04.
//  Copyright 2015年 hibiya.tech@gmail.com . All rights reserved.
//

#include "PopUpLayer.h"

bool PopUpLayer::init()
{
    if ( !LayerColor::initWithColor(Color4B::GRAY) ) return false;
    
    String* popParam = String::create("0");
    NotificationCenter::getInstance()->postNotification("notification", popParam);   //노티피케이션 보내기
    winSize=Director::getInstance()->getWinSize();
    
    //메뉴추가
    MenuItemFont* pMenuItem = MenuItemFont::create("close", CC_CALLBACK_1(PopUpLayer::doClose, this));
    pMenuItem->setColor(Color3B::BLACK);
    Menu* pMenu2 = Menu::create(pMenuItem, NULL);
    pMenu2->setPosition(Vec2(240, 100));
    this->addChild(pMenu2,10);
    
    //backLayer추가
    backLayer = LayerColor::create(ccc4(0, 0, 0, 50), winSize.width, winSize.height);
    backLayer->setAnchorPoint(Vec2(0, 0));
    backLayer->setPosition(Vec2(0 ,0));
    this->addChild(backLayer);
    
    //popUpLayer추가
    popUpLayer = LayerColor::create(ccc4(255, 0, 0, 255), 250, 150);
    popUpLayer->setAnchorPoint(Vec2(0, 0));
    popUpLayer->setPosition(Vec2((winSize.width-popUpLayer->getContentSize().width)/2, (winSize.height-popUpLayer->getContentSize().height)/2));
    this->addChild(popUpLayer);
    
    return true;
}

void PopUpLayer::doClose(Ref* pSender)
{
    String* popParam = String::create("1");
    CCNotificationCenter::getInstance()->postNotification("notification", popParam);         //노티피케이션 보내기
    //팝업창 제거
    this->removeFromParentAndCleanup(true);
}
