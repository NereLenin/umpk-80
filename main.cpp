#include <iostream>
#include <bitset>
#include "emulator.h"

using namespace std;






int main()
{

    emulator test;

    cout << "First empty emulator" << endl;
    test.print_flags();
    test.print_registers();
    test.print_list();


    cout << endl<< "add commands" << endl;
    test.add_cmd(6);
    test.add_cmd(255);
    test.add_cmd(120);

    test.print_list();

    cout << endl<< "First iteration" << endl;

    test.iteration();
    test.print_registers();

    cout << endl << "Second iteration" << endl;
    test.iteration();
    test.print_registers();


    return 0;
}
