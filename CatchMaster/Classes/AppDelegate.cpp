#include "AppDelegate.h"
#include "Scene/LoadingScene.h"
#include "Scene/PageViewScene.h"

#include "Util/SaveData.h"

#include "ScrollText.h"
#include "CubeTexture.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{
    g_screenLog = new ScreenLog();
    g_screenLog->setLevelMask( LL_DEBUG | LL_INFO | LL_WARNING | LL_ERROR | LL_FATAL );
    g_screenLog->setFontFile( "Marker Felt.ttf" );
    g_screenLog->setTimeoutSeconds(15);
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview)
    {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

	glview->setDesignResolutionSize(288, 512, ResolutionPolicy::SHOW_ALL);

	// set the resource directory
	this->setResourceSearchResolution();
    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
	
    //auto scene = CubeTexture::createScene();
    
    if (SaveData::loadBool("MUSIC_SWITH"))
    {
        log(">>>>>> MUSIC_SWITH : %d", true );
    } else
    {
        SaveData::saveBool("MUSIC_SWITH", false);
    }
    
    auto scene = PageViewScene::create();

    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void AppDelegate::setResourceSearchResolution()
{
    std::vector<std::string> paths;
    paths.push_back("fonts");
    paths.push_back("image");
    paths.push_back("menuimage");
    paths.push_back("sounds");
    FileUtils::getInstance()->setSearchResolutionsOrder(paths);
    
    log(">>>>>>>>>>>> filePath : %s ",  FileUtils::getInstance()->getWritablePath().c_str());
}