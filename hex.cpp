#include "hex.h"


//std выпилить потом
//заккоментить че делали
using namespace std;


// constructors

hexes::hexes()
{
    b = 0;
}


hexes::hexes(const unsigned long& value)
{
    if(value>255) cout << "no more than 255 plz" << endl;
    b = value;
}


hexes::hexes(const char* value)
{
    operator=(value);
}


// print format
void hexes::print_bin()
{
    cout << b;
}

void hexes::print_int()
{
    cout << b.to_ulong();
}


void hexes::print_hex()
{
    cout << hex << b.to_ulong();
}


// to_format

int hexes::to_int()
{
    return static_cast<int>(b.to_ulong());

}

//выпилить
char* hexes::to_char()
{
    char *str = new char[2];
    int value = to_int();

    int tvalue = value;

    for(int i=0;i<2 && tvalue>=1 && value>=1;i++)
    {
        tvalue%=16; value/=16;
        if(tvalue>9) str[1-i] = static_cast<char>(tvalue + 87);
        else str[1-i] = static_cast<char>(tvalue + 48);
        tvalue = value;
    }

    return str;
}



void hexes::operator = (const hexes& two)
{
    b = two.b;
}

void hexes::operator = (int value)
{

   b = static_cast<std::size_t>(value);
}

void hexes::operator = (const char* value)
{
    if(!right_hex_alphabet(value))
    {
        std::cout << "not rigt hex alphabet" << std::endl;
        return;
    }

    int one=static_cast<int>(value[0]);

    if(one<=70 && one>=65)
         one = one -55;
    else if(one<=102 && one>=97)
         one = one -87;
    else
        one = one-48;


    int two=static_cast<int>(value[1]);
    if(two<=70 && two>=65)
         two = two -55;
    else if(two<=102 && two>=97)
         two = two-87;
    else
        two = two-48;

    int res = one * 16 + two;

    operator=(res);

}

hexes hexes::operator + (const hexes& two)
{
   return (b.to_ulong() + two.b.to_ulong());
}

hexes hexes::operator - (const hexes& two)
{
   return (b.to_ulong() - two.b.to_ulong());
}

hexes hexes::operator * (const hexes& two)
{
   return (b.to_ulong() * two.b.to_ulong());
}

hexes hexes::operator / (const hexes& two)
{
   return (b.to_ulong() / two.b.to_ulong());
}


// shifts

void hexes::operator << (const unsigned long& n)
{
    b<<=(n);
}

void hexes::operator >> (const unsigned long& n)
{
    b>>=(n);
}


void hexes::c_shift_left()
{
      std::size_t temp= b[7];

      b<<=1;

       b[0] = temp;

}

void hexes::c_shift_right()
{

    std::size_t temp= b[0];

    b>>=1;

    b[7] = temp;
}

void hexes::c_shift_left(int n)
{
     for(int i=0; i<n;i++)
         c_shift_left();
}

void hexes::c_shift_right(int n)
{

     for(int i=0; i<n;i++)
         c_shift_right();
}


bool hexes::operator==(const hexes &two)
{
    return b == two.b;
}

bool hexes::operator == (int value)
{
    unsigned long one=static_cast<unsigned long>(value);

    return b.to_ulong() == one;
}

bool hexes::operator == (const char* value)
{
    //проверка входных параметров, действительно ли от 1 до F,

    int one=static_cast<int>(value[0]);

    if(one<=70 && one>=65)
         one = one -55;
    else if(one<=102 && one>=97)
         one = one -87;
    else
        one = one-48;


    int two=static_cast<int>(value[1]);
    if(two<=70 && two>=65)
         two = two -55;
    else if(two<=102 && two>=97)
         two = two-87;
    else
        two = two-48;

    int res = one * 16 + two;

    return to_int() == res;
}


bool hexes::right_hex_alphabet(const char *value)
{
    bool res_one,res_two;
    res_one = res_two = 0;

    int one = static_cast<int>(value[0]);
    for(int i = 48; i<=57;i++)
            if(i==one) res_one = true;

    if(!res_one)
    {
    for(int i = 65; i<=70;i++)
            if(i==one) res_one = true;
    }

    if(!res_one)
    {
    for(int i = 97; i<=102;i++)
            if(i==one) res_one = true;
    }


    int two = static_cast<int>(value[1]);

    if(!res_two)
    {
    for(int i = 48; i<=57;i++)
            if(i==two) res_two = true;
    }

    if(!res_two)
    {
    for(int i = 65; i<=70;i++)
            if(i==two) res_two = true;
    }
    if(!res_two)
    {
    for(int i = 97; i<=102;i++)
            if(i==two) res_two = true;
    }

    return res_one&&res_two;
}
