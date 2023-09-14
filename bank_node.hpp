#ifndef _BANK_NODE_HPP
#define _BANK_NODE_HPP
#include <iostream>
#include <string>
#include<fstream>
#include <vector>

class Bank_node
{
public:
    Bank_node();
    ~Bank_node();
    Bank_node(std::string, std::string, int, std::string, int);

    void set_name(std::string);
    void set_address(std::string);
    void set_account_number(int);
    void set_password(std::string);
    void set_balance(int);
    void set_left(Bank_node*);
    void set_right(Bank_node*);

    std::string get_name();
    std::string get_address();
    int get_account_number();
    std::string get_password();
    int get_balance();
    Bank_node* get_left();
    Bank_node* get_right();
private:
    std::string name;
    std::string address;
    int account_number;
    std::string password;
    int balance;

    Bank_node* left;
    Bank_node* right;
};
#endif