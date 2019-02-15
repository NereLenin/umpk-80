#include "command_list.h"

command_list::command_list()
{
    begin = nullptr;
    end = nullptr;
}


//проверить этот и следующий метод на излишнее копирование при передаче

void command_list::add(const hexes &value){
    cmd *new_cmd = new cmd;

    new_cmd->value_cmd = value;


    new_cmd->back = nullptr;

    if(begin==nullptr)
    {
        begin = new_cmd;
        end = new_cmd;
        return;
    }

    if(begin->next == nullptr)
    {
        begin->next = new_cmd;
        new_cmd->back = begin;

        end = new_cmd;

        return;
    }

    end->next = new_cmd;
    new_cmd->back = end;

    end = new_cmd;
}

//const unsigned long&
void command_list::add(int value){
    hexes *new_cmd = new hexes;

    *new_cmd = value;//?

    add(*new_cmd);

    //? не удаляем
}
void command_list::add(const char* value){
    hexes *new_cmd = new hexes(value);

    add(*new_cmd);
}

void command_list::remove(int index)
{
   cmd *temp = begin;

    for(int i = 0; temp!=nullptr&&i!=index; temp = temp->next,i++);

    if(temp == nullptr){ std::cout << "not_exist" << std::endl;return;}

    if(temp == end)
    {
        (temp->back)->next = nullptr;
        end = (temp->back);
        return;
    }
    if(temp == begin)
    {
        (temp->next)->back = nullptr;
        begin = (temp->next);
        return;
    }

    (temp->next)->back = temp->back;
    (temp->back)->next = temp->next;

    delete temp;
}


hexes& command_list::operator [] (int index){
    if(index < 0)
    {
        std::cout << "not_exist, you will give first element " << std::endl;return begin->value_cmd;
    }
    hexes null_value;

    cmd *temp = begin;

    for(int i = 0; temp!=nullptr&&i!=index; temp = temp->next,i++);

    if(temp == nullptr){ std::cout << "not_exist, you will give last element " << std::endl;return end->value_cmd;}

    return (temp->value_cmd);
}

void command_list::print()
{
    if(begin==nullptr){ std::cout << "empty list" << std::endl;}
    for(cmd *i = begin; i!=nullptr; i = i->next)
        i->value_cmd.print_hex();

}


 void command_list::debag_print()
 {
     int n=0;

     std::cout << "i"<< std::endl;


     for(cmd *i = begin; i!=nullptr; i = i->next)
     {
         std::cout << n  << "     " << " n " << i->next << " back " << i->back  << " b " << begin << " e " <<  end << std::endl;
         n++;
     }

 }
