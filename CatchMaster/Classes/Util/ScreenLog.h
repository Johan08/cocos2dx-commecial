//
//  ScreenLog.h
//  CatchMaster
//
//  Created by sxz on 2015/01/02.
//  Copyright 2015年 hibiya.tech@gmail.com . All rights reserved.
//

#ifndef CatchMaster_ScreenLog_H
#define CatchMaster_ScreenLog_H

#include "cocos2d.h"

#include <string>
#include <vector>

#define LL_FATAL    0x01
#define LL_ERROR    0x02
#define LL_WARNING  0x04
#define LL_INFO     0x08
#define LL_DEBUG    0x10
#define LL_TRACE    0x11

using namespace std;
USING_NS_CC;

// use example  ::  g_screenLog->log(LL_ERROR, "onContactBegin");

class ScreenLogMessage
{
    friend class ScreenLog;
private:
    class ScreenLog* m_layer;
    int         m_level;
    std::string m_text;
    float       m_timestamp;
    LabelTTF*   m_label;
    bool        m_dirty;
    
private:
    ScreenLogMessage(ScreenLog* layer)
    {
        m_layer = layer;
        m_label = NULL;
        m_level = 0;
        m_timestamp = 0;
        m_dirty = true;
    }
    
    virtual ~ScreenLogMessage() {}
    
    void setLabelText(std::string msg);
    void createLabel();
    bool checkLabel();
};

//////////////////////////////////////////////////////////////////////

class ScreenLog : public Layer
{
    friend class screenLogMessage;
private:
    
    int m_level;
    float m_timeout;
    std::vector<ScreenLogMessage*> m_messages;
    
    
public:
    
    ScreenLog();
    ~ScreenLog();
    
    pthread_mutex_t m_contentMutex;
    std::string m_fontFile;
    
    void setFontFile(std::string file);
    void setLevelMask(int level);
    void setTimeoutSeconds(float seconds);
    void attachToScene(Scene* scene);
    
    ScreenLogMessage* log(int level, const char* msg, ...);
    void setMessageText(ScreenLogMessage* slm, const char *p_str, ...);
    
    void update(float dt);
    void moveLabelsUp(int maxIndex);
    void clearEntries();
};

extern ScreenLog* g_screenLog;

//////////////////////////////////////////////////////////////////////

class ScopeLock
{
public:
    pthread_mutex_t* m_mutex;
    
    ScopeLock(pthread_mutex_t* m)
    {
        m_mutex = m;
        pthread_mutex_lock(m_mutex);
    }
    
    ~ScopeLock()
    {
        pthread_mutex_unlock(m_mutex);
    }
};

//////////////////////////////////////////////////////////////////////

class ScopeLog
{
public:
    std::string m_functionName;
    ScopeLog(std::string fn)
    {
        m_functionName = fn;
        g_screenLog->log(LL_TRACE, "Entered %s", m_functionName.c_str());
    }
    ~ScopeLog() {
        g_screenLog->log(LL_TRACE, "Exiting %s", m_functionName.c_str());
    }
};

#endif // CatchMaster_ScreenLog_H
