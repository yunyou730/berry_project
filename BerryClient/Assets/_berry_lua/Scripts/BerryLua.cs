using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;

public class BerryLua
{
#if UNITY_IPHONE
    [DllImport("__Internal")]
#else
    [DllImport("berry_lua")]
#endif
    public static extern int berry_test_1(int n1, int n2);

}
