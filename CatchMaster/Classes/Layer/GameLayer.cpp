//
//  GameLayer.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/22.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#include "GameLayer.h"
#include "CCActionInterval.h"

/**
 <#Description#>
 */
bool GameLayer::init() {
  /////////////////////////////////////////
  // 1.super init first
  if (!Layer::init()) {
    return false;
  }

  // Welcome Message
  //Size visiableSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  ///////////////////////////////////////////////////////////////////////////////

  // MotionStreakを作成
  m_pStreak = MotionStreak::create(1.0, 1.0f, 3.0f, Color3B::GREEN, "arrow01.png");
  addChild(m_pStreak);
    
   //CCLOGINFO("%s %d deallocing demo : %p", __FUNCTION__, __LINE__, this);

  //イベントリスナー作成
  auto listener = EventListenerTouchOneByOne::create();

  //タッチ開始時
  listener->onTouchBegan = [this](Touch* touch, Event* event) {
    Point pos = this->convertTouchToNodeSpace(touch);
    this->m_pStreak->setPosition(pos);
    return true;
  };

  //タッチ移動時
  listener->onTouchMoved = [this](Touch* touch, Event* event) {
    Point pos = this->convertTouchToNodeSpace(touch);
    this->m_pStreak->setPosition(pos);
  };

  //ディスパッチャに登録
  Director::getInstance()
      ->getEventDispatcher()
      ->addEventListenerWithFixedPriority(listener, 100);

  ////////////////////////////////////////////////////////////////////////////////////////////////

  Sprite* bug = Sprite::create("arrow01.png");

  bug->setPosition(Vec2(320, 400));  // Boss坐标
  this->addChild(bug);

  PointArray* bosspoints = PointArray::create(18);
  bosspoints->addControlPoint(Vec2(250, 380));
  bosspoints->addControlPoint(Vec2(350, 300));
  bosspoints->addControlPoint(Vec2(450, 350));
  bosspoints->addControlPoint(Vec2(500, 500));
  bosspoints->addControlPoint(Vec2(450, 350));
  bosspoints->addControlPoint(Vec2(350, 200));
  bosspoints->addControlPoint(Vec2(250, 350));
  bosspoints->addControlPoint(Vec2(150, 400));
  bosspoints->addControlPoint(Vec2(50, 450));
  bosspoints->addControlPoint(Vec2(150, 300));
  bosspoints->addControlPoint(Vec2(250, 480));
  bosspoints->addControlPoint(Vec2(150, 480));
  bosspoints->addControlPoint(Vec2(50, 480));
  bosspoints->addControlPoint(Vec2(150, 380));
  bosspoints->addControlPoint(Vec2(250, 380));
  bosspoints->addControlPoint(Vec2(350, 380));
  bosspoints->addControlPoint(Vec2(450, 380));
  bosspoints->addControlPoint(Vec2(350, 380));
  bosspoints->addControlPoint(Vec2(250, 380));

  //根据坐标组创建一个轨迹 三个参数是 移动一轮的时间,坐标组,浮张力(惯性)
  ActionInterval* bosslineTo = CardinalSplineTo::create(18, bosspoints, 0);

  //让boss执行这个行动 CCRepeatForever是一直执行
  bug->runAction(CCRepeatForever::create(bosslineTo));

  return true;
}

/**
 *  @author shixinzhu, 15-12-28 15:12:37
 *
 *  <#Description#>
 *
 *  @param dt <#dt description#>
 */
void GameLayer::update(float dt) {
  log(">>>>>>> update()");
  //１フレームごとに２px移動させる
  m_pos += Point(2.0, 0);
  m_pStreak->setPosition(m_pos);
}
