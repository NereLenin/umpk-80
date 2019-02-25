#ifndef MSG_ERROR_H
#define MSG_ERROR_H

#include "hex.h"

/* возможно поля текста нам нахуй не нужны, тк мы знаем какой тип ошибки еще на этапе создания тип
 * или просто косячная операция, или ошибка адрессации, а шо может быть кроме ошибки аддресации?
 */
class msg_error
{

protected:
    std::string text;
    int point;

public:
    msg_error();
    msg_error(const std::string& error_text, int current_point);
    virtual ~msg_error();
    void print();

};


class msg_address_error : public msg_error
{
private:
    hexes first_reg;
    hexes second_reg;
public:
    msg_address_error();
    msg_address_error(const std::string& error_text,hexes &first_error_reg,hexes &second_error_reg,int current_point);
    void print();

};

#endif // MSG_ERROR_H
