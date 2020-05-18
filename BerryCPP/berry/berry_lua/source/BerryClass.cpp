#include "BerryClass.h"
#include "BerryLuaWrapper.h"

void OpenBerryLib(lua_State* L)
{
	lua_pushcfunction(L, create_berry_object);
	lua_setglobal(L, "create_berry_object");

	lua_pushcfunction(L, delete_berry_object);
	lua_setglobal(L, "delete_berry_object");

	lua_pushcfunction(L, test_lua_call_cpp);
	lua_setglobal(L, "test_lua_call_cpp");

	lua_pushcfunction(L, create_berry_object2);
	lua_setglobal(L, "create_berry_object2");
}

static int create_berry_object(lua_State* L)
{
	double num = lua_tonumber(L, 1);
	const char* str = lua_tostring(L, 2);
	BerryObject* berryObject = new BerryObject((int)num,str);
	lua_pushlightuserdata(L, berryObject);
	return 1;
}

static int delete_berry_object(lua_State* L)
{
	BerryObject* berryObject = (BerryObject*)(lua_touserdata(L, 1));
	delete berryObject;
	return 0;
}

/*
c++ ×¢²áÀàµ½ lua
https://www.cnblogs.com/afan/p/6179720.html
*/
static int create_berry_object2(lua_State* L)
{
	// @miao @todo
	BerryObject* obj = new BerryObject();
	size_t size1 = sizeof(BerryObject*);
	size_t size2 = sizeof(BerryObject);
	size_t size3 = sizeof(obj);
	
	lua_newuserdata(L, sizeof(BerryObject));

	return 1;
}

static int test_lua_call_cpp(lua_State* L)
{
	// @miao @temp
	//berry::BerryLuaWraper::DumpStack(L);

	int stackSize = lua_gettop(L);
	if (stackSize >= 3)
	{
		//berry::BerryLuaWraper::DumpStack(L);
		lua_getfield(L, 3, "syz");
		//berry::BerryLuaWraper::DumpStack(L);
	}

	//lua_pushglobaltable

	lua_newtable(L);

	lua_pushstring(L,"key");
	lua_pushstring(L,"value");
	lua_settable(L, -3);

	lua_pushstring(L, "key2");
	lua_pushboolean(L, false);
	lua_settable(L, -3);
	
	stackSize = lua_gettop(L);
	return stackSize;
}

BerryObject::BerryObject()
	:m_nNum(100)
	,m_strTest("test1")
{

}

BerryObject::BerryObject(int nNum, const char* str)
	:m_nNum(nNum)
	,m_strTest(str)
{

}

BerryObject::~BerryObject()
{
	printf("BerryObject::~BerryObject()\n");
}
