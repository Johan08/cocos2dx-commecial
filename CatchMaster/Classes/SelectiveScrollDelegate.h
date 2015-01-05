//
//  SelectiveScrollDelegate.h
//  CatchMaster
//
//  Created by sxz on 2015/01/03.
//  Copyright 2015年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_SelectiveScrollDelegate_H
#define CatchMaster_SelectiveScrollDelegate_H

#include "cocos2d.h"

USING_NS_CC;

class SelectiveScrollDelegate {
    
public:
    virtual bool isLayerSelected(Node* node, void* sender)
    {
        CC_UNUSED_PARAM(node), CC_UNUSED_PARAM(sender);
        return false;
    }
    
    virtual void selectiveScrollHighlightLayer(bool hi, Node* node, void* sender)
    {
        CC_UNUSED_PARAM(hi), CC_UNUSED_PARAM(node), CC_UNUSED_PARAM(sender);
    }
    
    virtual void selectiveScrollDidSelectLayer(Node* node, void* sender)
    {
        CC_UNUSED_PARAM(node), CC_UNUSED_PARAM(sender);
    }
    
    virtual bool isPagingPointNode(Node* node, void* sender)
    {
        CC_UNUSED_PARAM(node), CC_UNUSED_PARAM(sender);
        return false;
    }
    
    virtual void pagingScrollWillEnd(Node* node, void* sender)
    {
        CC_UNUSED_PARAM(node), CC_UNUSED_PARAM(sender);
    }
    
    virtual void pagingScrollDidEnd(Node* node, void* sender)
    {
        CC_UNUSED_PARAM(node), CC_UNUSED_PARAM(sender);
    }
};

#endif /* defined(CatchMaster_SelectiveScrollDelegate_H) */
