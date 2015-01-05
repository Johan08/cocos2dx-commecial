#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;

    void onDraw();
    
    CREATE_FUNC(HelloWorld);
    
private:
    CustomCommand _customCommand;
    
    GLuint vao;
    GLuint vertexVBO;
    GLuint colorVBO;
};

#endif // __HELLOWORLD_SCENE_H__
