#include "BerryLuaWrapper.h"
#include "BerryClass.h"
#include <string>
#include <sstream>
#include <stdio.h>

using namespace berry;

BerryLuaWraper* BerryLuaWraper::GetInstance()
{
	static BerryLuaWraper instance;
	return &instance;
}

BerryLuaWraper::BerryLuaWraper()
{
	m_L = luaL_newstate();
	luaL_openlibs(m_L);
	OpenBerryLib(m_L);
}

BerryLuaWraper::~BerryLuaWraper()
{
	lua_close(m_L);
}
		
void BerryLuaWraper::ExecuteString(const char* luaCode)
{
	luaL_dostring(m_L, luaCode);
}

void BerryLuaWraper::ExecuteFile(const char* luaFilePath)
{
	luaL_dofile(m_L, luaFilePath);
}

/*
c++ µ÷ÓÃ  lua 
https://www.cnblogs.com/slysky/p/7890738.html
*/
void BerryLuaWraper::TestCallLua()
{
	luaL_loadfile(m_L, "test.lua");
	int ret = lua_pcall(m_L, 0, 0, 0);
	if (ret != LUA_OK)
	{
		printf("xxx\n");
	}
	
	int tp = lua_getglobal(m_L, "abc");
	std::string abc = lua_tostring(m_L, -1);
	printf("%s\n",abc.c_str());

	//lua_settop(m_L, 0);

	lua_getglobal(m_L, "tbl");
	lua_getfield(m_L, -1, "name");
	std::string name = lua_tostring(m_L, -1);
	lua_getfield(m_L, -2, "age");
	int age = lua_tointeger(m_L, -1);
	printf("[name]%s [age]%d\n",name.c_str(),age);

}

void BerryLuaWraper::RegisterLogFunc(LogFuncProto func)
{
	m_logFunc = func;
}

void BerryLuaWraper::Log(const char* log)
{
	if (m_logFunc != nullptr)
	{
		m_logFunc(log);
	}
}

std::string BerryLuaWraper::DumpStack(lua_State* L)
{
	int stackSize = lua_gettop(L);
	std::string allInfo;
	for (int index = 1; index <= stackSize; index++)
	{
		int t = lua_type(L, index);
		std::string strInfo;

		switch (t)
		{
			case LUA_TSTRING:
			{
				strInfo = lua_tostring(L, index);
				break;
			}
			case LUA_TBOOLEAN:
			{
				strInfo = lua_toboolean(L, index) ? "true" : "false";
				break;
			}
			case LUA_TNUMBER:
			{
				lua_Number result = lua_tonumber(L, index);
				std::stringstream ss;
				ss << result;
				ss >> strInfo;
				break;
			}
			default:
			{
				strInfo = lua_typename(L, index);
				break;
			}
		};
		allInfo = allInfo + strInfo.c_str() + "\n";
		printf("%s\t", strInfo.c_str());
	}
	printf("\n");
	return allInfo;
	
}
