//
//  MenuLayer.h
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_MenuLayer_H
#define CatchMaster_MenuLayer_H

#include "cocos2d.h"

#include "../Scene/WeaponView.h"
#include "../Scene/SettingScene.h"
#include "../Scene/HighScoreScene.h"
#include "../Scene/HelpScene.h"

USING_NS_CC;

class MenuLayer : public Layer
{
public:
    
    // in there you must add your Code in here.
    virtual bool init();
    
    // a selector callback     
    void menuStartCallback(Ref* pSender);
    
    void menuSettingCallback(Ref* pSender);
    
    void menuHighScroreCallback(Ref* pSender);
    
    void menuHelpCallback(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(MenuLayer);
};

#endif // CatchMaster_MenuLayer_H

