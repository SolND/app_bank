#include "bank_tree.hpp"
#include "hash_table.hpp"

Bank_tree::Bank_tree(){ }

Bank_tree::~Bank_tree(){ }

void Bank_tree::set_hash_table(Hash_table hash)
{
	this->h = hash;
}

void Bank_tree::set_root(Bank_node* root)
{
	this->root = root;
}

Bank_node* Bank_tree::get_root()
{
	return this->root;
}

Hash_table Bank_tree::get_hash_table()
{
	return this->h;
}

Bank_node* Bank_tree::search(Bank_node* root, int accountno)
{
	if (root == nullptr)
		return (nullptr);
	else if (accountno < root->get_account_number())
		return (search(root->get_left(), accountno));
	else if (accountno > root->get_account_number())
		return (search(root->get_right(), accountno));
	return (root);

}


void Bank_tree::load_server()
{
	std::ifstream read;
	read.open("server.txt", std::ios::app);

	std::string name = "";
	std::string adress = "";
	int accountno = 0;
	std::string password = "";
	int balance = 0;
	//cin.ignore();
	while (!read.eof())
	{	
		std::getline(read, name);
		std::getline(read, adress);
		read >> accountno;
		std::getline(read, password);
		read >> balance;
		read.ignore();

		if (name!="" && adress != "" && accountno != 0 && password != "" )
		{
			//cout << "enter hua" << endl;
			Bank_node * temp = new Bank_node(name, adress, accountno, password, balance);
			Bank_node * current = get_root();
			if (get_root() == nullptr)
			{

				set_root(temp);
			}
			else
			{
				while (true)
				{

					if (accountno < current->get_account_number())
					{
						if (current->get_left() == nullptr)
						{
							current->set_left(temp);
							break;
						}
						current = current->get_left();
					}

                    if(accountno < current->get_account_number())
                    {
                        if(current->get_right() == nullptr)
                        {
                            current->set_right(temp);
                            break;
                        }
                        current = current->get_right();
                    }
					if (accountno == current->get_account_number())
					{
						break;
					}
				}
			}
		}
	}
	read.close();
}

bool file_data(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        return false; // Tệp không tồn tại hoặc không thể mở
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            file.close();
            return true; // Tệp tồn tại và có dữ liệu bên trong
        }
    }

    file.close();
    return false; // Tệp tồn tại nhưng không có dữ liệu bên trong
}

void Bank_tree:: update_server(Bank_node *root)
{
	static int i = 0;
	if (i == 0)
	{
		i++;
		// remove("server.txt");
	}

	std::ofstream write;
	write.open("server.txt");
	if(file_data("server.txt") == true)
	{
		if (root)
		{
			update_server(root->get_left());
			write << root->get_name()<<"\n";
			write << root->get_address()<<"\n";
			write << root->get_account_number()<<"\n";
			write << root->get_password()<<"\n";
			write << root->get_balance()<<"\n";
			update_server(root->get_right());
		}
	}

	write.close();
}

void Bank_tree:: printoinfo(Bank_node* root)
{
	if (root)
	{
		printoinfo(root->get_left());
		std::cout << root->get_name()<<"\n";
		std::cout << root->get_address()<<"\n";
		std::cout << root->get_account_number()<<"\n";
		std::cout << root->get_password()<<"\n";
		std::cout << root->get_balance()<<"\n";
		printoinfo(root->get_right());
	}
	std::cout << "Danh sách tài khoản trống\n";
}

void Bank_tree::add_account(std::string name, std::string addr, int number, std::string pass, int balance)
{
    get_hash_table().add(number, pass);
    std::ofstream write;
    write.open("server.txt", std::ios::app);
    write << name << "\n" << addr << "\n" << number << "\n" << pass << "\n" << balance << "\n";
    write.close();

    Bank_node *temp = new Bank_node(name, addr, number, pass, balance);
    
    Bank_node *current = get_root();
    if(get_root() == nullptr)
    {
        set_root(temp);
    }
    else
    {
        while(true)
        {
            if(number < current->get_account_number())
            {
                if(current->get_left() == nullptr)
                {
                    current->set_left(temp);
                    break;
                }
                current = current->get_left();
            }

            if(number < current->get_account_number())
            {
                if(current->get_right() == nullptr)
                {
                    current->set_right(temp);
                    break;
                }
                current = current->get_right();
            }
        }
    }
}

