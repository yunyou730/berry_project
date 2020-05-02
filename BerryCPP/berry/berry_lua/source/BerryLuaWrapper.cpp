#include "BerryLuaWrapper.h"

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
}

BerryLuaWraper::~BerryLuaWraper()
{
	lua_close(m_L);
}
		
void BerryLuaWraper::ExecuteString(const char* luaCode)
{
	luaL_dostring(m_L, luaCode);
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
