#ifndef _BANK_TREE_HPP
#define _BANK_TREE_HPP

#include "bank_node.hpp"
#include "hash_table.hpp"
#include <vector>
#include <fstream>
class Bank_tree
{
public:
    Bank_tree();
    ~Bank_tree();
	void add_account(std::string, std::string, int, std::string, int);
	Bank_node* delete_account(Bank_node *, int);
	void with_draw(int,int);
	void deposit(int,int);
	void edit_account_byadmin();
	void transfer(int,int,int);
	void transaction_history();
	void find_max(Bank_node *);
	void load_server();
	void update_server(Bank_node *);
	Bank_node* search(Bank_node *,int);
	void printoinfo(Bank_node *);
    void set_hash_table(Hash_table);
    void set_root(Bank_node*);
    Hash_table get_hash_table();
    Bank_node* get_root();
    std::vector<int> v;
private:
    // std::vector<int> v;
    Hash_table h;
    Bank_node *root;
};

#endif