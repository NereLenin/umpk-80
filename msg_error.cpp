#include "msg_error.h"

msg_error::~msg_error(){

}

msg_error::msg_error()
{
    point =0;
}
msg_error::msg_error(const std::string& error_text, int current_point)
{
    point = current_point;
    text = error_text;
}

void msg_error::print()
{
    std::cout << text << " on point " << point << std::endl;
}


msg_address_error::msg_address_error()
{

}

msg_address_error::msg_address_error(const std::string& error_text,hexes &first_error_reg,hexes &second_error_reg,int current_point)
{
    text = error_text;
    first_reg = first_error_reg;
    second_reg = second_error_reg;
    point = current_point;
}

void msg_address_error::print()
{
    std::cout << text << " with ";
    first_reg.print_hex();
    second_reg.print_hex();
    std::cout << " on point" << point << std::endl;
}

