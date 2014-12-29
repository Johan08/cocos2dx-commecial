//
//  PageViewLayer.h
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_PageViewLayer_H
#define CatchMaster_PageViewLayer_H

#include "cocos2d.h"
#include <ui/CocosGUI.h>

#include "../Scene/MenuView.h"

using namespace cocos2d;
using namespace ui;

class PageViewLayer : public Layer
{
public:
    
    // in there you must add your Code in here.
    virtual bool init();
    
    // a selector callback     
    //void menuCallback(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(PageViewLayer);
    
    // pageview controller
    void pageviewCallBack(Ref * psender, PageViewEventType type);
};

#endif // CatchMaster_PageViewLayer_H

