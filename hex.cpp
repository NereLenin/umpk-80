#include "hex.h"


void hexes::print_hex(){
    uint8_t t=value;
    for(int i=0;i<8;i++)
    {
        std::cout << ((t%=2)==1);
    }
}
