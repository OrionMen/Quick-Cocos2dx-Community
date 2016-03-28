//
//  ProtocolHandler.cpp
//  Ragnarok Battle Online
//
//  Created by xudexin on 13-4-17.
//
//

#include "CCPomelo.h"
#include <errno.h>

#include "json/document.h"
#include <pomelo_trans.h>


#define NOTI_EX ((void*)0x33)
#define NOTI_TIMEOUT 30

static Pomelo *s_Pomelo = NULL; // pointer to singleton

void pomelo_on_event_cb(pc_client_t* client, int ev_type, void* ex_data, const char* arg1, const char* arg2)
{
    printf("test: get event %s, arg1: %s, arg2: %s\n", pc_client_ev_str(ev_type),
           arg1 ? arg1 : "", arg2 ? arg2 : "");
    if (NULL == ScriptEngineManager::getInstance()->getScriptEngine()) {
        return ;
    }
    
    LuaStack *pStack = LuaEngine::getInstance()->getLuaStack();
    if (NULL == pStack) {
        return ;
    }
    
    lua_State *tolua_s = pStack->getLuaState();
    if (NULL == tolua_s) {
        return ;
    }
    
    pStack->pushString(pc_client_ev_str(ev_type));
    pStack->pushString(arg1);
    pStack->pushString(arg2);
    pStack->executeFunctionByHandler(s_Pomelo->getLuaEventHandler(), 3);
    pStack->clean();
    return ;
}

#define REQ_TIMEOUT 30
void pomelo_on_request_cb(const pc_request_t* req, int rc, const char* resp)
{
    printf("test get resp %s\n", resp);
    
    if (NULL == ScriptEngineManager::getInstance()->getScriptEngine()) {
        return ;
    }
    
    LuaStack *pStack = LuaEngine::getInstance()->getLuaStack();
    if (NULL == pStack) {
        return ;
    }
    
    lua_State *tolua_s = pStack->getLuaState();
    if (NULL == tolua_s) {
        return ;
    }
    
    rapidjson::Document doc;
    doc.Parse(resp);
    if (doc.HasParseError()) {
        return;
    }
    if (doc.HasMember("code")) {
        int code = doc["code"].GetInt();
        if (code == 200) {
            //这个rc应该通用搞，放在每个协议里面搞不太对
            //    pStack->pushString(pc_client_rc_str(rc));
            pStack->pushString(resp);
            int * p  = (int*)pc_request_ex_data(req);
            pStack->executeFunctionByHandler(*p, 1);
            pStack->clean();
            
            delete p;//因为之前为这个lua function handler申请了内存，保证他常驻内存
            return ;
        }
        else
        {
            //不等于200说明有错误，这时候应该有个lua函数负责处理这个抛出的错误code
            pStack->pushInt(code);
            pStack->executeFunctionByHandler(s_Pomelo->getLuaRequestErrorHandler(), 1);
            pStack->clean();
            
            return ;
        }
    }
}

void notify_cb(const pc_notify_t* noti, int rc)
{
//    PC_TEST_ASSERT(rc == PC_RC_OK);
}

void Pomelo::polling(float)
{
    pc_client_poll(_client);
}

Pomelo::Pomelo():
_handlerId(0),
_luaHandlerId(0),
_luaRequestErrorHandlerId(0){
    Director::getInstance()->getScheduler()->schedule(CC_SCHEDULE_SELECTOR(Pomelo::polling), this, 0, false);
//    Director::getInstance()->getScheduler()->pauseTarget(this);
    
    pc_client_config_t config = PC_CLIENT_CONFIG_DEFAULT;
    config.enable_polling = 1;
    pc_lib_init(NULL, NULL, NULL, NULL);
    
    _client = (pc_client_t*)malloc(pc_client_size());
    pc_client_init(_client, (void*)0x11, &config);
    
    _handlerId = pc_client_add_ev_handler(_client, pomelo_on_event_cb, NULL, NULL);
}

Pomelo::~Pomelo(){
    Director::getInstance()->getScheduler()->unschedule(CC_SCHEDULE_SELECTOR(Pomelo::polling), s_Pomelo);
    
    pc_client_rm_ev_handler(_client, _handlerId);
    
    pc_client_cleanup(_client);
    
    free(_client);
    
    pc_lib_cleanup();
}

void Pomelo::pauseTarget()
{
    Director::getInstance()->getScheduler()->pauseTarget(this);
}
void Pomelo::resumeTarget()
{
    Director::getInstance()->getScheduler()->resumeTarget(this);
}

void Pomelo::destroyInstance()
{
    if (s_Pomelo) {
        
        s_Pomelo->release();
    }
}

Pomelo* Pomelo::getInstance()
{
    if (s_Pomelo == NULL) {
        s_Pomelo = new Pomelo();
    }
    return s_Pomelo;
}

int Pomelo::connect(const char* addr,int port,const char* handshake_opts){
    return pc_client_connect(_client , addr , port , handshake_opts);
}

int Pomelo::disconnect()
{
    return pc_client_disconnect(_client);
}

int Pomelo::notifyWithTimeout(const char* route, const char* msg)
{
    return pc_notify_with_timeout(_client, route, msg, NOTI_EX, NOTI_TIMEOUT, notify_cb);
}

int Pomelo::requestWithTimeout(const char* route, const char* msg ,LUA_FUNCTION lua_cb)
{
    //这里用new int是为了保证这个lua function handler常驻内存。等消息返回的时候删掉
    //感觉如果消息回不来可能会有内存泄露，但是问题不大。
    //要不然就用一个List<Map<void* , int>>去存。不过这样感觉好麻烦啊。
    return pc_request_with_timeout(_client, route, msg, new int(lua_cb), REQ_TIMEOUT, pomelo_on_request_cb);
}

void Pomelo::registerLuaEventHandler(LUA_FUNCTION handler)
{
    unRegisterLuaEventHandler();
    _luaHandlerId = handler;
}

void Pomelo::registerLuaRequestErrorHandler(LUA_FUNCTION handler)
{
    _luaRequestErrorHandlerId = handler;
}

void Pomelo::unRegisterLuaEventHandler(void)
{
    if (0 != _luaHandlerId)
    {
        LuaEngine::getInstance()->removeScriptHandler(_luaHandlerId); //移除lua函数的绑定
        _luaHandlerId = 0;
    }
}

void Pomelo::unRegisterLuaRequestErrorHandler(void)
{
    if (0 != _luaRequestErrorHandlerId)
    {
        LuaEngine::getInstance()->removeScriptHandler(_luaRequestErrorHandlerId); //移除lua函数的绑定
        _luaRequestErrorHandlerId = 0;
    }
}

