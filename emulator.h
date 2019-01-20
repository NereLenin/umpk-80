#ifndef EMULATOR_H
#define EMULATOR_H

#include "hex.h"
#include "command_list.h"
class emulator;


class emulator
{
private:
    command_list list;

    command_list umpk_cmd_list; //maybe will be better to do it static?

    //all availible?
    int all_cmd; //чтобы знать сколько у нас вообще команд, не в листе, а реализованно и поддерживается эмулятором

//    typedef void (emulator::*srch_fnc)(void);
//    srch_fnc cmd_methods[3];

    void(emulator::*cmd_methods[2])(void);



    hexes A;

    //couple BC
    hexes B,C;

    //couple
    hexes D,E;

    //couple
    hexes H,L;

    //especial virtual registr
   // hexes M;

    void MOV(hexes& R1,hexes& R2);//p

    void MVI(hexes& R);//p

    void ADD(hexes& R);//p


    //mov
    void MOV_A_B() { MOV(A,B);}


    //mvi
    void MVI_B() { MVI(B);}

    //flags
    bool Cy;
    bool Z;
    bool P;


    void init_umpk_cmd_list();
public:
    int point;

    emulator();

    //set get point
    void add(const command_list&);
    void add_from_file(char *path);

    void add_cmd(int);
    void add_cmd(const hexes&);
    void add_cmd(const std::string&);
    void add_cmd(const char*);

    void start_from_point();
    void start();

    void iteration();

    void print_list();
    void print_flags();
    void print_registers();


};

#endif // EMULATOR_H
