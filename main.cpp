#include "hash_table.hpp"
#include "admin.hpp"
#include "staff.hpp"
#include "bank_node.hpp"
#include "bank_tree.hpp"
#include "customer.hpp"
void boot()
{
	Hash_table H;
	Bank_tree T;
	H.start_hash();
	T.load_server();
}
int main()
{
	void boot();

	int condition=0;
	while (condition != 4)
	{
		std::cout << "YOU want to login as:\t\t\t\t\t\t" << std::endl << std::endl;
		std::cout << "1-ADMIN\n";
		std::cout << "2-STAFF\n";
		std::cout << "3-CUSTOMER\n";
		std::cin >> condition;
		if (condition == 1)
		{
			admin();
		}
		if (condition == 2)
		{

		}
		if (condition == 3)
		{
			customer();
		}
		if (condition == 4)
		{
			condition = 4;
		}
	}

	
	system("pause");
	return 0;
}