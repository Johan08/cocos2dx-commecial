//
//  MenuItemLayer.h
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_MenuItemLayer_H
#define CatchMaster_MenuItemLayer_H

#include "cocos2d.h"
#include <ui/CocosGUI.h>

USING_NS_CC;
using namespace ui;

class MenuItemLayer : public Layer
{
public:
    
    // in there you must add your Code in here.
    virtual bool init();
    
    // a selector callback     
    //void menuCallback(Ref* pSender);
    
    void gamePause(Ref* pSender);
    
    void settings(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(MenuItemLayer);
};

#endif // CatchMaster_MenuItemLayer_H

