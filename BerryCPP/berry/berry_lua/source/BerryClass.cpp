#include "BerryClass.h"

void OpenBerryLib(lua_State* L)
{
	lua_pushcfunction(L, create_berry_object);
	lua_setglobal(L, "create_berry_object");

	lua_pushcfunction(L, delete_berry_object);
	lua_setglobal(L, "delete_berry_object");

}

static int create_berry_object(lua_State* L)
{
	double num = lua_tonumber(L, 1);
	const char* str = lua_tostring(L, 2);
	BerryObject* berryObject = new BerryObject((int)num,str);
	lua_pushlightuserdata(L, berryObject);


	//luaL_newlibtable(L, "");
	
	//lua_newuserdata(L, sizeof(*berryObject));

	//lua_createtable(L,)
	lua_newtable(L);
	lua_setfield(L,-1,"");


	return 1;
}

static int delete_berry_object(lua_State* L)
{
	BerryObject* berryObject = (BerryObject*)(lua_touserdata(L, 1));
	delete berryObject;
	return 0;
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
