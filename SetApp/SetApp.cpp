#include <iostream>
#include "../SetLib/SetLib.h"

int main()
{
    Set set;
    set += 1;
    set += 3;
    set += 4;

    Set set1;
    set1 += 9;
    set1 += 7;

    Set set2 = set + set1;

    Set set3;
    set3 += 5;

    set2 += set3;

    std::cout << set << set1 << set2 << set3;
}

