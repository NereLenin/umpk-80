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
   // hexes M;

    void MOV(hexes&,hexes&);//p
    //R,R / R,M

    void MVI(hexes& R);//p
    //R,value

    void ADD(hexes&);//p


    //flags
    bool Cy;
    bool Z;
    bool P;

public:
    int point;

    emulator();

    //set get point
    void add(const command_list&);
    void add_from_file(char *path);

    void add_cmd(int);
    void add_cmd(const hexes&);
    void add_cmd(const std::string&);
    void add_cmd(char[2]);

    void start_from_point();
    void start();

    void iteration();

    void print_list();
    void print_flags();
    void print_registers();


};

#endif // EMULATOR_H
