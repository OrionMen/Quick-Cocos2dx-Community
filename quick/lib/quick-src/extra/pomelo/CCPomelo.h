//
//
//  Created by xudexin on 13-4-17.
//
//

#ifndef __CCPomelo__
#define __CCPomelo__

#include "cocos2d.h"

//#include "pomelo.h"
#include "pomelo/include/pomelo.h"
#include <queue>

#include "CCLuaEngine.h"

using namespace cocos2d;

class Pomelo :public cocos2d::Ref{
public:
    static Pomelo *getInstance();
    static void destroyInstance();
    
    int connect(const char* addr,int port ,const char* handshake_opts = NULL);
    int disconnect();
    
    int notifyWithTimeout(const char* route, const char* msg);
    int requestWithTimeout(const char* route, const char* msg ,LUA_FUNCTION lua_cb);
    
    void registerLuaEventHandler(LUA_FUNCTION handler);//这个是lua监听
    void registerLuaRequestErrorHandler(LUA_FUNCTION handler);//这个是lua request报错返回的回调
    
    LUA_FUNCTION getLuaEventHandler(){
        return _luaHandlerId;
    }
    
    LUA_FUNCTION getLuaRequestErrorHandler()
    {
        return _luaRequestErrorHandlerId;
    }
    
    void pauseTarget();
    void resumeTarget();
    
private:
    pc_client_t* _client;
    
    int _handlerId;
    
    LUA_FUNCTION _luaHandlerId;
    LUA_FUNCTION _luaRequestErrorHandlerId;
    
private:
    void polling(float dt);
    void unRegisterLuaEventHandler();
    void unRegisterLuaRequestErrorHandler();
public:
    Pomelo();
    virtual ~Pomelo();
};

#endif /* defined(__CCPomelo__) */
