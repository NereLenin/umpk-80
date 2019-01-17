#include "command_list.h"

command_list::command_list()
{
    begin = nullptr;
    end = nullptr;
}

//const unsigned long&
void command_list::add(int value){
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


 void command_list::debag_print()
 {
     int n=0;

     std::cout << "i"<< std::endl;

     for(cmd *i = begin; i!=nullptr; i = i->next)
     {
         std::cout << n  << "     " << " n " << i->next << " back " << i->back  << " b " << begin << " e " <<  end << std::endl;
         n++;
     }

     for(cmd *i = begin; i!=nullptr; i = i->next)
     {
         std::cout << n  << "     " << " n " << i->next << " back " << i->back  << " b " << begin << " e " <<  end << std::endl;
         n++;
     }

 }
