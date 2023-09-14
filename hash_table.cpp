#include "hash_table.hpp"
#include <vector>
Hash_table::Hash_table()
{
    this->start = nullptr;
}

Hash_table::~Hash_table()
{
	
}
void Hash_table::set_start(Node* s)
{
    this->start = s;
}
Node* Hash_table::get_start()
{
    return this->start;
}
void Hash_table::start_hash()
{
	for (int i = 0; i < 12; i++)
	{
		Node * temp1 = new Node(i);
		if (get_start() == nullptr)
		{
			set_start(temp1);
		}
		else
		{
			Node * current = start;
			while (current->get_next() != nullptr)
			{
				current = current->get_next();
			}
			current->set_next(temp1);
		}
	}
	load_hash_table();
}
void Hash_table::add(int a, std::string p)
{
	static int i = 0;
	std::ofstream write;
	write.open("hashtable.txt",std::ios::app);
	if (i != 0)
	{
		write << "\n";
		write << a << "\n" << p;
	}
	else
	{
		i++;
		write << a << "\n" << p;
	}
	write.close();

	start_hash();
}
bool Hash_table::match(int a, std::string p)
{
	bool flag = false;
	int r = a % 10;
	Node * c = start;
	while (c->get_data() != r)
	{
		c = c->get_next();
	}
	Node_1 *c1 = c->get_pre();
	while (c1 != nullptr)
	{
		if (c1->get_account_number() == a && c1->get_password() == p)
		{
			flag = true;
			break;
		}
		c1 = c1->get_next();
	}
	return flag;
}
void Hash_table::display()
{
	Node * current = start;
	while (current != nullptr)
	{
		std::cout<<current->get_data()<<"\n";
		current = current->get_next();
	}
}
void  Hash_table::load_hash_table()
{
	int acc = 0, r;
    std::string pass;

	std::ifstream read;
	read.open("hashtable.txt");
	while (!read.eof())
	{

		read >> acc;
		read >> pass;
		if (match(acc, pass))
		{
			continue;
		}
		if (acc!= -858993460 && pass!= "-858993460")
		{
			r = acc % 10;

			Node * c = start;
			while (c->get_data() != r)
			{
				c = c->get_next();
			}
			Node_1 *temp = new Node_1(acc, pass);
			if (c->get_pre() == nullptr)
			{
				c->set_per(temp);
			}
			else
			{
				Node_1 *root;
				root = c->get_pre();
				while (root->get_next() != nullptr)
				{
					root = root->get_next();
				}
				root->set_next(temp);
			}
		}
		else
		{
			std::cout << "NO password present\n";
		}
	}
	read.close();
}
void Hash_table::display_password()
{
	start_hash();
	Node *c = get_start();
	while (c != nullptr)
	{
		Node_1 *c1 = c->get_pre();
		while (c1 != nullptr)
		{
			std::cout<<c1->get_account_number()<<"\n";
			std::cout<<c1->get_password()<<"\n";
			c1 = c1->get_next();
		}
		c = c->get_next();
	}
}
void  Hash_table::delete_password(int accountno)
{
	std::ifstream read;
	read.open("hashtable.txt");
	std::vector<int> vec;
	int acc=0,pass=0;
	int i = 0;
	while (!read.eof())
	{
		i++;
		read >> acc;
		read >> pass;
		if (acc == accountno)
		{	                                           // read both account number and password to skip them
			continue;
		}
		vec.push_back(acc);
		vec.push_back(pass);
	}
	read.close();
	std::ofstream write;
	write.open("temp.txt", std::ios::app);
	
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] != 0)
			{
				write << vec[i] << "\n";
			}
		}
	
	
	write.close();
	remove("hashtable.txt");
	rename("temp.txt", "hashtable.txt");
}