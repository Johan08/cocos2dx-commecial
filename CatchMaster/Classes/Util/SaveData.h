//
//  SaveData.h
//  CatchMaster
//
//  Created by sxz on 2015/01/01.
//  Copyright 2015年 hibiya.tech@gmail.com. All rights reserved.

#ifndef CatchMaster_SaveData_H
#define CatchMaster_SaveData_H

#include "cocos2d.h"
USING_NS_CC;

class SaveData : public Node
{
public:
    virtual bool init();
    
    static void saveInt(const char *key,int value);
    static void saveString(const char *key,const cocos2d::__String *string);
    static void saveBool(const char *key,bool _bolean);
    
    static int loadInt(const char *key);
    static std::string loadString(const char *key);
    static bool loadBool(const char *key);
};

#endif //CatchMaster_SaveData_H
