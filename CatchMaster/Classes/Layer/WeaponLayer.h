//
//  WeaponLayer.h
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_WeaponLayer_H
#define CatchMaster_WeaponLayer_H

#include "cocos2d.h"
#include "../Scene/GameScene.h"

#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class WeaponLayer : public LayerColor
{
public:
    
    // in there you must add your Code in here.
    virtual bool init();
    
    // a selector callback     
    void menuCallback(Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(WeaponLayer);
    
    void onTouchEvent(Ref *ref, Widget::TouchEventType touchType);
    
    void textFieldEvent(Ref *pSender, TextField::EventType type);
    
    void addLayer();
    
    Menu* pMenu ;
    
    void doPop(Ref* pSender);
    
    void doNotification(Ref* obj);
};

#endif // CatchMaster_WeaponLayer_H

