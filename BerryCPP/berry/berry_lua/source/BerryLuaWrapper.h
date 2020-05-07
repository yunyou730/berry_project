#pragma once


extern "C"
{
#include "../lua-5.3.5/lua.h"
#include "../lua-5.3.5/lualib.h"
#include "../lua-5.3.5/lauxlib.h"
}

#include "../include/berry_lua_entry.h"

namespace berry
{
	class BerryLuaWraper
	{
	public:
		static BerryLuaWraper* GetInstance();
		virtual ~BerryLuaWraper();

		void ExecuteString(const char* luaCode);
		void RegisterLogFunc(LogFuncProto func);
		void Log(const char* log);


		void ExecuteFile(const char* luaFilePath);

	private:
		BerryLuaWraper();

	private:
		lua_State* m_L = nullptr;
		LogFuncProto	m_logFunc = nullptr;
	};
}