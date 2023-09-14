#ifndef _HASH_TABLE_HPP
#define _HASH_TABLE_HPP

#include "node.hpp"
#include <map>
#
class Hash_table
{
public:
    Hash_table();
    ~Hash_table();
	void start_hash();
	void load_hash_table();
	void add(int,std::string);
	bool match(int,std::string);
	void display();
	void display_password();
	void delete_password(int);
    void set_start(Node*);
    Node* get_start();
private:
    Node *start;
};
#endif