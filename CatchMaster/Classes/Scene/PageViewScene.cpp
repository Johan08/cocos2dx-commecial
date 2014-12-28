//
//  PageViewScene.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/27.
//  Copyright 2014年 __MyCompanyName__. All rights reserved.
//

#include "PageViewScene.h"

Scene* PageViewScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PageViewScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initiallize your instance
bool PageViewScene::init()
{
    //////////////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //画面サイズを取得
    auto windowSize = Director::getInstance()->getWinSize();
    
    //PageViewを作成これにレイアウトを追加していく
    auto pageView = PageView::create();
    pageView->setTouchEnabled(true);
    pageView->setSize(windowSize);
    
    //3ページ作成する
    for (int i = 0; i < 4; i++) {
        
        //レイアウトを作成
        auto layout = Layout::create();
        layout->setSize(windowSize);
        
        //画像
        auto imageView = ImageView::create("splash.png");
        imageView->setAnchorPoint( Point::ANCHOR_BOTTOM_LEFT );
        imageView->setScale(2.0f);
        layout->addChild(imageView);
        
        //テキスト
        auto label = Text::create(StringUtils::format("%dﾍﾟｰｼﾞ",(i+1)), "fonts/Marker Felt.ttf", 30);
        label->setColor(Color3B(Color3B::BLUE));
        label->setPosition(Point(layout->getSize().width / 2, layout->getSize().height / 2));
        layout->addChild(label);
        
        //レイアウトをaddする
        pageView->addPage(layout);
    }
    
    //イベントリスナーを追加（using namespace ui; しないと参照出来ないので注意）
    pageView->addEventListenerPageView(this, pagevieweventselector(PageViewScene::pageviewCallBack));
    
    this->addChild(pageView);

    return true;
}

//コールバック
void PageViewScene::pageviewCallBack(Ref* sender, PageViewEventType type)
{
    if(type == PAGEVIEW_EVENT_TURNING){
        auto pageView = dynamic_cast<PageView*>(sender);
        //選択されているページをログに出力
        log("%ld",pageView->getCurPageIndex() + 1);
        
        if (pageView->getCurPageIndex() == 3) {
            auto scene = GameScene::create();
            TransitionScene *transition = TransitionFade::create(1, scene);
            Director::getInstance()->replaceScene(transition);
        }
    }
}

