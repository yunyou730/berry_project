#pragma once

extern "C"
{
#include "../lua-5.3.5/lua.h"
#include "../lua-5.3.5/lualib.h"
#include "../lua-5.3.5/lauxlib.h"
}


extern void OpenBerryLib(lua_State* L);

static int create_berry_object(lua_State* L);
static int delete_berry_object(lua_State* L);
static int test_lua_call_cpp(lua_State* L);
static int create_berry_object2(lua_State* L);

class BerryObject
{
public:
	BerryObject();
	BerryObject(int nNum,const char* str);
	~BerryObject();

	int GetNum() const { return m_nNum; }
	const char* GetStr() { return m_strTest; }
private:
	int		m_nNum;
	const char* m_strTest;
	//int		m_testplace[200];
};
