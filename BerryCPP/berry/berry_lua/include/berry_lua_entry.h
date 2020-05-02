#pragma once

#ifdef BERRY_LUA_EXPORTS
#define BERRY_LUA_API _declspec(dllexport)
#else
#define BERRY_LUA_API _declspec(dllimport)
#endif

extern "C" BERRY_LUA_API int berry_test_1(int n1, int n2);
extern "C" BERRY_LUA_API void berr_test_2(const char* str);
extern "C" BERRY_LUA_API void berry_test_lua_1(const char* luaCode);

typedef void(__stdcall* LogFuncProto)(const char* info);
extern "C" BERRY_LUA_API void berry_register_log_func(LogFuncProto func);
extern "C" BERRY_LUA_API void berry_test_call_c_sharp_back(const char* strParam);

