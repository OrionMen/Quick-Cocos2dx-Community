#include "lua_pomelo_auto.hpp"
#include "lua.h"
#include "tolua++.h"
#include "pomelo_trans.h"
#include "pomelo.h"
#include "cocos2d.h"
#include "CCLuaEngine.h"
#include "CCPomelo.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_pomelo_Pomelo_notifyWithTimeout(lua_State* tolua_S)
{
    int argc = 0;
    Pomelo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Pomelo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Pomelo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_pomelo_Pomelo_notifyWithTimeout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        const char* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "Pomelo:notifyWithTimeout"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "Pomelo:notifyWithTimeout"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_pomelo_Pomelo_notifyWithTimeout'", nullptr);
            return 0;
        }
        int ret = cobj->notifyWithTimeout(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Pomelo:notifyWithTimeout",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_pomelo_Pomelo_notifyWithTimeout'.",&tolua_err);
#endif

    return 0;
}
int lua_pomelo_Pomelo_getLuaRequestErrorHandler(lua_State* tolua_S)
{
    int argc = 0;
    Pomelo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Pomelo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Pomelo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_pomelo_Pomelo_getLuaRequestErrorHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_pomelo_Pomelo_getLuaRequestErrorHandler'", nullptr);
            return 0;
        }
        cocos2d::LUA_FUNCTION ret = cobj->getLuaRequestErrorHandler();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Pomelo:getLuaRequestErrorHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_pomelo_Pomelo_getLuaRequestErrorHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_pomelo_Pomelo_disconnect(lua_State* tolua_S)
{
    int argc = 0;
    Pomelo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Pomelo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Pomelo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_pomelo_Pomelo_disconnect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_pomelo_Pomelo_disconnect'", nullptr);
            return 0;
        }
        int ret = cobj->disconnect();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Pomelo:disconnect",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_pomelo_Pomelo_disconnect'.",&tolua_err);
#endif

    return 0;
}
int lua_pomelo_Pomelo_resumeTarget(lua_State* tolua_S)
{
    int argc = 0;
    Pomelo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Pomelo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Pomelo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_pomelo_Pomelo_resumeTarget'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_pomelo_Pomelo_resumeTarget'", nullptr);
            return 0;
        }
        cobj->resumeTarget();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Pomelo:resumeTarget",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_pomelo_Pomelo_resumeTarget'.",&tolua_err);
#endif

    return 0;
}
int lua_pomelo_Pomelo_registerLuaRequestErrorHandler(lua_State* tolua_S)
{
    int argc = 0;
    Pomelo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Pomelo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Pomelo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_pomelo_Pomelo_registerLuaRequestErrorHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::LUA_FUNCTION arg0;

        arg0 = toluafix_ref_function(tolua_S, 2, 0); ok &= arg0 >= 0;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_pomelo_Pomelo_registerLuaRequestErrorHandler'", nullptr);
            return 0;
        }
        cobj->registerLuaRequestErrorHandler(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Pomelo:registerLuaRequestErrorHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_pomelo_Pomelo_registerLuaRequestErrorHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_pomelo_Pomelo_getLuaEventHandler(lua_State* tolua_S)
{
    int argc = 0;
    Pomelo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Pomelo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Pomelo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_pomelo_Pomelo_getLuaEventHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_pomelo_Pomelo_getLuaEventHandler'", nullptr);
            return 0;
        }
        cocos2d::LUA_FUNCTION ret = cobj->getLuaEventHandler();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Pomelo:getLuaEventHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_pomelo_Pomelo_getLuaEventHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_pomelo_Pomelo_connect(lua_State* tolua_S)
{
    int argc = 0;
    Pomelo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Pomelo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Pomelo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_pomelo_Pomelo_connect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        int arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "Pomelo:connect"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "Pomelo:connect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_pomelo_Pomelo_connect'", nullptr);
            return 0;
        }
        int ret = cobj->connect(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    if (argc == 3) 
    {
        const char* arg0;
        int arg1;
        const char* arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "Pomelo:connect"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "Pomelo:connect");

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "Pomelo:connect"); arg2 = arg2_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_pomelo_Pomelo_connect'", nullptr);
            return 0;
        }
        int ret = cobj->connect(arg0, arg1, arg2);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Pomelo:connect",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_pomelo_Pomelo_connect'.",&tolua_err);
