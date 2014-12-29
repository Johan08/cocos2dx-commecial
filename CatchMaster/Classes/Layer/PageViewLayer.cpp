//
//  PageViewLayer.cpp
//  CatchMaster
//
//  Created by sxz on 2014/12/29.
//  Copyright 2014年 hibiya.tech@gmail.com . All rights reserved.
//

#include "PageViewLayer.h"

bool PageViewLayer::init()
{
  if (!Layer::init())
  {
    return false;
  }

  //画面サイズを取得
  auto windowSize = Director::getInstance()->getWinSize();

  // PageViewを作成これにレイアウトを追加していく
  auto pageView = PageView::create();
  pageView->setTouchEnabled(true);
  pageView->setSize(windowSize);

  // 3ページ作成する
  for (int i = 0; i < 4; i++)
  {
    //レイアウトを作成
    auto layout = Layout::create();
    layout->setSize(windowSize);

    //画像
    auto imageView = ImageView::create("splash.png");
    imageView->setAnchorPoint(Point::ZERO);
    imageView->setScale(1.0f);
    layout->addChild(imageView);

    //テキスト
    auto label = Text::create(StringUtils::format("%d", (i + 1)), "Marker Felt.ttf", 30);
    label->setColor(Color3B(Color3B::BLUE));
    label->setPosition(Vec2(layout->getSize().width / 2, layout->getSize().height / 2));
    layout->addChild(label);

    //レイアウトをaddする
    pageView->addPage(layout);
  }

  //イベントリスナーを追加（using namespace ui; しないと参照出来ないので注意）
  pageView->addEventListenerPageView(this, pagevieweventselector(PageViewLayer::pageviewCallBack));

  this->addChild(pageView);

  return true;
}

//コールバック
void PageViewLayer::pageviewCallBack(Ref* sender, PageViewEventType type)
{
  if (type == PAGEVIEW_EVENT_TURNING)
  {
    auto pageView = dynamic_cast<PageView*>(sender);
    //選択されているページをログに出力
    log("%ld", pageView->getCurPageIndex() + 1);

    if (pageView->getCurPageIndex() == 3)
    {
      auto scene = MenuView::create();
      TransitionScene* transition = TransitionFade::create(1, scene);
      Director::getInstance()->replaceScene(transition);
    }
  }
}