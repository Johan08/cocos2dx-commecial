//
//  ButtonLayer.h
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_ButtonLayer_H
#define CatchMaster_ButtonLayer_H

#include "cocos2d.h"
USING_NS_CC;

class ButtonLayer : public Layer
{
public:
    
    // in there you must add your Code in here.
    virtual bool init();
    
    // a selector callback     
    void menuCallback(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(ButtonLayer);
};

#endif // CatchMaster_ButtonLayer_H

