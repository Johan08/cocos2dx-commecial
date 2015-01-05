//
//  WeaponLayer.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#include "WeaponLayer.h"

// on "init" you need to initialize your instance
bool WeaponLayer::init()
{
    /////////////////////////////////////////
    // 1.super init first
    if ( !LayerColor::initWithColor(Color4B::WHITE)) return false;
    

    //Welcome Message
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
//    // クリッピングノードの作成とレイヤへ追加
//    auto clippingNode = ClippingNode::create();
//    clippingNode->setAlphaThreshold(0);
//    clippingNode->setPosition(Vec2(0, 0));
//    clippingNode->setAnchorPoint(Point::ZERO);
//    this->addChild(clippingNode);
//
//    // マスク画像の作成とステンシルに設定
//    auto mask = Sprite::create("mask.png");
//    mask->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
//    clippingNode->setStencil(mask);
//    
//    auto image = Sprite::create("image.png");
//    image->setPosition(visibleSize.width/ 2, visibleSize.height /2);
//    clippingNode->addChild(image);
//
//    Sprite *buttonNormal = Sprite::create("CloseNormal.png");
//    Sprite *buttonClose  = Sprite::create("CloseSelected.png");
//    
//    auto menuItem  = MenuItemSprite::create(buttonNormal,buttonClose,NULL,CC_CALLBACK_1(WeaponLayer::menuCallback, this));
//    menuItem->setPosition(Point(origin.x + visibleSize.width/2 ,origin.y + 60));
//    
//    auto menu = Menu::create(menuItem, NULL);
//    menu->setPosition(Point(origin.x ,origin.y));
//    this->addChild(menu, 1);
    
    //addLayer();
    
    
    
    
    //메뉴 추가
    MenuItemFont* itemPop=CCMenuItemFont::create("popUp",	this,  menu_selector(WeaponLayer::doPop));
    itemPop->setColor(ccc3(0,0,0));
    //CCMenu* pMenu=CCMenu::create(itemPop, NULL);
    pMenu=CCMenu::create(itemPop, NULL);
    pMenu->setPosition(ccp(240, 50));
    this->addChild(pMenu);
    
    //스프라이트 추가
    CCSprite* man=CCSprite::create("CloseNormal.png");
    man->setPosition( ccp(20,250));
    this->addChild(man);
    
    //액션 추가
    CCActionInterval* myAction=CCMoveBy::create(15, ccp(400, 0));
    man->runAction(myAction);
    
    //노티피케이션 추카
    //CCNotificationCenter::getInstance()()->addObserver(this, callfuncO_selector(WeaponLayer::doNotification), "notification", NULL);
    //"notification"이라는 메시지가 오면 해당 함수를 실행한다.
    
    return true;
}

void WeaponLayer::menuCallback(Ref* pSender)
{
    auto scene = GameScene::create();
    TransitionScene *transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}

void WeaponLayer::addLayer()
{
    auto layer = Layer::create();
    
    // モーダルレイヤ ここから
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [](Touch *touch,Event*event)->bool
    {
        return true;
    };
    auto dip = layer->getEventDispatcher();
    dip->addEventListenerWithSceneGraphPriority(listener, this);
    dip->setPriority(listener, 1);
    // モーダルレイヤ ここまで
    
    auto size = Director::getInstance()->getVisibleSize();
    ui::ScrollView* sc = ui::ScrollView::create();
    sc->setContentSize(size);
    sc->setBackGroundColor(Color3B::BLUE);
    sc->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
    sc->setBounceEnabled(true);
    sc->setDirection(ui::ScrollView::Direction::VERTICAL);
    sc->setContentSize(Size(480,size.height));
    sc->setInnerContainerSize(Size(480, sc->getContentSize().height + 300 ));
    sc->setPosition(Vec2(0,size.height - sc->getContentSize().height ));
    
    Button* button = Button::create("CloseNormal.png");
    button->setPosition(Vec2(button->getContentSize().width / 2.0f, sc->getContentSize().height - button->getContentSize().height / 2.0f));
    sc->addChild(button);
    
    layer->addChild(sc);
    addChild(layer);
}

/**
 *  @author shixinzhu
 *
 *  your_widget->addTouchEventListener(CC_CALLBACK_2(WeaponLayer::onTouchEvent, this));//CC_CALLBACK_2照着写，表示有两个参数的回调。
 *
 *  @param ref       <#ref description#>
 *  @param touchType <#touchType description#>
 */
void WeaponLayer::onTouchEvent(cocos2d::Ref *ref, Widget::TouchEventType touchType)
{
    switch(touchType)
    {
        case Widget::TouchEventType::BEGAN:
            log("on began");
            break;
        case Widget::TouchEventType::MOVED:
            log("on moved");
            break;
        case Widget::TouchEventType::ENDED:
            log("on ended");
            break;
        case Widget::TouchEventType::CANCELED:
            log("on canceled");
            break;
        default:
            log("impossible");
    }
}

void WeaponLayer::textFieldEvent(Ref *pSender, TextField::EventType type)
{
    switch (type)
    {
        case TextField::EventType::ATTACH_WITH_IME:
            CCLOG("获得输入焦点");
            break;
        case TextField::EventType::DETACH_WITH_IME:
            CCLOG("获得输入焦点");
            break;
        case TextField::EventType::INSERT_TEXT:
            CCLOG("输入了文本");
            break;
        case TextField::EventType::DELETE_BACKWARD:
            CCLOG("获得输入焦点");
            break;
        default:
            break;
    }
}


void WeaponLayer::doPop(Ref* pSender)
{
//    Scene* pScene=PopLayer::scene();
//    this->addChild(pScene,2000,2000);
}
//노티피케이션 함수
void WeaponLayer::doNotification(Ref *obj){
    //노티피케이션 받기
    CCString *pParam=(CCString*)obj;
    CCLog("notification %s", pParam->getCString());
    
    if(pParam->intValue()==1){
        CCLog("noti 11");
        CCDirector::sharedDirector()->resume();   //화면 재시작
        
        //Director::getInstance()->get getTouchDispatcher()->addTargetedDelegate(pMenu, 1,true);
        //메뉴 버튼 활성
    }
    else{
        //Array* childs = this->getChildren();
        CCLog("noti 00");
        CCDirector::sharedDirector()->pause();   //화면 정지
        
       // CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(pMenu);
        //메뉴버튼 비활성
    }
    
}
