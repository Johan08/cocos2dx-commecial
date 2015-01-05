//
//  PopUpLayer.h
//  CatchMaster
//
//  Created by sxz on 2015/01/04.
//  Copyright 2015年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_PopUpLayer_H
#define CatchMaster_PopUpLayer_H

#include "cocos2d.h"

USING_NS_CC;

class PopUpLayer : public LayerColor
{
public:

    virtual bool init();
    
    CREATE_FUNC(PopUpLayer);
    
    Size winSize;
    
    LayerColor* backLayer;
    LayerColor* popUpLayer;
    
    void doClose(Ref* pSender);
};

#endif //CatchMaster_PopUpLayer_H
