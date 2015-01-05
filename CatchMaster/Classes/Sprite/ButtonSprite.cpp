//
//  ButtonSprite.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com. All rights reserved.

#include "ButtonSprite.h"


ButtonSprite::ButtonSprite() {}

ButtonSprite::~ButtonSprite() {}

ButtonSprite* ButtonSprite::create(const std::string& filename)
{
    ButtonSprite* sprite = new ButtonSprite();

    if (sprite->initWithFile(filename))
    {
        sprite->autorelease();
        sprite->initOptions();
        sprite->addEvents();
        return sprite;
    }

    CC_SAFE_DELETE(sprite);
    return NULL;
}

void ButtonSprite::initOptions()
{
   // do things here like setTag(), setPosition(), any custom logic.
}

void ButtonSprite::addEvents()
{
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);

    listener->onTouchBegan = [&](Touch* touch, Event* event)
    {   
        Vec2 p = touch->getLocation();
        Rect rect = this->getBoundingBox();

        if(rect.containsPoint(p))
        {
            return true; // to indicate that we have consumed it.
        }

        return false; // we did not consume this event, pass thru.
    };

    listener->onTouchEnded = [=](Touch* touch, Event* event)
    {
        ButtonSprite::touchEvent(touch);
    };

    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 30);
}

void ButtonSprite::touchEvent(Touch* touch)
{
    auto scene = getParent()->getParent();
    
    if (scene)
    {
        auto child = scene->getChildByTag(1002);
        if (child)
        {
            if (child->isVisible())
            {
                child->setVisible(false);
            } else
            {
                child->setVisible(true);
            }
        }
    }
}
