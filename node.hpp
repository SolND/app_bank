#ifndef _NODE_HPP
#define _NODE_HPP

#include <string>
#include <fstream>
#include <iostream>

class Node_1
{
public:
    Node_1();
    ~Node_1();
    Node_1(int, std::string);

    void set_next(Node_1*); 
    void set_password(std::string);
    void set_account_number(int);

    std::string get_password();
    int get_account_number();
    Node_1* get_next();
    
private:
    Node_1 *next;
    int acc_number;
    std::string password;
};

class Node
{
public:
    Node();
    ~Node();
    Node(int);
    
    void set_next(Node*);
    void set_per(Node_1*);
    void set_data(int);

    Node* get_next();
    Node_1* get_pre();
    int get_data();
    
private:
    Node *next;
    Node_1 *pre;
    int data;
};





#endif