#endif

    return 0;
}
int lua_pomelo_Pomelo_requestWithTimeout(lua_State* tolua_S)
{
    int argc = 0;
    Pomelo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Pomelo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Pomelo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_pomelo_Pomelo_requestWithTimeout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        const char* arg1;
        cocos2d::LUA_FUNCTION arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "Pomelo:requestWithTimeout"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "Pomelo:requestWithTimeout"); arg1 = arg1_tmp.c_str();

        arg2 = toluafix_ref_function(tolua_S, 4, 0); ok &= arg2 >= 0;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_pomelo_Pomelo_requestWithTimeout'", nullptr);
            return 0;
        }
        int ret = cobj->requestWithTimeout(arg0, arg1, arg2);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Pomelo:requestWithTimeout",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_pomelo_Pomelo_requestWithTimeout'.",&tolua_err);
#endif

    return 0;
}
int lua_pomelo_Pomelo_registerLuaEventHandler(lua_State* tolua_S)
{
    int argc = 0;
    Pomelo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Pomelo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Pomelo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_pomelo_Pomelo_registerLuaEventHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::LUA_FUNCTION arg0;

        arg0 = toluafix_ref_function(tolua_S, 2, 0); ok &= arg0 >= 0;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_pomelo_Pomelo_registerLuaEventHandler'", nullptr);
            return 0;
        }
        cobj->registerLuaEventHandler(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Pomelo:registerLuaEventHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_pomelo_Pomelo_registerLuaEventHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_pomelo_Pomelo_pauseTarget(lua_State* tolua_S)
{
    int argc = 0;
    Pomelo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Pomelo",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Pomelo*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_pomelo_Pomelo_pauseTarget'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_pomelo_Pomelo_pauseTarget'", nullptr);
            return 0;
        }
        cobj->pauseTarget();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Pomelo:pauseTarget",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_pomelo_Pomelo_pauseTarget'.",&tolua_err);
#endif

    return 0;
}
int lua_pomelo_Pomelo_destroyInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Pomelo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_pomelo_Pomelo_destroyInstance'", nullptr);
            return 0;
        }
        Pomelo::destroyInstance();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "Pomelo:destroyInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_pomelo_Pomelo_destroyInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_pomelo_Pomelo_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Pomelo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_pomelo_Pomelo_getInstance'", nullptr);
            return 0;
        }
        Pomelo* ret = Pomelo::getInstance();
        object_to_luaval<Pomelo>(tolua_S, "Pomelo",(Pomelo*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "Pomelo:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_pomelo_Pomelo_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_pomelo_Pomelo_constructor(lua_State* tolua_S)
{
    int argc = 0;
    Pomelo* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_pomelo_Pomelo_constructor'", nullptr);
            return 0;
        }
        cobj = new Pomelo();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"Pomelo");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Pomelo:Pomelo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_pomelo_Pomelo_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_pomelo_Pomelo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Pomelo)");
    return 0;
}

int lua_register_pomelo_Pomelo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Pomelo");
    tolua_cclass(tolua_S,"Pomelo","Pomelo","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Pomelo");
        tolua_function(tolua_S,"new",lua_pomelo_Pomelo_constructor);
        tolua_function(tolua_S,"notifyWithTimeout",lua_pomelo_Pomelo_notifyWithTimeout);
        tolua_function(tolua_S,"getLuaRequestErrorHandler",lua_pomelo_Pomelo_getLuaRequestErrorHandler);
        tolua_function(tolua_S,"disconnect",lua_pomelo_Pomelo_disconnect);
        tolua_function(tolua_S,"resumeTarget",lua_pomelo_Pomelo_resumeTarget);
        tolua_function(tolua_S,"registerLuaRequestErrorHandler",lua_pomelo_Pomelo_registerLuaRequestErrorHandler);
        tolua_function(tolua_S,"getLuaEventHandler",lua_pomelo_Pomelo_getLuaEventHandler);
        tolua_function(tolua_S,"connect",lua_pomelo_Pomelo_connect);
        tolua_function(tolua_S,"requestWithTimeout",lua_pomelo_Pomelo_requestWithTimeout);
        tolua_function(tolua_S,"registerLuaEventHandler",lua_pomelo_Pomelo_registerLuaEventHandler);
        tolua_function(tolua_S,"pauseTarget",lua_pomelo_Pomelo_pauseTarget);
        tolua_function(tolua_S,"destroyInstance", lua_pomelo_Pomelo_destroyInstance);
        tolua_function(tolua_S,"getInstance", lua_pomelo_Pomelo_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(Pomelo).name();
    g_luaType[typeName] = "Pomelo";
    g_typeCast["Pomelo"] = "Pomelo";
    return 1;
}
TOLUA_API int register_all_pomelo(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_pomelo_Pomelo(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

