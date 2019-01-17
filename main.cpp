#include <iostream>
#include <bitset>
#include <hex.h>

using namespace std;




template <class type_two>
class one{
private:
    type_two* used;

public:

    void init(type_two *current_use){
        used = current_use;
    }

    one();
    void test()
    {
        used->value = 3;
    }

};

class two
{
private:
    int value;
public:
    two(){
        value =0;

    }
    one<two> *test;

    friend class one<two>;
};



int main()
{
    hexes one(200);
    hexes two(3);

    one.print_bin();

    return 0;
}