Bank_node* Bank_tree::delete_account(Bank_node *root, int account)
{
    if(root == nullptr)
	{
        std::cout << "Bạn đã nhập sai dữ liệu\n";
	}
    else if(account < root->get_account_number())
	{
        root->set_left(delete_account(root->get_left(), account));
	}
    else if(account > get_root()->get_account_number())
	{
        root->set_right(delete_account(root->get_right(), account));
	}
    else
    {
        if(root->get_left() && root->get_right())
        {
            find_max(root->get_left());
            root->set_account_number(v.back());
			root->set_left(delete_account(root->get_left(), root->get_account_number()));
        }
        else
		{
			std::cout << "aya\n";
			Bank_node* temp = root;
			if (root->get_left() == nullptr)
				root = root->get_right();
			else if (root->get_right() == nullptr)
				root = root->get_left();
			delete temp;
		}
    }
}

void Bank_tree::with_draw(int accountno,int amount)
{
	load_server();
	Bank_node *temp = search(get_root(), accountno);
	temp->set_balance(temp->get_balance() - amount);
	std::vector <int> data;
	std::ifstream read;
	read.open("transaction.txt", std::ios::app);
	int line = 0;
	while (!read.eof())
	{
		read >> line;
		if (line == accountno)
		{
			data.push_back(line);
			line = (amount*-1);
			data.push_back(line);
			continue;
		}
		data.push_back(line);
	}
	read.close();

	std::ofstream write;
	write.open("temp.txt", std::ios::app);
	for (int i = 0; i < data.size(); i++)
	{
		write << data[i]<< "\n";
	}
	write.close();
	// remove("transaction.txt");
	// rename("temp.txt", "transaction.txt");
	
	update_server(get_root());
}

void Bank_tree::deposit(int accountno,int amount)
{
	load_server();
	Bank_node *temp = search(get_root(), accountno);
	temp->set_balance(temp->get_balance() + amount);

	std::vector <int> data;
	std::ifstream read;
	read.open("transaction.txt", std::ios::app);
	int line = 0;
	while (!read.eof())
	{
		read >> line;
		if (line == accountno)
		{
			data.push_back(line);
			line = amount;
			data.push_back(line);
			continue;
		}
		data.push_back(line);
	}
	read.close();

	std::ofstream write;
	write.open("temp.txt", std::ios::app);
	for (int i = 0; i < data.size(); i++)
	{
		write << data[i] << "\n";
	}
	write.close();
	// remove("transaction.txt");
	// rename("temp.txt", "transaction.txt");


	update_server(get_root());
}
void Bank_tree::edit_account_byadmin()
{

}

void Bank_tree::transfer(int sender_accountno,int reciever_accountno,int sender_amount)
{
	// happening in tree
	Bank_node *sender = search(get_root(), sender_accountno);
	sender->set_balance(sender->get_balance() -sender_amount);
	Bank_node *reciever = search(get_root(), reciever_accountno);
	reciever->set_balance(reciever->get_balance() + sender_amount);
	update_server(get_root());

	// Now happening in the transacton file

	//  for sender
	std::vector<int> data;
	std::ifstream read;
	read.open("transaction.txt", std::ios::app);
	int line = 0;
	while (!read.eof())
	{
		read >> line;
		if (line == sender_accountno)
		{
			data.push_back(line);
			line = (sender_amount*-1);
			data.push_back(line);
			continue;
		}
		data.push_back(line);
	}
	read.close();

	std::ofstream write;
	write.open("temp.txt", std::ios::app);
	for (int i = 0; i < data.size(); i++)
	{
		write << data[i] << "\n";
	}
	write.close();
	// remove("transaction.txt");
	// rename("temp.txt", "transaction.txt");


	//  for reciever 


	std::vector<int> data1;
	std::ifstream read1;
	read1.open("transaction.txt", std::ios::app);
	int line1 = 0;
	while (!read.eof())
	{
		read1 >> line1;
		if (line == reciever_accountno)
		{
			data1.push_back(line1);
			line1 = sender_amount;
			data1.push_back(line1);
			continue;
		}
		data1.push_back(line1);
	}
	read1.close();

	std::ofstream write1;
	write1.open("temp.txt", std::ios::app);
	for (int i = 0; i < data1.size(); i++)
	{
		write1 << data1[i] << "\n";
	}
	write1.close();
	// remove("transaction.txt");
	// rename("temp.txt", "transaction.txt");

}
void Bank_tree::transaction_history()
{
    std::ifstream read;
    read.open("transaction.txt");

    if (!read.is_open()) {
        std::cout << "Không thể mở tệp lịch sử giao dịch.\n";
        return;
    }

    std::cout << "Lịch sử giao dịch:\n";
    
    int account_number, amount;
    
    while (read >> account_number >> amount) {
        std::cout << "Tài khoản " << account_number << ": " << amount << " VNĐ\n";
    }

    read.close();
}
void Bank_tree:: find_max(Bank_node* root)
{
	if (root)
	{
		find_max(root->get_left());
		v.push_back(root->get_account_number());
		find_max(root->get_right());
	}
}