#include <stdio.h>
#define BERRY_LUA_EXPORTS
#include "../include/berry_lua_entry.h"
#include "BerryLuaWrapper.h"


extern "C" BERRY_LUA_API int berry_test_1(int n1,int n2)
{
	return n1 + n2;
}

extern "C" BERRY_LUA_API void berr_test_2(const char* str)
{
	printf("%s\n",str);
}

extern "C" BERRY_LUA_API void berry_test_lua_1(const char* luaCode)
{
	berry::BerryLuaWraper::GetInstance()->ExecuteString(luaCode);
}

extern "C" BERRY_LUA_API void berry_register_log_func(LogFuncProto func)
{
	berry::BerryLuaWraper::GetInstance()->RegisterLogFunc(func);
}

extern "C" BERRY_LUA_API void berry_test_call_c_sharp_back(const char* strParam)
{
	berry::BerryLuaWraper::GetInstance()->Log(strParam);
}

extern "C" BERRY_LUA_API void berry_test_do_lua_file(const char* strParam)
{
	berry::BerryLuaWraper::GetInstance()->ExecuteFile(strParam);
}

