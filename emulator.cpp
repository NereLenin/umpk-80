#include "emulator.h"


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

    for(int i=0;i<=896;i++)
        add_cmd(0);

    init_umpk_cmd_list();

    stop_flag = 0;
}


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

void emulator::add_cmd(const char* addr, const char* value)
{
    char *one = new char[2];
    char *two = new char[2];

    one[0] = addr[0];one[1] = addr[1];
    two[0] = addr[2];two[1]=addr[3];

    hexes *R1 = new hexes(one);
    hexes *R2 = new hexes(two);
    hexes *cmd = new hexes(value);

    list[hex_couple_to_int(*R1,*R2)] = *cmd;

    delete R1;
    delete R2;
    delete cmd;
    delete[] one;
    delete[] two;
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

    //INR R
    umpk_cmd_list.add("3C");
    add_cmd_methods(all_cmd,(&emulator::INR_A));

    umpk_cmd_list.add("04");
    add_cmd_methods(all_cmd,(&emulator::INR_B));

    umpk_cmd_list.add("0C");
    add_cmd_methods(all_cmd,(&emulator::INR_C));

    umpk_cmd_list.add("14");
    add_cmd_methods(all_cmd,(&emulator::INR_D));

    umpk_cmd_list.add("1C");
    add_cmd_methods(all_cmd,(&emulator::INR_E));

    umpk_cmd_list.add("24");
    add_cmd_methods(all_cmd,(&emulator::INR_H));

    umpk_cmd_list.add("2C");
    add_cmd_methods(all_cmd,(&emulator::INR_L));

    umpk_cmd_list.add("34");
    add_cmd_methods(all_cmd,(&emulator::INR_M));//DCR m


    //INX R
    umpk_cmd_list.add("03");
    add_cmd_methods(all_cmd,(&emulator::INX_B));

    umpk_cmd_list.add("13");
    add_cmd_methods(all_cmd,(&emulator::INX_D));

    umpk_cmd_list.add("23");
    add_cmd_methods(all_cmd,(&emulator::INX_H));

    //INX SP



    //lda
    umpk_cmd_list.add("3A");
    add_cmd_methods(all_cmd,(&emulator::LDA));

    //sta
    umpk_cmd_list.add("32");
    add_cmd_methods(all_cmd,(&emulator::STA));

   //lxi
    umpk_cmd_list.add("01");
    add_cmd_methods(all_cmd,(&emulator::LXI_B));

    umpk_cmd_list.add("11");
    add_cmd_methods(all_cmd,(&emulator::LXI_D));

    umpk_cmd_list.add("21");
    add_cmd_methods(all_cmd,(&emulator::LXI_H));
    //lxi sp

    //ldax

    umpk_cmd_list.add("0A");
    add_cmd_methods(all_cmd,(&emulator::LDAX_B));

    umpk_cmd_list.add("1A");
    add_cmd_methods(all_cmd,(&emulator::LDAX_D));

    //stax

    umpk_cmd_list.add("02");
    add_cmd_methods(all_cmd,(&emulator::STAX_B));

    umpk_cmd_list.add("12");
    add_cmd_methods(all_cmd,(&emulator::STAX_D));


    //jz

    umpk_cmd_list.add("CA");
    add_cmd_methods(all_cmd,(&emulator::JZ));

    //jnz
    umpk_cmd_list.add("C2");
    add_cmd_methods(all_cmd,(&emulator::JNZ));

    //jc
    umpk_cmd_list.add("DA");
    add_cmd_methods(all_cmd,(&emulator::JC));

    //jnc
    umpk_cmd_list.add("D2");
    add_cmd_methods(all_cmd,(&emulator::JNC));

    //jmp
    umpk_cmd_list.add("C3");
    add_cmd_methods(all_cmd,(&emulator::JMP));

    //RST1
    umpk_cmd_list.add("CF");
    add_cmd_methods(all_cmd,(&emulator::RST1));

 //   std::cout << all_cmd << std::endl;


    //ANA
    umpk_cmd_list.add("A7");
    add_cmd_methods(all_cmd,(&emulator::ANA_A));

    umpk_cmd_list.add("A0");
    add_cmd_methods(all_cmd,(&emulator::ANA_B));

    umpk_cmd_list.add("A1");
    add_cmd_methods(all_cmd,(&emulator::ANA_C));

    umpk_cmd_list.add("A2");
    add_cmd_methods(all_cmd,(&emulator::ANA_D));

    umpk_cmd_list.add("A3");
    add_cmd_methods(all_cmd,(&emulator::ANA_E));

    umpk_cmd_list.add("A4");
    add_cmd_methods(all_cmd,(&emulator::ANA_H));

    umpk_cmd_list.add("A5");
    add_cmd_methods(all_cmd,(&emulator::ANA_L));

    umpk_cmd_list.add("A6");
    add_cmd_methods(all_cmd,(&emulator::ANA_M));

    umpk_cmd_list.add("00");
    add_cmd_methods(all_cmd,(&emulator::null_cmd));


}

