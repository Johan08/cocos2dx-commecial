//
//  GameLayer.h
//  CatchMaster
//
//  Created by sxz on 2014/12/22.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_GameLayer_H
#define CatchMaster_GameLayer_H

#include "cocos2d.h"
#include "CCActionInterval.h"  //包含系统延时类动作头文件
#include <cstdlib>
#include "time.h"

#include "../Sprite/BugSprite.h"
#include "../Sprite/ButtonSprite.h"


USING_NS_CC;
using namespace std;
using namespace CocosDenshion;

#define min(X, Y) ((X) < (Y) ? (X) : (Y))
#define max(X, Y) ((X) > (Y) ? (X) : (Y))

const int BUG_RADIUS = 15;

typedef enum game_status {
  GAME_STATUS_READY = 1,
  GAME_STATUS_START,
  GAME_STATUS_OVER
} GameStatus;

class StatusDelegate {
 public:
  /**
   * When the game start, this method will be called
   */
  virtual void onGameStart(void) = 0;

  /**
   * During paying, after the score changed, this method will be called
   */
  virtual void onGamePlaying(int score) = 0;

  /**
   * When game is over, this method will be called
   */
  virtual void onGameEnd(int curSocre, int bestScore) = 0;

  /**
   * アクションの初期化を行う。
   * durationは必須で、あとは指定したいパラメータを入れる感じですね
   * ちなみにこれは正確にはオーバーライドじゃなく、
   * 単に初期化を行うメソッドであるとわかりやすく統一させるだけです。
   */
  bool initWithDuration(float duration, ...);
  /**
   *  コピーする際に必要
   */
  virtual CCObject* copyWithZone(CCZone* pZone);
  /**
   * CCNode::runAction()時に呼び出されるメソッドみたいです。
   * ここでCCNodeのパラメーターの取得などを行います
   * 例：CCPoint pos = pTarget->getPosition();
   */
  virtual void startWithTarget(CCNode* pTarget);
  /**
   * アクションの実行中の動作を記載します。
   * float time は0〜1.0の間で変化していきます(0=開始 1=終了)
   */
  virtual void update(float time);
  /**
   * reverseさせたい場合に必要。
   * 必要ない場合はオーバーライドしなくてもいいみたいです。
   */
  virtual ActionInterval* reverse();
};

class GameLayer : public Layer {
 public:
  // in there you must add your Code in here.
  virtual bool init();

  // a selector callback
  void menuCallback(Ref* pSender);

  // implement the "static create()" method manually
  CREATE_FUNC(GameLayer);

  /**
   * This layer need physical engine work
   */
  void setPhyWorld(PhysicsWorld* world) { this->world = world; }

  virtual void update(float dt);

  // void update(float delta);

 private:
  PhysicsWorld* world;

  BugSprite* bug;
    
  ButtonSprite* buttonSprite;
    
  //  pause button
  //Sprite *pauseButton;

 private:
  MotionStreak* m_pStreak;  //インスタンスをメンバ変数として用意
  Point m_pos;              //MotionStreakの位置
};

#endif  // CatchMaster_GameLayer_H
