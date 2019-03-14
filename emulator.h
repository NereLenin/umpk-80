#ifndef EMULATOR_H
#define EMULATOR_H

#include "msg_error.h"

#include "command_list.h"

#include <stack>

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

    void(emulator::*cmd_methods[125])(void);

    bool stop_flag;

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

    std::stack<hex_couple> emul_stack;


    void add_cmd_methods(int &all_cmd, void (emulator::*func)() )
    {
        cmd_methods[all_cmd] = func;
        all_cmd++;
    }




    void init_umpk_cmd_list();

    void dcr_hex_couple(hexes &A1, hexes &A2);
    void inr_hex_couple(hexes &A1, hexes &A2);

    hexes& get_cell(hexes &A1, hexes &A2);

    void set_add(hexes &A1, hexes &A2, hexes &value);


    void JMP(const bool &flag);


    void MOV(hexes& R1,hexes& R2);//p

    void MVI(hexes& R);//p

    void ADD(hexes& R);//p

    void ADI();

    void SUB(hexes& R);

    void SUI();

    void DCR(hexes &R);
    void INR(hexes &R);

    void LDA();

    void STA();

    void LXI(hexes &R1, hexes &R2);

    void LDAX(hexes &R1, hexes &R2);
    void STAX(hexes &R1, hexes &R2);

    void RST1();





    int hex_couple_to_int(hexes &A1, hexes &A2);


    //mov

    void MOV_A_A() { MOV(A,A);}
    void MOV_A_B() { MOV(A,B);}
    void MOV_A_C() { MOV(A,C);}
    void MOV_A_D() { MOV(A,D);}
    void MOV_A_E() { MOV(A,E);}
    void MOV_A_H() { MOV(A,H);}
    void MOV_A_L() { MOV(A,B);}
    void MOV_A_M() { MOV(A, get_cell(H,L));}//mov a m

    void MOV_B_A() { MOV(B,A);}
    void MOV_B_B() { MOV(B,B);}
    void MOV_B_C() { MOV(B,C);}
    void MOV_B_D() { MOV(B,D);}
    void MOV_B_E() { MOV(B,E);}
    void MOV_B_H() { MOV(B,H);}
    void MOV_B_L() { MOV(B,L);}
    void MOV_B_M() { MOV(B, get_cell(H,L));}//mov b m

    void MOV_C_A() { MOV(C,A);}
    void MOV_C_B() { MOV(C,B);}
    void MOV_C_C() { MOV(C,C);}
    void MOV_C_D() { MOV(C,D);}
    void MOV_C_E() { MOV(C,E);}
    void MOV_C_H() { MOV(C,H);}
    void MOV_C_L() { MOV(C,L);}
    void MOV_C_M() { MOV(C, get_cell(H,L));}//mov c m

    void MOV_D_A() { MOV(D,A);}
    void MOV_D_B() { MOV(D,B);}
    void MOV_D_C() { MOV(D,C);}
    void MOV_D_D() { MOV(D,D);}
    void MOV_D_E() { MOV(D,E);}
    void MOV_D_H() { MOV(D,H);}
    void MOV_D_L() { MOV(D,L);}
    void MOV_D_M() { MOV(D, get_cell(H,L));}    // mov d m

    void MOV_E_A() { MOV(E,A);}
    void MOV_E_B() { MOV(E,B);}
    void MOV_E_C() { MOV(E,C);}
    void MOV_E_D() { MOV(E,D);}
    void MOV_E_E() { MOV(E,E);}
    void MOV_E_H() { MOV(E,H);}
    void MOV_E_L() { MOV(E,L);}
    void MOV_E_M() { MOV(E, get_cell(H,L));}//mov e m

    void MOV_H_A() { MOV(H,A);}
    void MOV_H_B() { MOV(H,B);}
    void MOV_H_C() { MOV(H,C);}
    void MOV_H_D() { MOV(H,D);}
    void MOV_H_E() { MOV(H,E);}
    void MOV_H_H() { MOV(H,H);}
    void MOV_H_L() { MOV(H,L);}
    void MOV_H_M() { MOV(H, get_cell(H,L));}//mov h m

    void MOV_L_A() { MOV(L,A);}
    void MOV_L_B() { MOV(L,B);}
    void MOV_L_C() { MOV(L,C);}
    void MOV_L_D() { MOV(L,D);}
    void MOV_L_E() { MOV(L,E);}
    void MOV_L_H() { MOV(L,H);}
    void MOV_L_L() { MOV(L,L);}
    void MOV_L_M() { MOV(L, get_cell(H,L));}//mov l m

    // mov m r
    void MOV_M_A() { set_add(H,L,A);}
    void MOV_M_B() { set_add(H,L,B);}
    void MOV_M_C() { set_add(H,L,C);}
    void MOV_M_D() { set_add(H,L,D);}
    void MOV_M_E() { set_add(H,L,E);}
    void MOV_M_H() { set_add(H,L,H);}
    void MOV_M_L() { set_add(H,L,L);}

    void MVI_A() { MVI(A);}
    void MVI_B() { MVI(B);}
    void MVI_C() { MVI(C);}
    void MVI_D() { MVI(D);}
    void MVI_E() { MVI(E);}
    void MVI_H() { MVI(H);}
    void MVI_L() { MVI(L);}
    void MVI_M() { MVI(get_cell(H,L));}
    //mvi m

    void ADD_A() { ADD(A);}
    void ADD_B() { ADD(B);}
    void ADD_C() { ADD(C);}
    void ADD_D() { ADD(D);}
    void ADD_E() { ADD(E);}
    void ADD_H() { ADD(H);}
    void ADD_L() { ADD(L);}
    void ADD_M() { ADD(get_cell(H,L));}
    //add m


    void SUB_A() { SUB(A);}
    void SUB_B() { SUB(B);}
    void SUB_C() { SUB(C);}
    void SUB_D() { SUB(D);}
    void SUB_E() { SUB(E);}
    void SUB_H() { SUB(H);}
    void SUB_L() { SUB(L);}
    void SUB_M() { SUB(get_cell(H,L));}
    //SUB m

    //DCR
    void DCR_A() { DCR(A);}
    void DCR_B() { DCR(B);}
    void DCR_C() { DCR(C);}
    void DCR_D() { DCR(D);}
    void DCR_E() { DCR(E);}
    void DCR_H() { DCR(H);}
    void DCR_L() { DCR(L);}
    void DCR_M() { DCR(get_cell(H,L));}

    //DCX

    void DCX_B(){dcr_hex_couple(B,C);point++;}

    void DCX_D(){dcr_hex_couple(D,E);point++;}

    void DCX_H(){dcr_hex_couple(H,L);point++;}
    //dcx sp

    //INR
    void INR_A() { INR(A);}
    void INR_B() { INR(B);}
    void INR_C() { INR(C);}
    void INR_D() { INR(D);}
    void INR_E() { INR(E);}
    void INR_H() { INR(H);}
    void INR_L() { INR(L);}
    void INR_M() { INR(get_cell(H,L));}

    //DCX

    void INX_B(){inr_hex_couple(B,C);point++;}

    void INX_D(){inr_hex_couple(D,E);point++;}

    void INX_H(){inr_hex_couple(H,L);point++;}
    //inx sp

    //lxi
    void LXI_B(){LXI(B,C);}
    void LXI_D(){LXI(D,E);}
    void LXI_H(){LXI(H,L);}
    //void LXI_SP

    //ldax

    void LDAX_B(){LDAX(B,C);}
    void LDAX_D(){LDAX(D,E);}

    //stax

    void STAX_B(){LDAX(B,C);}
    void STAX_D(){LDAX(D,E);}

    //lhld


    //shld


    //xchg


    //jamp

    void JZ(){JMP(Z);}
    void JNZ(){JMP(!Z);}

    void JC(){ JMP(Cy); }
    void JNC(){ JMP(!Cy); }

    void JMP();

    //flags
    bool Cy;
    bool Z;
    bool P;

    void add_cmd(int);//delete?
    void add_cmd(const hexes&);
    void add_cmd(const std::string&);
    void add_cmd(const char*);

public:

    int point;

    emulator();

    //set get point
    void add(const command_list&);
    void add_from_file(char *path);


    void add_cmd(const char* addr, const char* value);

    void start_from_point();
    void start();

    void iteration();

    void print_list();
    void print_flags();
    void print_registers();


};

#endif // EMULATOR_H
