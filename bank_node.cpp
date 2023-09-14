#include "bank_node.hpp"

Bank_node::Bank_node()
{
    this->name = "";
    this->address = "";
    this->password = "";
    this->left = nullptr;
    this->right = nullptr;
    this->account_number = 0;
    this->balance = 0;
}

Bank_node::~Bank_node()
{

}

Bank_node::Bank_node(std::string name, std::string addr, int number, std::string pass, int balance)
{
    this->name = name;
    this->address = addr;
    this->password = pass;
    this->left = nullptr;
    this->right = nullptr;
    this->account_number = number;
    this->balance = balance;
}

void Bank_node::set_name(std::string name)
{
    this->name = name;
}

void Bank_node::set_address(std::string addr)
{
    this->address = addr;
}

void Bank_node::set_password(std::string pass)
{
    this->password = pass;
}

void Bank_node::set_account_number(int number)
{
    this->account_number = number;
}

void Bank_node::set_balance(int balance)
{
    this->balance = balance;
}

void Bank_node::set_left(Bank_node* left)
{
    this->left = left;
}

void Bank_node::set_right(Bank_node* right)
{
    this->right = right;
}

std::string Bank_node::get_name()
{
    return this->name;
}

std::string Bank_node::get_address()
{
    return this->address;
}

std::string Bank_node::get_password()
{
    return this->password;
}

int Bank_node::get_account_number()
{
    return this->account_number;
}

int Bank_node::get_balance()
{
    return this->balance; // account balance
}

Bank_node* Bank_node::get_left()
{
    return this->left;
}
Bank_node* Bank_node::get_right()
{
    return this->right;
}