//
//  WelcomeLayer.h
//  CatchMaster
//
//  Created by sxz on 2014/12/21.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_WelcomeLayer_H
#define CatchMaster_WelcomeLayer_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "../Scene/GameScene.h"

USING_NS_CC;
using namespace CocosDenshion;

// const int START_BUTTON_TAG = 100;
class WelcomeLayer : public Layer {
 public:
  // in there you must add your Code in here.
  virtual bool init();

  // implement the "static create()" method manually
  CREATE_FUNC(WelcomeLayer);

 private:
  // a selector callback
  void menuCallback(Ref* pSender);
};

#endif  // CatchMaster_WelcomeLayer_H
