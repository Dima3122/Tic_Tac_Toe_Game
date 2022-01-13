#include <iostream>
#include "My_String.h"

int main()
{
    My_String str("TEST");
    My_String str2("TEST2");
    str = str2;
    std::cout << str << std::endl;
    bool first = true;
    first = str == str2;
    std::cout << first << std::endl;
    My_String str3 = str + str2;
    std::cout << str3.get_str() << std::endl;
    first = str3 == str2;
    std::cout << first << std::endl;
    first = str3 != str2;
    std::cout << first << std::endl;
    return 0;
}