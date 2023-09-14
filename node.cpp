#include "node.hpp"


Node::Node()
{
	//This is a bidirectional node which requires a pointer to both the next and previous node.
	next = nullptr;
	pre = nullptr;
	data = 0;
}
Node::Node(int d)//Parameterized Constructor
{
	next = nullptr;
	pre = nullptr;
	data = d;
}
Node::~Node(){}

void Node::set_next(Node* next)
{
    this->next = next;
}

void Node::set_data(int data)
{
    this->data = data;
}

void Node::set_per(Node_1* pre)
{
    this->pre = pre;
}

Node* Node::get_next()
{
    return this->next;
}
Node_1* Node::get_pre()
{
    return this->pre;
}

int Node::get_data()
{
    return this->data;
}

Node_1::Node_1()
{
    this->next = nullptr;
    this->acc_number = 0;
    this->password = "";
}
Node_1::~Node_1(){}
Node_1::Node_1(int a, std::string p)
{
    this->next = nullptr;
    this->acc_number = 0;
    this->password = "";
}

void Node_1::set_account_number(int acc)
{
    this->acc_number = acc;
}

void Node_1::set_password(std::string pass)
{
    this->password = pass;
}

void Node_1::set_next(Node_1 *next)
{
    this->next = next;
}

std::string Node_1::get_password()
{
    return this->password;
}

Node_1* Node_1::get_next()
{
    return this->next;
}
int Node_1::get_account_number()
{
    return this->acc_number;
}