#include <iostream>
#include <bitset>
#include "emulator.h"

using namespace std;



int main()
{

    emulator test;

    test.add_cmd("2E");
    test.add_cmd("FF");
    test.add_cmd("85");

    test.iteration();
    test.iteration();

    test.print_registers();
    test.print_flags();

    return 0;
}
