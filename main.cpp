#include <iostream>
#include <bitset>
#include "emulator.h"

using namespace std;



int main()
{

    hexes one("FF");
    hexes two("FF");

    hexes value("FF");

    emulator test;

    test.add_cmd("0800","0E");//mvi c
    test.add_cmd("0801","04");
    test.add_cmd("0802","21");//lxi h
    test.add_cmd("0803","0E");
    test.add_cmd("0804","08");
    test.add_cmd("0805","36");//mvi m
    test.add_cmd("0806","FF");
    test.add_cmd("0807","23");//inx hl
    test.add_cmd("0808","0D");//dcr c
    test.add_cmd("0809","C2");//JNZ
    test.add_cmd("080A","05");
    test.add_cmd("080B","08");
    test.add_cmd("080C","CF");

    /*test.iteration();
    test.print_flags();
    test.print_registers();

    test.iteration();
    test.print_flags();
    test.print_registers();

    test.iteration();
    test.print_flags();
    test.print_registers();

    test.iteration();
    test.print_flags();
    test.print_registers();

    test.iteration();
    test.print_flags();
    test.print_registers();

    test.iteration();
    test.print_flags();
    test.print_registers();

    test.iteration();
    test.print_flags();
    test.print_registers();

*/
    test.start();

//    test.print_list();

    return 0;
}
