#include <iostream>
#include <bitset>
#include "command_list.h"

using namespace std;






int main()
{

    command_list test;

    test.add(0);

    test.add(1);

    test.add(2);

    test.add(3);

    test.add(4);

    test.debag_print();


    return 0;
}
