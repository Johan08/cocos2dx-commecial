//
//  CubeTexture.h
//  CatchMaster
//
//  Created by sxz on 2015/01/03.
//  Copyright 2015年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_CubeTexture_H
#define CatchMaster_CubeTexture_H

#include "cocos2d.h"

using namespace cocos2d;

class CubeTexture : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t transformUpdated) override;
    //we call our actual opengl commands here
    void onDraw();
    
    // implement the "static create()" method manually
    CREATE_FUNC(CubeTexture);
    
private:
    Mat4 _modelViewMV;
    CustomCommand _customCommand;
    
    GLProgram *mShaderProgram;
    GLint _colorLocation;
    GLint _positionLocation;
    GLint _textureLocation;
    
    GLuint _textureUniform;
    
    GLuint _textureID;
   // GLuint _textureID2;
    
    GLuint vertexBuffer;
    GLuint indexBuffer;
    
//    GLuint _vertexBuffer2;
//    GLuint _indexBuffer2;
    
};

#endif // CatchMaster_CubeTexture_H

