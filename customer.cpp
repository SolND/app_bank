#include "customer.hpp"
using namespace std;
void customer()
{
	Bank_tree t;
	Hash_table h;
	int condition = 0;
	while (condition != 3)
	{
		cout << "welcome CUSTOMER" << endl;
		cout << "choose the following please" << endl;
		cout << "press 1 to see account details" << endl;
		cout << "press 2 to see transaction history  " << endl;
		cout << "press 3 to exit" << endl;
		cin >> condition;
		if (condition == 1)
		{
			int accountno;
			cout << "please enter account number" << endl;
			cin >> accountno;
			Bank_node* temp = t.search(t.get_root(), accountno);
			cout << "Account Details Are :\t\t\t\t\t\t " << endl << endl;
			cout << "NAME :" << temp->get_name() << endl;
			cout << "ADRESS :" << temp->get_address() << endl;
			cout << "ACCOUNT NUMBER :" << temp->get_account_number() << endl;
			cout << "PASSWORD :" << temp->get_password() << endl;
			cout << "BALANCE :" << temp->get_balance() << endl;
		}
		if (condition == 2)
		{
			// transaction file print karani ha account search kr k
		}
		if (condition == 3)
		{
			condition = 3;
		}

	}

}