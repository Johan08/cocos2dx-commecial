//
//  LoadingScene.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/21.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#include "LoadingScene.h"
#include "WelcomeScene.h"

bool LoadingScene::init() {
  //////////////////////////////////////
  // 1. super init first
  if (!Scene::init()) {
    return true;
  }

  return true;
}

/**
 *  @author shixinzhu
 *
 *  <#Description#>
 */
void LoadingScene::onEnter() {
  Sprite *background = Sprite::create("splash.png");
  Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();
  background->setPosition(origin.x + visibleSize.width / 2,
                          origin.y + visibleSize.height / 2);
  this->addChild(background);
  auto scene = WelcomeScene::create();
  TransitionScene *transition = TransitionFade::create(1, scene);
  Director::getInstance()->replaceScene(transition);
}
