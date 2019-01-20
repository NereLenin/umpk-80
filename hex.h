#ifndef HEX_H
#define HEX_H
#include <iostream>
#include <bitset>


//убрать to int описать правила преобразования


class hexes
{
private:
public:

    std::bitset<8> b; // 9 бит для флагов?

    hexes();
    hexes(const unsigned long&);
    hexes(const char*);

    void print_bin();
    void print_hex();
    void print_int();

    int to_int();
    char* to_char();

    void operator = (const hexes&);
    void operator = (const unsigned long&);

    hexes operator + (const hexes &);
    hexes operator - (const hexes &);
    hexes operator * (const hexes &);
    hexes operator / (const hexes &);

    void operator << (const unsigned long&);
    void operator >> (const unsigned long&);

    void c_shift_left ();//one shift
    void c_shift_right ();

    void c_shift_left (const unsigned long&);//many shift
    void c_shift_right (const unsigned long&);

    bool operator == (const char*);//Выпилить?
    bool operator == (int);//выпилить?

    bool operator == (const hexes&);//выпилить?



};
#endif // HEX_H
