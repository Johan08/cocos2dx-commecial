#include "ScrollText.h"
USING_NS_CC;
#define IF_RETURN(cont,p) if ((cont)){return (p);}
#define IF_RETURN_FALSE(cont) IF_RETURN(cont,false)
bool ScrollText::init()
{
	bool ret = true;
	if (Node::init())
	{
		auto pMask = Sprite::create("switch-mask.png");
		_mLable = Label::createWithSystemFont("Title", "Arial-BoldMT", 40);
		_mLable->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
		IF_RETURN_FALSE(!initClipper(pMask,_mLable));
		scheduleUpdate();
		setAutoScroll(true);
		return ret;
	}
	return ret;
}

bool ScrollText::initClipper( cocos2d::Sprite* &pMask,cocos2d::Node* &pMoveChild)
{
	auto clipper = ClippingNode::create();
	IF_RETURN_FALSE(!clipper);
	IF_RETURN_FALSE(!pMask);
	setContentSize(pMask->getContentSize());
	IF_RETURN_FALSE(!pMask->getTexture());
	auto _clipperStencil = Sprite::createWithTexture(pMask->getTexture());
	//_clipperStencil->setAnchorPoint((0.5,0.5));
	IF_RETURN_FALSE(!_clipperStencil);
	_clipperStencil->retain();
	clipper->setAlphaThreshold(0.1f);
	clipper->setStencil(_clipperStencil);
	clipper->addChild(pMoveChild,1);
	addChild(clipper);
	for (auto child:_mNodes)
	{
		IF_RETURN_FALSE(!child);
		clipper->addChild(child);
	}
	return true;
}

ScrollText::ScrollText():_autoScroll(false)
{

}

ScrollText::~ScrollText()
{
	CC_SAFE_RELEASE(_mLable);
}

void ScrollText::update( float delta )
{
	if (!_mLable)
	{
		return;
	}
	//float currentX = _mLable->getPositionX();
	float contentX = getContentSize().width*(-1.0f);
	float lableX = _mLable->getContentSize().width*(-1.0f);

	if (_autoScroll)
	{
		if(_mLable->getPositionX()>=(lableX+contentX/2))
			_mLable->setPositionX(_mLable->getPositionX()-0.25f);
		else
		{
			_mLable->setPositionX(-contentX/2);
		}
	}
	else
	{
		_mLable->setPositionX(contentX/2);
	}
}

void ScrollText::setAutoScroll( bool isScroll,bool byWidth/*=false*/ )
{
	if (!byWidth)
	{
		_autoScroll = isScroll;
	}
	else
	{
		_autoScroll=_mLable->getContentSize().width>getContentSize().width?true:false;
	}
}

ScrollText* ScrollText::create( cocos2d::Sprite* &pMask,cocos2d::Node* &pMoveChild,cocos2d::Node* &otherChild,... )
{
	auto *sTxt = new ScrollText(); 
	if (sTxt ) 
	{ 
		va_list lst;
		va_start(lst, otherChild);
		Node* pNow;
		pNow=otherChild;
		while(otherChild)
		{
			if (pNow)
			{
				sTxt->_mNodes.pushBack(pNow);
				pNow=va_arg(lst,Node*);
			}
			else
				break;
		}
		va_end(lst);
		if(sTxt->initWithDatas(pMask,pMoveChild))
		{
			sTxt->autorelease(); 
			return sTxt; 
		}
		else
		{
			delete sTxt; 
			sTxt = NULL; 
			return NULL; 
		}
	} 
	else 
	{ 
		delete sTxt; 
		sTxt = NULL; 
		return NULL; 
	} 
}

bool ScrollText::initWithDatas( cocos2d::Sprite* &pMask,cocos2d::Node* &pMoveChild)
{
	bool ret = false;
	if (Node::init())
	{
		IF_RETURN_FALSE(!pMask);
		_mLable = pMoveChild;
		_mLable->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
		initClipper(pMask,_mLable);
		scheduleUpdate();
		return true;
	}
	return ret;
}