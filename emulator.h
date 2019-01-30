#ifndef EMULATOR_H
#define EMULATOR_H

#include "hex.h"
#include "command_list.h"
class emulator;


class emulator
{
private:
    command_list list;

    command_list umpk_cmd_list; //p
    //maybe will be better to do it static?

    //all availible?
    int all_cmd; //чтобы знать сколько у нас вообще команд, не в листе, а реализованно и поддерживается эмулятором

//    typedef void (emulator::*srch_fnc)(void);
//    srch_fnc cmd_methods[3];

    void(emulator::*cmd_methods[72])(void);


    //accum
    hexes A;


    //couple BC
    hexes B,C;

    //couple
    hexes D,E;

    //couple
    hexes H,L;

    //especial virtual registr
   // hexes M;

    void add_cmd_methods(int &all_cmd, void (emulator::*func)() )
    {
        cmd_methods[all_cmd] = func;
        all_cmd++;

    }

    void MOV(hexes& R1,hexes& R2);//p

    void MVI(hexes& R);//p

    void ADD(hexes& R);//p

    void ADI();

    void SUB(hexes& R);

    void SUI();

    int hex_couple_to_int(hexes &A1, hexes &A2);


    //mov

    void MOV_A_A() { MOV(A,A);}
    void MOV_A_B() { MOV(A,B);}
    void MOV_A_C() { MOV(A,C);}
    void MOV_A_D() { MOV(A,D);}
    void MOV_A_E() { MOV(A,E);}
    void MOV_A_H() { MOV(A,H);}
    void MOV_A_L() { MOV(A,B);}
    //mov a m

    void MOV_B_A() { MOV(B,A);}
    void MOV_B_B() { MOV(B,B);}
    void MOV_B_C() { MOV(B,C);}
    void MOV_B_D() { MOV(B,D);}
    void MOV_B_E() { MOV(B,E);}
    void MOV_B_H() { MOV(B,H);}
    void MOV_B_L() { MOV(B,L);}
    //mov b m

    void MOV_C_A() { MOV(C,A);}
    void MOV_C_B() { MOV(C,B);}
    void MOV_C_C() { MOV(C,C);}
    void MOV_C_D() { MOV(C,D);}
    void MOV_C_E() { MOV(C,E);}
    void MOV_C_H() { MOV(C,H);}
    void MOV_C_L() { MOV(C,L);}
    //mov c m

    void MOV_D_A() { MOV(D,A);}
    void MOV_D_B() { MOV(D,B);}
    void MOV_D_C() { MOV(D,C);}
    void MOV_D_D() { MOV(D,D);}
    void MOV_D_E() { MOV(D,E);}
    void MOV_D_H() { MOV(D,H);}
    void MOV_D_L() { MOV(D,L);}
    // mov d m

    void MOV_E_A() { MOV(E,A);}
    void MOV_E_B() { MOV(E,B);}
    void MOV_E_C() { MOV(E,C);}
    void MOV_E_D() { MOV(E,D);}
    void MOV_E_E() { MOV(E,E);}
    void MOV_E_H() { MOV(E,H);}
    void MOV_E_L() { MOV(E,L);}
    //mov e m

    void MOV_H_A() { MOV(H,A);}
    void MOV_H_B() { MOV(H,B);}
    void MOV_H_C() { MOV(H,C);}
    void MOV_H_D() { MOV(H,D);}
    void MOV_H_E() { MOV(H,E);}
    void MOV_H_H() { MOV(H,H);}
    void MOV_H_L() { MOV(H,L);}
    //mov h m

    void MOV_L_A() { MOV(L,A);}
    void MOV_L_B() { MOV(L,B);}
    void MOV_L_C() { MOV(L,C);}
    void MOV_L_D() { MOV(L,D);}
    void MOV_L_E() { MOV(L,E);}
    void MOV_L_H() { MOV(L,H);}
    void MOV_L_L() { MOV(L,L);}
    //mov l m

    // mov m r

    void MVI_A() { MVI(A);}
    void MVI_B() { MVI(B);}
    void MVI_C() { MVI(C);}
    void MVI_D() { MVI(D);}
    void MVI_E() { MVI(E);}
    void MVI_H() { MVI(H);}
    void MVI_L() { MVI(L);}
    //mvi m

    void ADD_A() { ADD(A);}
    void ADD_B() { ADD(B);}
    void ADD_C() { ADD(C);}
    void ADD_D() { ADD(D);}
    void ADD_E() { ADD(E);}
    void ADD_H() { ADD(H);}
    void ADD_L() { ADD(L);}
    //add m


    void SUB_A() { SUB(A);}
    void SUB_B() { SUB(B);}
    void SUB_C() { SUB(C);}
    void SUB_D() { SUB(D);}
    void SUB_E() { SUB(E);}
    void SUB_H() { SUB(H);}
    void SUB_L() { SUB(L);}
    //SUB m


    //mvi

    //flags
    bool Cy;
    bool Z;
    bool P;


    void init_umpk_cmd_list();
public:


    hexes& get_cell(hexes &A1, hexes &A2);

    void set_add(hexes &A1, hexes &A2, hexes &value);

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
