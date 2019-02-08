#include "emulator.h"


void emulator::print_registers()
{
    std::cout << "A: ";
    A.print_bin();


    std::cout << "B: ";
    B.print_bin();


    std::cout << "C: ";
    C.print_bin();


    std::cout << "D: ";
    D.print_bin();


    std::cout << "E: ";
    E.print_bin();


    std::cout << "H: ";
    H.print_bin();


    std::cout << "L: ";
    L.print_bin();
}

void emulator::print_flags()
{
    std::cout << "Z: " << Z << " C: " << Cy << " P: " << P << std::endl;
}


void emulator::add_cmd(int value)
{
    list.add(value);
}

void emulator::add_cmd(const hexes& value)
{
    list.add(value);
}

void emulator::add_cmd(const char* value)
{
    list.add(value);
}


emulator::emulator()
{
    A = 0;

    B = 0;
    C = 0;

    D = 0;
    E = 0;

    H = 0;
    L = 0;

    Cy = Z = P = 0;

    point = 0;

    all_cmd = 0;
    init_umpk_cmd_list();

}

void emulator::print_list()
{
    list.print();
}

void emulator::init_umpk_cmd_list()
{
    all_cmd = 0;//сколько всего команд в эмуляторе


    //MOV A

    umpk_cmd_list.add("7F");
    add_cmd_methods(all_cmd,(&emulator::MOV_A_A));

    umpk_cmd_list.add("78");
    add_cmd_methods(all_cmd,(&emulator::MOV_A_B));

    umpk_cmd_list.add("79");
    add_cmd_methods(all_cmd,(&emulator::MOV_A_C));

    umpk_cmd_list.add("7A");
    add_cmd_methods(all_cmd,(&emulator::MOV_A_D));

    umpk_cmd_list.add("7B");
    add_cmd_methods(all_cmd,(&emulator::MOV_A_E));


    umpk_cmd_list.add("7C");
    add_cmd_methods(all_cmd,(&emulator::MOV_A_H));

    umpk_cmd_list.add("7D");
    add_cmd_methods(all_cmd,(&emulator::MOV_A_L));

    umpk_cmd_list.add("7E");
    add_cmd_methods(all_cmd,(&emulator::MOV_A_M));//MOV A,M

    //MOV B

    umpk_cmd_list.add("47");
    add_cmd_methods(all_cmd,(&emulator::MOV_B_A));

    umpk_cmd_list.add("40");
    add_cmd_methods(all_cmd,(&emulator::MOV_B_B));

    umpk_cmd_list.add("41");
    add_cmd_methods(all_cmd,(&emulator::MOV_B_C));

    umpk_cmd_list.add("42");
    add_cmd_methods(all_cmd,(&emulator::MOV_B_D));

    umpk_cmd_list.add("43");
    add_cmd_methods(all_cmd,(&emulator::MOV_B_E));

    umpk_cmd_list.add("44");
    add_cmd_methods(all_cmd,(&emulator::MOV_B_H));

    umpk_cmd_list.add("45");
    add_cmd_methods(all_cmd,(&emulator::MOV_B_L));

    umpk_cmd_list.add("46");
    add_cmd_methods(all_cmd,(&emulator::MOV_B_M));//MOV B,M


    //MOV C

    umpk_cmd_list.add("4F");
    add_cmd_methods(all_cmd,(&emulator::MOV_C_A));

    umpk_cmd_list.add("48");
    add_cmd_methods(all_cmd,(&emulator::MOV_C_B));

    umpk_cmd_list.add("49");
    add_cmd_methods(all_cmd,(&emulator::MOV_C_C));

    umpk_cmd_list.add("4A");
    add_cmd_methods(all_cmd,(&emulator::MOV_C_D));

    umpk_cmd_list.add("4B");
    add_cmd_methods(all_cmd,(&emulator::MOV_C_E));

    umpk_cmd_list.add("4C");
    add_cmd_methods(all_cmd,(&emulator::MOV_C_H));

    umpk_cmd_list.add("4D");
    add_cmd_methods(all_cmd,(&emulator::MOV_C_L));

    umpk_cmd_list.add("4E");
    add_cmd_methods(all_cmd,(&emulator::MOV_C_M));//MOV C,M

    //MOV D

    umpk_cmd_list.add("57");
    add_cmd_methods(all_cmd,(&emulator::MOV_D_A));

    umpk_cmd_list.add("50");
    add_cmd_methods(all_cmd,(&emulator::MOV_D_B));

    umpk_cmd_list.add("51");
    add_cmd_methods(all_cmd,(&emulator::MOV_D_C));

    umpk_cmd_list.add("52");
    add_cmd_methods(all_cmd,(&emulator::MOV_D_D));

    umpk_cmd_list.add("53");
    add_cmd_methods(all_cmd,(&emulator::MOV_D_E));

    umpk_cmd_list.add("54");
    add_cmd_methods(all_cmd,(&emulator::MOV_D_H));

    umpk_cmd_list.add("55");
    add_cmd_methods(all_cmd,(&emulator::MOV_D_L));

    umpk_cmd_list.add("56");
    add_cmd_methods(all_cmd,(&emulator::MOV_D_M));//MOV D,M


    //MOV E

    umpk_cmd_list.add("5F");
    add_cmd_methods(all_cmd,(&emulator::MOV_E_A));

    umpk_cmd_list.add("58");
    add_cmd_methods(all_cmd,(&emulator::MOV_E_B));

    umpk_cmd_list.add("59");
    add_cmd_methods(all_cmd,(&emulator::MOV_E_C));

    umpk_cmd_list.add("5A");
    add_cmd_methods(all_cmd,(&emulator::MOV_E_D));

    umpk_cmd_list.add("5B");
    add_cmd_methods(all_cmd,(&emulator::MOV_E_E));

    umpk_cmd_list.add("5C");
    add_cmd_methods(all_cmd,(&emulator::MOV_E_H));

    umpk_cmd_list.add("5D");
    add_cmd_methods(all_cmd,(&emulator::MOV_E_L));

    umpk_cmd_list.add("5E");
    add_cmd_methods(all_cmd,(&emulator::MOV_E_M));//MOV E,M


    //MOV H

    umpk_cmd_list.add("67");
    add_cmd_methods(all_cmd,(&emulator::MOV_H_A));

    umpk_cmd_list.add("60");
    add_cmd_methods(all_cmd,(&emulator::MOV_H_B));

    umpk_cmd_list.add("61");
    add_cmd_methods(all_cmd,(&emulator::MOV_H_C));

    umpk_cmd_list.add("62");
    add_cmd_methods(all_cmd,(&emulator::MOV_H_D));

    umpk_cmd_list.add("63");
    add_cmd_methods(all_cmd,(&emulator::MOV_H_E));

    umpk_cmd_list.add("64");
    add_cmd_methods(all_cmd,(&emulator::MOV_H_H));

    umpk_cmd_list.add("65");
    add_cmd_methods(all_cmd,(&emulator::MOV_H_L));

    umpk_cmd_list.add("66");
    add_cmd_methods(all_cmd,(&emulator::MOV_H_M));//MOV H,M

    //MOV L

    umpk_cmd_list.add("6F");
    add_cmd_methods(all_cmd,(&emulator::MOV_L_A));

    umpk_cmd_list.add("68");
    add_cmd_methods(all_cmd,(&emulator::MOV_L_B));

    umpk_cmd_list.add("69");
    add_cmd_methods(all_cmd,(&emulator::MOV_L_C));

    umpk_cmd_list.add("6A");
    add_cmd_methods(all_cmd,(&emulator::MOV_L_D));

    umpk_cmd_list.add("6B");
    add_cmd_methods(all_cmd,(&emulator::MOV_L_E));

    umpk_cmd_list.add("6C");
    add_cmd_methods(all_cmd,(&emulator::MOV_L_H));

    umpk_cmd_list.add("6D");
    add_cmd_methods(all_cmd,(&emulator::MOV_L_L));

    umpk_cmd_list.add("6E");
    add_cmd_methods(all_cmd,(&emulator::MOV_L_M));//MOV L,M

    //MOV M

    umpk_cmd_list.add("77");
    add_cmd_methods(all_cmd,(&emulator::MOV_M_A));

    umpk_cmd_list.add("70");
    add_cmd_methods(all_cmd,(&emulator::MOV_M_B));

    umpk_cmd_list.add("71");
    add_cmd_methods(all_cmd,(&emulator::MOV_M_C));

    umpk_cmd_list.add("72");
    add_cmd_methods(all_cmd,(&emulator::MOV_M_D));

    umpk_cmd_list.add("73");
    add_cmd_methods(all_cmd,(&emulator::MOV_M_E));

    umpk_cmd_list.add("74");
    add_cmd_methods(all_cmd,(&emulator::MOV_M_H));

    umpk_cmd_list.add("75");
    add_cmd_methods(all_cmd,(&emulator::MOV_M_L));

    //MVI R
    umpk_cmd_list.add("3E");
    add_cmd_methods(all_cmd,(&emulator::MVI_A));

    umpk_cmd_list.add("06");
    add_cmd_methods(all_cmd,(&emulator::MVI_B));

    umpk_cmd_list.add("0E");
    add_cmd_methods(all_cmd,(&emulator::MVI_C));

    umpk_cmd_list.add("16");
    add_cmd_methods(all_cmd,(&emulator::MVI_D));

    umpk_cmd_list.add("1E");
    add_cmd_methods(all_cmd,(&emulator::MVI_E));

    umpk_cmd_list.add("26");
    add_cmd_methods(all_cmd,(&emulator::MVI_H));

    umpk_cmd_list.add("2E");
    add_cmd_methods(all_cmd,(&emulator::MVI_L));

    umpk_cmd_list.add("36");
    add_cmd_methods(all_cmd,(&emulator::MVI_M));//MVI M

    //ADD R
    umpk_cmd_list.add("87");
    add_cmd_methods(all_cmd,(&emulator::ADD_A));

    umpk_cmd_list.add("80");
    add_cmd_methods(all_cmd,(&emulator::ADD_B));

    umpk_cmd_list.add("81");
    add_cmd_methods(all_cmd,(&emulator::ADD_C));

    umpk_cmd_list.add("82");
    add_cmd_methods(all_cmd,(&emulator::ADD_D));

    umpk_cmd_list.add("83");
    add_cmd_methods(all_cmd,(&emulator::ADD_E));

    umpk_cmd_list.add("84");
    add_cmd_methods(all_cmd,(&emulator::ADD_H));

    umpk_cmd_list.add("85");
    add_cmd_methods(all_cmd,(&emulator::ADD_L));

    umpk_cmd_list.add("86");
    add_cmd_methods(all_cmd,(&emulator::ADD_M));//ADD M

    //ADI
    umpk_cmd_list.add("C6");
    add_cmd_methods(all_cmd,(&emulator::ADI));


    //SUB A
    umpk_cmd_list.add("97");
    add_cmd_methods(all_cmd,(&emulator::SUB_A));

    umpk_cmd_list.add("90");
    add_cmd_methods(all_cmd,(&emulator::SUB_B));

    umpk_cmd_list.add("91");
    add_cmd_methods(all_cmd,(&emulator::SUB_C));

    umpk_cmd_list.add("92");
    add_cmd_methods(all_cmd,(&emulator::SUB_D));

    umpk_cmd_list.add("93");
    add_cmd_methods(all_cmd,(&emulator::SUB_E));

    umpk_cmd_list.add("94");
    add_cmd_methods(all_cmd,(&emulator::SUB_H));

    umpk_cmd_list.add("95");
    add_cmd_methods(all_cmd,(&emulator::SUB_L));

    umpk_cmd_list.add("96");
    add_cmd_methods(all_cmd,(&emulator::SUB_M));//sub m

    //DCR R
    umpk_cmd_list.add("3D");
    add_cmd_methods(all_cmd,(&emulator::DCR_A));

    umpk_cmd_list.add("05");
    add_cmd_methods(all_cmd,(&emulator::DCR_B));

    umpk_cmd_list.add("0D");
    add_cmd_methods(all_cmd,(&emulator::DCR_C));

    umpk_cmd_list.add("15");
    add_cmd_methods(all_cmd,(&emulator::DCR_D));

    umpk_cmd_list.add("1D");
    add_cmd_methods(all_cmd,(&emulator::DCR_E));

    umpk_cmd_list.add("25");
    add_cmd_methods(all_cmd,(&emulator::DCR_H));

    umpk_cmd_list.add("2D");
    add_cmd_methods(all_cmd,(&emulator::DCR_L));

    umpk_cmd_list.add("35");
    add_cmd_methods(all_cmd,(&emulator::DCR_M));//DCR m


    //DCX R
    umpk_cmd_list.add("0B");
    add_cmd_methods(all_cmd,(&emulator::DCX_B));

    umpk_cmd_list.add("1B");
    add_cmd_methods(all_cmd,(&emulator::DCX_D));

    umpk_cmd_list.add("2B");
    add_cmd_methods(all_cmd,(&emulator::DCX_H));

    //DCX SP

   // std::cout << all_cmd << std::endl;


}

