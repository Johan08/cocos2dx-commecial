//
//  LevelScene.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#include "LevelScene.h"

//Scene* LevelScene::createScene()
//{
//    // 'scene' is an autorelease object
//    auto scene = Scene::create();
//    
//    // 'layer' is an autorelease object
//    auto layer = LevelScene::create();
//
//    // add layer as a child to scene
//    scene->addChild(layer);
//
//    // return the scene
//    return scene;
//}

// on "init" you need to initiallize your instance
bool LevelScene::init()
{
    //////////////////////////////////////
    // 1. super init first
    if ( !Scene::init() ) 
    {
        return false;
    }

    //Size visibleSize = Director::getInstance()->getVisibleSize();
    //Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add your code in here...

    return true;
}

void LevelScene::onEnter()
{

}
