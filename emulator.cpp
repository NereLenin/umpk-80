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
}

void emulator::print_list()
{
    list.print();
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


//-----------------------------------//

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
    A = (A+R);
    if(A.to_int() + R.to_int()>255)
        C=1;
    point++;
}
void emulator::iteration()
{

    if(list[point] == "78") MOV(A,B);


}
