using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TestDLLCall : MonoBehaviour
{
    public int num = 0;
    // Start is called before the first frame update
    void Start()
    {
        num = BerryLua.berry_test_1(1, 3);
        BerryLua.ExcuteLuaFile("main.lua");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
