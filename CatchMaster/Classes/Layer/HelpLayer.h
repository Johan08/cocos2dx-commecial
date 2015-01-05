//
//  HelpLayer.h
//  CatchMaster
//
//  Created by sxz on 2015/01/01.
//  Copyright 2015年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_HelpLayer_H
#define CatchMaster_HelpLayer_H

#include "cocos2d.h"

#include "../Scene/MenuView.h"

USING_NS_CC;

class HelpLayer : public Layer
{
public:
    
    // in there you must add your Code in here.
    virtual bool init();
    
    // a selector callback     
    void menuCallback(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(HelpLayer);
};

#endif // CatchMaster_HelpLayer_H

