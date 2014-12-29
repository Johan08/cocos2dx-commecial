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
USING_NS_CC;

class WeaponLayer : public Layer
{
public:
    
    // in there you must add your Code in here.
    virtual bool init();
    
    // a selector callback     
    void menuCallback(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(WeaponLayer);
};

#endif // CatchMaster_WeaponLayer_H

