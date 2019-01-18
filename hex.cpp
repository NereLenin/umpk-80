#include "hex.h"


//std выпилить потом
//заккоментить че делали
using namespace std;



hexes::hexes()
{
    b = 0;
}

hexes::hexes(const unsigned long& value)
{
    if(value>255) cout << "not more than 255 plz" << endl;
    b = value;
}


void hexes::print_bin()
{
    cout << b << endl;
}

void hexes::print_int()
{
    cout << b.to_ulong() << endl;
}


void hexes::print_hex()
{
    cout << hex << b.to_ulong() << endl;
}




void hexes::operator = (const hexes& two)
{
    b = two.b;
}


void hexes::operator = (const unsigned long& value)
{
   b = value;
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




void hexes::operator << (const unsigned long& n)
{
    b<<=(n);
}

void hexes::operator >> (const unsigned long& n)
{
    b>>=(n);
}

void hexes::c_shift_left (const unsigned long& n)
{

    //првоерить дописать если количество сдвигов больше разряда или запретить или поделить на количество разрядов а потом сдвигать
     int tn = static_cast<int>(n);
      int *temp = new int[n];

      for(int i=0; i < tn; i++)
            temp[i] = static_cast<int>(b[7-i]);

      b<<=n;

      for(int i=0; i < tn; i++)
            b[i] = temp[(tn-1)-i];

      delete[] temp;
}

void hexes::c_shift_right (const unsigned long& n)
{

    //првоерить дописать если количество сдвигов больше разряда или запретить или поделить на количество разрядов а потом сдвигать
     int tn = static_cast<int>(n);
      int *temp = new int[n];

      for(int i=0; i < tn; i++)
            temp[i] = static_cast<int>(b[i]);

      b>>=n;

      for(int i=0; i < tn; i++)
            b[(7 - (tn-1)) + i] = temp[i];

      delete[] temp;
}

int hexes::to_int()
{
    return static_cast<int>(b.to_ulong());
}

bool hexes::operator == (const char* value)
{
    //проверка входных параметров, действительно ли от 1 до F,
    //вхождение F -f

    int one=static_cast<int>(value[0]);

    if(one<=102&&value[0]>=97)
         one = one -87;

    else
        one = one-48;

    int two=static_cast<int>(value[1]);

    if(two<=102&&two>=97)
         two = two-87;
    else
        two = two-48;

    int res = one * 16 + two;

    return to_int() == res;
}

hexes::hexes(char value[2])
{
    //проверка на соответсвие char формату

    unsigned long value_i =0;



}

char* hexes::to_char()
{
    char *new_char = new char[2];

    int value = to_int();



}
