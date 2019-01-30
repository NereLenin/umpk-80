#include <iostream>
#include <bitset>
#include "emulator.h"

using namespace std;



int main()
{

    hexes one("08");
    hexes two("00");

    hexes value("FF");

    emulator test;

    test.add_cmd("01");
    test.add_cmd("02");
    test.add_cmd("03");
    test.add_cmd("04");

    test.set_add(one,two,value);

    test.print_list();
    //test.add_cmd("2E");
    //test.add_cmd("FF");
   // test.add_cmd("85");

    //test.iteration();
    //test.iteration();

    //test.print_registers();
    //test.print_flags();

    return 0;
}
