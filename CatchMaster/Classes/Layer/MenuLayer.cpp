//
//  MenuLayer.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.

#include "MenuLayer.h"

/**
 <#Description#>
 */
bool MenuLayer::init()
{
    // 1.super init first
    if ( !Layer::init() ) return false;
    
    auto windowSize = Director::getInstance()->getVisibleSize();
    auto screenBackground = Sprite::create("menu_background.png");
    screenBackground->setAnchorPoint(Point::ZERO);
    screenBackground->setPosition(Vec2(0, 0 + 40));
    screenBackground->setScale(windowSize.width / screenBackground->getBoundingBox().size.width,
                         (windowSize.height - 40)/ screenBackground->getBoundingBox().size.height);
    this->addChild(screenBackground);
    
    //游戏进入
    auto start = Sprite::create("start.png");
    auto menuStartItem  = MenuItemSprite::create(start,start,NULL,CC_CALLBACK_1(MenuLayer::menuStartCallback, this));
    menuStartItem->setPosition(Vec2(150, 410 - 80));
    
    //进入排行榜
    auto scores = Sprite::create("scores.png");
    auto menuScoresItem  = MenuItemSprite::create(scores,scores,NULL,CC_CALLBACK_1(MenuLayer::menuHighScroreCallback, this));
    menuScoresItem->setPosition(Vec2(215,310 - 80));
    
    //游戏设置
    auto setting = Sprite::create("set.png");
    auto menuSettingItem  = MenuItemSprite::create(setting,setting,NULL,CC_CALLBACK_1(MenuLayer::menuSettingCallback, this));
    menuSettingItem->setPosition(Vec2(100, 300 - 80));
    
    //进入帮助
    auto help = Sprite::create("help.png");
    auto menuHelpItem  = MenuItemSprite::create(help,help,NULL,CC_CALLBACK_1(MenuLayer::menuHelpCallback, this));
    menuHelpItem->setPosition(Vec2(145, 225 - 80));
    
    auto menu = Menu::create(menuStartItem, menuScoresItem, menuSettingItem, menuHelpItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 2);
    
    return true;
}

/**
 *  @author shixinzhu
 *
 *  <#Description#>
 *
 *  @param pSender <#pSender description#>
 */
void MenuLayer::menuStartCallback(Ref* pSender)
{
    auto scene = WeaponView::create();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}

/**
 *  @author shixinzhu
 *
 *  <#Description#>
 *
 *  @param pSender <#pSender description#>
 */
void MenuLayer::menuSettingCallback(Ref* pSender)
{
    auto scene = SettingScene::create();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}

/**
 *  @author shixinzhu
 *
 *  <#Description#>
 *
 *  @param pSender <#pSender description#>
 */
void MenuLayer::menuHighScroreCallback(Ref* pSender)
{
    auto scene = HighScoreScene::create();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}

/**
 *  @author shixinzhu
 *
 *  <#Description#>
 *
 *  @param pSender <#pSender description#>
 */
void MenuLayer::menuHelpCallback(Ref* pSender)
{
    auto scene = HelpScene::create();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}