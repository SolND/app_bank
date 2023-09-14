#include "admin.hpp"
using namespace std;
void admin()
{
	Bank_tree t;
	Hash_table h;
	int condition = 0;
	while (condition != 6)
	{
		cout << "welcome ADMIN" << endl;
		cout << "choose the following please" << endl;
		cout << "press 1 to add account " << endl;
		cout << "press 2 to delete account " << endl;
		cout << "press 3 to check all account " << endl;
		cout << "press 4 to see password of account " << endl;
		cout << "press 5 to edit account " << endl;
		cout << "press 6 to exit" << endl;
		cin >> condition;
		if (condition == 1)
		{
			string n = "", a = "", p = "";
			int acc, b;
			cout << "Import name: ";
			cin >> n;
			cout << "Import adress: ";
			cin >> a;
			cout << "Import account number: ";
			cin >> acc;
			cout << "Import password: ";
			cin >> p;
			cout << "Import balance";
			cin >> b;
			t.add_account(n, a, acc, p, b);
		}
		if (condition == 2)
		{
			int acc = 0;
			cout << "Import account number: ";
			cin >> acc;
			t.load_server();
			t.set_root(t.delete_account(t.get_root(), acc));
			cout << "bar a gia delete se: ";
			h.delete_password(acc);
			cout << "delete pass: ";
			t.update_server(t.get_root());
			cout << "update h gia: ";
		}
		if (condition == 3)
		{
			t.load_server();
			t.printoinfo(t.get_root());
		}
		if (condition == 4)
		{
			h.display_password();
		}
		if (condition == 5)
		{

		}
		if (condition == 6)
		{
			condition = 6;
		}
	}
}