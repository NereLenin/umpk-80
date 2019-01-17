#ifndef HEX_H
#define HEX_H
#include <iostream>
#include <bitset>



class hexes
{
private:
public:

    std::bitset<8> b; // 9 бит для флагов?

    hexes();
    hexes(const unsigned long&);
    hexes(const std::string&);
    hexes(const std::bitset<8>&);
    hexes(char[2]);

    void print_bin();
    void print_hex();
    void print_int();

    void operator = (const hexes&);
    void operator = (const unsigned long&);

    hexes operator + (const hexes &);
    hexes operator - (const hexes &);
    hexes operator * (const hexes &);
    hexes operator / (const hexes &);

    void operator << (const unsigned long&);
    void operator >> (const unsigned long&);

    void c_shift_left (const unsigned long&);
    void c_shift_right (const unsigned long&);


};
#endif // HEX_H
