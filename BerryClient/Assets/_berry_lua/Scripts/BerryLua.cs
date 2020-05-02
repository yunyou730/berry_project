using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;
using System.IO;

public class BerryLua
{

#if UNITY_IPHONE
    private const string LIB_NAME = "__Internal";
#else
    private const string LIB_NAME = "berry_lua";
#endif

    [DllImport(LIB_NAME)]
    public static extern int berry_test_1(int n1, int n2);

    [DllImport(LIB_NAME)]
    public static extern void berry_test_lua_1(string luaCode);

    public static void ExcuteLuaFile(string luaPath)
    {
        string fullPath = Application.streamingAssetsPath + "/Lua/" + luaPath;
        string luaCode = File.ReadAllText(fullPath);
        berry_test_lua_1(luaCode);
    }
}
