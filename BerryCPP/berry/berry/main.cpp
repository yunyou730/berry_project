#include <iostream>
#include "../berry_lua/include/berry_lua_entry.h"

int main()
{
    int n = berry_test_1(3, 5);
    printf("%d\n",n);
    berry_test_lua_1("for i = 1,5 do\nprint(i)\nend");
    berry_register_log_func([](const char* info) {
        printf(info);
    });
    berry_test_call_c_sharp_back("$$$$");
    return 0;
}
