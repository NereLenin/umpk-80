#ifndef EMULATOR_H
#define EMULATOR_H

#include "hex.h"
#include "command_list.h"
class emulator
{
private:
    command_list list;

    hexes A;

    //couple BC
    hexes B,C;

    //couple
    hexes D,E;

    //couple
    hexes H,L;

    //especial virtual registr
    hexes M;

    void MOV(char,char);
    //R,R / R,M

    void MVI(char,hexes*);
    //R,value

    void ADD(char);

public:
    int point;

    void add(command_list*);
    void add_from_file(char *path);

    void start(int);
    void start();

    void print_list();
    void print_flags();
    void pring_registers();

    emulator();
};

#endif // EMULATOR_H
