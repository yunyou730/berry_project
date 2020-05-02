#include <stdio.h>
#define BERRY_LUA_EXPORTS
#include "../include/berry_lua_entry.h"

extern "C" BERRY_LUA_API int berry_test_1(int n1,int n2)
{
	return n1 + n2;
}

extern "C" BERRY_LUA_API void berr_test_2(const char* str)
{
	printf("%s\n",str);
}