void emulator::iteration()
{
     for(int i =0; i<all_cmd; i++)//проходим по всем командам
    {

        if(list[point] == umpk_cmd_list[i])//
        {
          //  std::cout << std::endl <<  "point " << point << std::endl;

            (this->*cmd_methods[i])();

            //if(A==0) Z=1;
            //else Z=0;

            return;
        }
    }
    msg_error *not_right_command = new msg_error("Не найдена комманда",point);
    throw not_right_command;
}

void emulator::start()
{
    int i=0;
    try
    {

    for(i=0; i<1000 && !stop_flag;i++)
    {


        iteration();
    }
    }
    catch(msg_address_error *error)
    {
        error->print();
        delete error;
    }
    catch(msg_error *error)
    {
        error->print();
        delete  error;
    }
    std::cout << std::endl <<  "count iteration " << i << std::endl;
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
   if(A < R)
       Cy=1;
   if(A == R)
       Z=1;

    A = (A-R);


    point++;
}

void emulator::SUI(){
    point++;
    SUB(list[point]);
    point++;
}

void emulator::INR(hexes& R){
    if(R == 255)
     {
        Cy = 1;
    }
    R = (R + 1);

    if(R == 0)
     {
        Z=1;
     }

        point++;
}
void emulator::DCR(hexes& R){
    if(R == 0)
     {
        Cy = 1;
     }
     R = (R - 1);

     if(R == 0)
      {
         Z=1;
      }

    point++;
}
void emulator::LDA()
{
    hexes *t_R1 = new hexes;
    hexes *t_R2 = new hexes;
    point++;
    *t_R2 = list[point];
    point++;
    *t_R1 = list[point];
    point++;
    A = get_cell(*t_R1, *t_R2);

    delete t_R1; delete t_R2;
        point++;
}

void emulator::STA()
{
    hexes *t_R1 = new hexes;
    hexes *t_R2 = new hexes;
    point++;
    *t_R2 = list[point];
    point++;
    *t_R1 = list[point];
    point++;
    get_cell(*t_R1, *t_R2) = A;

    delete t_R1; delete t_R2;
        point++;
}
 

void emulator::LXI(hexes &R1, hexes &R2)
{
    point++;
    R2 = list[point];
    point++;
    R1 = list[point];
    point++;
}


void emulator::LDAX(hexes &R1, hexes &R2)
{
        A = get_cell(R1,R2);
            point++;
}

void emulator::STAX(hexes &R1, hexes &R2)
{
        get_cell(R1,R2) = A;
            point++;
}

void emulator::JMP()
{
    hexes *t_R1 = new hexes;
    hexes *t_R2 = new hexes;
    point++;
    *t_R2 = list[point];
    point++;
    *t_R1 = list[point];
    point++;

    point = hex_couple_to_int(*t_R1,*t_R2);

    delete t_R1; delete t_R2;

}

void emulator::JMP(const bool &flag)
{
    if(flag)
    {
    hexes *t_R1 = new hexes;
    hexes *t_R2 = new hexes;
    point++;
    *t_R2 = list[point];
    point++;
    *t_R1 = list[point];
    point++;

    point = hex_couple_to_int(*t_R1,*t_R2);

    delete t_R1; delete t_R2;
    }
    else point+=3;
}


void emulator::RST1()
{
    point = 0;
    stop_flag = 1;
}

 void emulator::ANA(hexes &R)
 {
        A&=R;

        if(A == 0)
            Z=0;

         point++;
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
        msg_address_error *new_error = new msg_address_error("Неправильный адресс епта",A1,A2,point);
        std::cout << "adress not exist" << std::endl;
        throw new_error;
        //return -1;
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

    if(*temp == 0)
    {
        Cy = 1;
        *temp = 0;
    }
    else
    *temp = temp->to_ulong() - 1;


    if(*temp == 0)
    {
        Z = 1;
    }

    for(unsigned long i=0;i<8;i++)
        A2.b[i] = temp->operator[](i);

    for(unsigned long i=8;i<16;i++)
        A1.b[i-8] = temp->operator[](i);

    delete temp;
}

void emulator::inr_hex_couple(hexes &A1, hexes &A2)
{
    std::bitset<16> *temp = new std::bitset<16>;

    for(unsigned long i=0;i<8;i++)
        temp->operator[](i) = A2.b[i];

    for(unsigned long i=8;i<16;i++)
        temp->operator[](i) = A1.b[i-8];

    if(*temp == 255)
    {
        Cy = 1;
        *temp = 0;
    }
    else
    *temp = temp->to_ulong() + 1;

    if(*temp == 0)
    {
      Z=1;
    }

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
    {
        msg_address_error *new_error = new msg_address_error("Неправильный адресс епта",A1,A2,point);
        std::cout << "adress not exist" << std::endl;
        throw new_error;
    }
    else
        list[new_point] = value;
}

hexes &emulator::get_cell(hexes &A1, hexes &A2)
{
    int new_point = hex_couple_to_int(A1,A2);
    if(new_point < 0)
    {
        msg_address_error *new_error = new msg_address_error("Неправильный адресс епта",A1,A2,point);
        std::cout << "adress not exist" << std::endl;
        throw new_error;
    }
    else
    return list[new_point];
}