void emulator::iteration()
{
    for(int i =0; i<all_cmd; i++)//проходим по всем командам
        if(list[point] == umpk_cmd_list[i])//
        {
            (this->*cmd_methods[i])();

            if(A==0) Z=1;
            else Z=0;

            return;
        }

    std::cout << "cmd not found" << std::endl;

}


//-----------------------------------//

//flag Z

void emulator::MOV(hexes& R1, hexes& R2){
    R1 = R2;
    point++;
}

void emulator::MVI(hexes& R){
    point++;
    R = list[point];
    point++;
}

void emulator::ADD(hexes& R)
{
    if(A.to_int() + R.to_int()>255) Cy=1;

    A = (A+R);

    point++;
}

void emulator::ADI(){
    point++;

    ADD(list[point]);

    point++;
}

void emulator::SUB(hexes& R)
{
    if(A.to_int() - R.to_int()<0)
        Cy=1;

    A = (A-R);


    point++;
}

void emulator::SUI(){
    point++;
    SUB(list[point]);
    point++;
}

void emulator::DCR(hexes& R){
   R = R + 1;
}

int emulator::hex_couple_to_int(hexes &A1, hexes &A2)
{
    std::bitset<16> *temp = new std::bitset<16>;

    for(unsigned long i=0;i<8;i++)
        temp->operator[](i) = A2.b[i];

    for(unsigned long i=8;i<16;i++)
        temp->operator[](i) = A1.b[i-8];

    int new_point = static_cast<int>(temp->to_ulong());

    delete temp;

    if(new_point <2048 || new_point>2944)
    {
        std::cout << "adress not exist" << std::endl;
        return -1;
    }

    new_point-=2048;
    return new_point;
}

void emulator::dcr_hex_couple(hexes &A1, hexes &A2)
{
    std::bitset<16> *temp = new std::bitset<16>;

    for(unsigned long i=0;i<8;i++)
        temp->operator[](i) = A2.b[i];

    for(unsigned long i=8;i<16;i++)
        temp->operator[](i) = A1.b[i-8];

    *temp = temp->to_ulong() + 1;

    for(unsigned long i=0;i<8;i++)
        A2.b[i] = temp->operator[](i);

    for(unsigned long i=8;i<16;i++)
        A1.b[i-8] = temp->operator[](i);

    delete temp;
}

void emulator::set_add(hexes &A1, hexes &A2, hexes &value)
{
    int new_point = hex_couple_to_int(A1,A2);
    if(new_point < 0)
        std::cout << "Нет такого адресса" << std::endl;
    else
        list[new_point] = value;
}

hexes &emulator::get_cell(hexes &A1, hexes &A2)
{
    int new_point = hex_couple_to_int(A1,A2);
    if(new_point < 0)
    {
        std::cout << "Нет такого адресса" << std::endl;
        return  list[point];
    }
    else
    return list[new_point];
}

