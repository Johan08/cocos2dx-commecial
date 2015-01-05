//
//  ButtonSprite.h
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.

#ifndef CatchMaster_ButtonSprite_H
#define CatchMaster_ButtonSprite_H

#include "cocos2d.h"

USING_NS_CC;

class ButtonSprite : public Sprite
{
public:
    ButtonSprite();
    ~ButtonSprite();

    static ButtonSprite* create(const std::string& filename);

    void initOptions();

    void addEvents();

    void touchEvent(Touch* touch);
};

#endif //CatchMaster_ButtonSprite_H
