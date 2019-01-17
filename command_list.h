#ifndef COMMAND_LIST_H
#define COMMAND_LIST_H
#include "hex.h"

//class comand_list;

class cmd{
private:
    cmd *next;
    cmd *back;
public:
    cmd()
    {
        next = nullptr;
        back = nullptr;
    }
    hexes value_cmd;

friend class command_list;
};

class command_list
{
private:
    cmd *begin;
    cmd *end;
public:
    command_list();
    command_list(const char *path);

    //const unsigned long&
    void add(int);
    void add(hexes);
    void add(char[2]);
    void add(std::string);

    void print();
    void remove(int);

    void read_from_file(char*);
    void read_from_file(std::string);

    void debag_print(); //delete

    hexes& operator [] (int n);//нам все равно нужен будет только hexes, нахер нам выдавать класс в котором приватные поля все равно закрыты
};

#endif // COMMAND_LIST_H
