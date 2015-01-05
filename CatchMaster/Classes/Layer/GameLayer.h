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

#include <cstdlib>
#include "time.h"

#include "../Sprite/BugSprite.h"
#include "../Sprite/ButtonSprite.h"

#include "../Scene/MenuView.h"

USING_NS_CC;
using namespace std;
using namespace CocosDenshion;

const int BUG_RADIUS = 15;

class GameLayer : public Layer
{
   public:
    
   virtual bool init();

   void menuSuspendCallback(Ref* pSender);
    
   void menuSuspendCloseCallback(Ref* pSender);
    
   void menuReturnMainCallback(Ref* pSender);
    
    /**
     *  @author shixinzhu
     *
     *  创建一个抛物线动作
     *
     *  @param t          时间
     *  @param startPoint 开始点
     *  @param endPoint   结束点
     *  @param height     高度 影响抛物线的高度
     *  @param angle      角度 贝塞尔曲线两个控制点与y轴的夹角，直接影响精灵的抛出角度
     *  @return
     */
    static EaseInOut* create(float t, Point startPoint, Point endPoint, float height = 0, float angle = 60);

    CREATE_FUNC(GameLayer);
    
    /**
     * This layer need physical engine work
     */
    void setPhyWorld(PhysicsWorld* world) { this->world = world; }
    
    void update(float time);
    
private:
    
    PhysicsWorld* world;
    
    Sprite* suspendBackground;
    
    Sprite* mosquito;
    
    Menu* pauseMenu;
    
    MotionStreak* pStreak;  //インスタンスをメンバ変数として用意
    Point         position; //MotionStreakの位置
    
    Node* groundNode;
    
    bool onContactBegin(PhysicsContact& contact);
};

#endif  // CatchMaster_GameLayer_H