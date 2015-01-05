//
//  GameLayer.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/22.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#include "GameLayer.h"

bool GameLayer::init()
{
    if (!Layer::init()) return false;

    // Welcome Message
    Size visiableSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // screen background
    auto screenBackground = Sprite::create("screen_background.png");
    screenBackground->setAnchorPoint(Point::ZERO);
    screenBackground->setPosition(Vec2(0, 0));
    this->addChild(screenBackground);
    
    // sprite ⇨ mosquito
    mosquito = Sprite::create("mosquito.png");
    mosquito->setPosition(Vec2(30, visiableSize.height - 300));
    mosquito->setScale(0.1 * ( visiableSize.width / mosquito->getBoundingBox().size.width));
    this->addChild(mosquito);
    
    //bug->runAction(this->create(6, bug->getPosition(), Vec2(visiableSize.width - 30, visiableSize.height - 300), 100));
    mosquito->runAction(Spawn::create(RotateBy::create(5, 1080),
                                 this->create(5, mosquito->getPosition(),Vec2(visiableSize.width - 30, visiableSize.height - 300), 100), NULL));
    
   
    PhysicsBody *body = PhysicsBody::createCircle(BUG_RADIUS);
    body->addShape(PhysicsShapeCircle::create(BUG_RADIUS));
    body->setDynamic(true);
    body->setLinearDamping(0.0f);
    body->setGravityEnable(false);
    body->setMass(1.0f);
    body->setContactTestBitmask(0xFFFFFFFF);
    this->mosquito->setPhysicsBody(body);
    
    // ************************************************************************ //
    
    // MotionStreakを作成
    pStreak = MotionStreak::create(1.0, 1.0f, 3.0f, Color3B::GREEN, "suspend.png");
    addChild(pStreak);
    
    
    this->groundNode = Node::create();
    
    //イベントリスナー作成
    auto listener = EventListenerTouchOneByOne::create();
    
    //タッチ開始時
    listener->onTouchBegan = [this](Touch* touch, Event* event)
    {
        Point pos = this->convertTouchToNodeSpace(touch);
        this->pStreak->setPosition(pos);
        
        auto groundBody = PhysicsBody::createBox(Size(4, pos.y));
        groundBody->addShape(PhysicsShapeBox::create(Size(4, pos.y)));
        groundBody->setDynamic(false);
        groundBody->setLinearDamping(0.0f);
        groundBody->setMass(1.0f);
        groundBody->setContactTestBitmask(0xFFFFFFFF);
        
        this->groundNode->setPhysicsBody(groundBody);
        this->groundNode->setPosition(pos.x, pos.y);
        this->addChild(this->groundNode);
        
        return true;
    };
    
    //タッチ移動時
    listener->onTouchMoved = [this](Touch* touch, Event* event)
    {
        Point pos = this->convertTouchToNodeSpace(touch);
        this->pStreak->setPosition(pos);
    };
    
    //ディスパッチャに登録
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 100);
    
    // *************************************************************************************** //
    
    // sprite ⇨ suspend (init for invisible)
    suspendBackground = Sprite::create("suspend_background.png");
    suspendBackground->setAnchorPoint(Point::ZERO);
    suspendBackground->setPosition(Vec2(0, 0 + 40));
    suspendBackground->setScale(visiableSize.width / suspendBackground->getBoundingBox().size.width,
                               (visiableSize.height - 40)/ suspendBackground->getBoundingBox().size.height);
    suspendBackground->setTag(2009);
    suspendBackground->setVisible(false);
    this->addChild(suspendBackground);
    
    //进入暂停
    auto suspendBtn = Sprite::create("suspend.png");
    auto menuSuspendItem  = MenuItemSprite::create(suspendBtn, suspendBtn, NULL, CC_CALLBACK_1(GameLayer::menuSuspendCallback, this));
    menuSuspendItem->setPosition(Vec2(visiableSize.width - suspendBtn->getBoundingBox().size.width - 20,
                                      visiableSize.height - suspendBtn->getBoundingBox().size.height - 20));
    
    auto menu = Menu::create(menuSuspendItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 3);
    
    // suspend close button
    auto closeButton = Sprite::create("exit.png");
    MenuItem *menuCloseItem  = MenuItemSprite::create(closeButton, closeButton, NULL, CC_CALLBACK_1(GameLayer::menuSuspendCloseCallback, this));
    menuCloseItem->setPosition(Vec2(245, 128));
    
    pauseMenu = Menu::create( menuCloseItem, NULL);
    pauseMenu->setPosition(Point::ZERO);
    pauseMenu->setVisible(false);
    this->addChild(pauseMenu, 4);
    
    schedule(schedule_selector(GameLayer::update), 2.0f);
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameLayer::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    
    return true;
}

EaseInOut* GameLayer::create(float t, Point startPoint, Point endPoint, float height, float angle)
{
    // 把角度转换为弧度
    float radian = angle*3.14159/180.0;
    
    // 第一个控制点为抛物线左半弧的中点
    float q1x = startPoint.x + (endPoint.x - startPoint.x) / 4.0;
    auto q1 = Vec2(q1x, height + startPoint.y + cos(radian) * q1x);
    
    // 第二个控制点为整个抛物线的中点
    float q2x = startPoint.x + (endPoint.x - startPoint.x) / 2.0;
    auto q2 = Vec2(q2x, height + startPoint.y + cos(radian) * q2x);
    
    //曲线配置
    ccBezierConfig cfg;
    cfg.controlPoint_1 = q1;
    cfg.controlPoint_2 = q2;
    cfg.endPosition    = endPoint;
    
    //使用CCEaseInOut让曲线运动有一个由慢到快的变化，显得更自然
    return EaseInOut::create(BezierTo::create(t, cfg), 0.5);
}

void GameLayer::menuSuspendCallback(Ref* pSender)
{
    Director::getInstance()->pause();
    auto background = this->getChildByTag(2009);
    if (background)
    {
        background->setVisible(true);
    }
    
    pauseMenu->setVisible(true);
}

void GameLayer::menuSuspendCloseCallback(Ref* pSender)
{
    Director::getInstance()->resume();
    auto background = this->getChildByTag(2009);
    if (background)
    {
        background->setVisible(false);
    }
    
    pauseMenu->setVisible(false);
}

void GameLayer::menuReturnMainCallback(Ref* pSender)
{
    auto scene = MenuView::create();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}

bool GameLayer::onContactBegin(PhysicsContact& contact)
{
    //this->gameOver();
    
    g_screenLog->log(LL_ERROR, "onContactBegin");

    return true;
}


void GameLayer::update(float t)
{
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    log("current time: %04d-%02d-%02d %02d:%02d:%02d",
        timeinfo->tm_year + 1900,
        timeinfo->tm_mon  + 1,
        timeinfo->tm_mday,
        timeinfo->tm_hour,
        timeinfo->tm_min,
        timeinfo->tm_sec);
}