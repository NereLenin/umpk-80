#ifndef HEX_H
#define HEX_H
#include "stdint.h"
#include <iostream>
class hexes
{
private:
    uint8_t value;
public:
    hexes(){value=0;}
    void print_hex();
    void print_bin();
};

#endif // HEX_H
