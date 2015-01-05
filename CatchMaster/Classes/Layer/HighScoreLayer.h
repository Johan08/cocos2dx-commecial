//
//  HighScoreLayer.h
//  CatchMaster
//
//  Created by sxz on 2015/01/01.
//  Copyright 2015年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_HighScoreLayer_H
#define CatchMaster_HighScoreLayer_H

#include <iostream>

#include "cocos2d.h"

#include "../Scene/MenuView.h"

USING_NS_CC;

class HighScoreLayer : public Layer
{
public:
    
    // in there you must add your Code in here.
    virtual bool init();
    
    // a selector callback     
    void menuCallback(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(HighScoreLayer);
    
    //sqlite3
    //sqlite3* useDataBase = NULL;
    
    char* errorMessage = NULL;
};

#endif // CatchMaster_HighScoreLayer_H

