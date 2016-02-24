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
    
    void registerLuaEventHandler(LUA_FUNCTION handler);
    
    LUA_FUNCTION getLuaEventHandler(){
        return _luaHandlerId;
    }
    
    void pauseTarget();
    void resumeTarget();
    
private:
    pc_client_t* _client;
    
    int _handlerId;
    
    LUA_FUNCTION _luaHandlerId;
    
private:
    void polling(float dt);
    void unregisterLuaEventHandler();

public:
    Pomelo();
    virtual ~Pomelo();
};

#endif /* defined(__CCPomelo__) */
