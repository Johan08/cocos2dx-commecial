//
//  HighScoreLayer.cpp
//  CatchMaster
//
//  Created by sxz on 2015/01/01.
//  Copyright 2015年 hibiya.tech@gmail.com . All rights reserved.
//

#include "HighScoreLayer.h"

bool HighScoreLayer::init()
{
    if ( !Layer::init() ) return false;
    
//    //DBファイルの保存先のパス
//    auto filePath = FileUtils::getInstance()->getWritablePath();
//    filePath.append("CatchMaster.db");
//    log(">>> filePath : %s" , filePath.c_str());
//    
//    //OPEN
//    auto status = sqlite3_open(filePath.c_str(), &useDataBase);
//    
//    //ステータスが0以外の場合はエラーを表示
//    if (status != SQLITE_OK){
//        CCLOG("opne failed : %s", errorMessage);
//    }else{
//        CCLOG("open sucessed");
//    }
//    
//    //テーブル作成
//    auto create_sql = "CREATE TABLE user( id integer primary key autoincrement, name nvarchar(32), age int(2) )";
//    status = sqlite3_exec(useDataBase, create_sql, NULL, NULL, &errorMessage );
//    if( status != SQLITE_OK ) CCLOG("create table failed : %s", errorMessage);
//    
//    //インサート
//    auto insert_sql = "INSERT INTO user(name, age) VALUES('raharu', 29)";
//    status = sqlite3_exec(useDataBase, insert_sql , NULL, NULL, &errorMessage);
//    
//    //Close
//    sqlite3_close(useDataBase);


    Size windowSize = Director::getInstance()->getVisibleSize();
    Vec2 origin     = Director::getInstance()->getVisibleOrigin();
    
    auto background = Sprite::create("score_background.png");
    background->setAnchorPoint(Point::ZERO);
    background->setPosition(Vec2(0, 40));
    background->setScale(windowSize.width / background->getBoundingBox().size.width,
                         (windowSize.height - 40)/ background->getBoundingBox().size.height);
    this->addChild(background, 0);
    
    auto label = LabelTTF::create("shixinzhu     89000", "Arial", 16);
    label->setPosition(130, windowSize.height - 100);
    label->setColor(Color3B::BLUE);
    this->addChild(label, 2);
    
    auto closeButton = Sprite::create("exit.png");
    auto menuCloseItem  = MenuItemSprite::create(closeButton, closeButton, NULL,CC_CALLBACK_1(HighScoreLayer::menuCallback, this));
    menuCloseItem->setPosition(Vec2(270, 40 + 19));
    
    auto menu = Menu::create(menuCloseItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    return true;
}

void HighScoreLayer::menuCallback(Ref* pSender)
{
    auto scene = MenuView::create();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}

