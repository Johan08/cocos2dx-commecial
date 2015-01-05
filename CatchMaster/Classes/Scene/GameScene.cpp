//
//  GameScene.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/21.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#include "GameScene.h"

// on "init" you need to initiallize your instance
bool GameScene::init()
{
    // 1. super init first
    if (Scene::initWithPhysics())
    {
        this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
        
        auto gameLayer = GameLayer::create();
        if (gameLayer)
        {
            gameLayer->setPhyWorld(this->getPhysicsWorld());
            //gameLayer->setDelegator(statusLayer);
            this->addChild(gameLayer);
        }
        
//        auto menuItemLayer = MenuItemLayer::create();
//        if (menuItemLayer)
//        {
//            this->addChild(menuItemLayer);
//        }
//        menuItemLayer->setVisible(false);
//        menuItemLayer->setTag(1002);
        
        g_screenLog->attachToScene(this);
        
        return true;
        
    } else
    {
        return false;
    }
}

void GameScene::restart()
{

}