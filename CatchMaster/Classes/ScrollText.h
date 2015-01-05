
#include "cocos2d.h"

class ScrollText:public cocos2d::Node
{
	public:
		CREATE_FUNC(ScrollText);

		static ScrollText* create(cocos2d::Sprite* &pMask,cocos2d::Node* &pMoveChild,cocos2d::Node* &otherChild,...);

		void setAutoScroll(bool isScroll,bool byWidth=false);
    
    protected:
		ScrollText();
		virtual ~ScrollText();
		virtual bool init();
		virtual bool initWithDatas(cocos2d::Sprite* &pMask,cocos2d::Node* &pMoveChild);
		bool initClipper(cocos2d::Sprite* &pMask,cocos2d::Node* &pMoveChild);
		void update(float delta);

	private:
		cocos2d::Node* _mLable;
		cocos2d::Vector<Node*> _mNodes;
		bool _autoScroll;
};