#ifndef HEX_H
#define HEX_H
#include <iostream>
#include <bitset>


//убрать to int описать правила преобразования


class hexes
{
private:
    bool right_hex_alphabet(const char* value); //p
    std::bitset<8> b; // p
public:
    hexes();
    hexes(const unsigned long&);
    hexes(const char*);

    void print_bin();
    void print_hex();
    void print_int();

    int to_int();//выпилить?
    char* to_char();//выпилить?

    void operator = (const hexes&);
    void operator = (int value);
    void operator = (const char*);


    hexes operator + (const hexes &);
    hexes operator - (const hexes &);
    hexes operator * (const hexes &);
    hexes operator / (const hexes &);

    void operator << (const unsigned long&);
    void operator >> (const unsigned long&);

    void c_shift_left ();//one shift
    void c_shift_right ();


    void c_shift_left (int n);//many shift
    void c_shift_right (int n);



    bool operator == (const char*);//Выпилить?
    bool operator == (int);//выпилить?

    bool operator == (const hexes&);//выпилить?

    bool operator < (const hexes&);

    bool operator > (const unsigned long);

    void operator&=( const hexes& );

    void operator|=(  const hexes& );

    void operator^=(  const hexes&  );

    void operator~();

    friend class emulator;
    //<<

};

class hex_couple
{
    hexes first_addr;
    hexes second_addr;

public:
    const hexes& get_first();
    const hexes& get_second();

    void set_first(const hexes&);
    void set_second(const hexes&);

    void print()//выпилить
    {
        std::cout << first_addr.to_int() << " " << second_addr.to_int()  << std::endl;
    }

};

#endif // HEX_H
