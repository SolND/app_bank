#include"staff.hpp"
using namespace std;
void staff()
{
	Bank_tree t;
	Hash_table h;
	int condition = 0;
	while (condition != 5)
	{
		cout << "\nwelcome STAFF" << endl;
		cout << "choose the following please" << endl;
		cout << "press 1 to see transaction history  " << endl;
		cout << "press 2 to transfer " << endl;
		cout << "press 3 to withdraw " << endl;
		cout << "press 4 to deposit " << endl;
		cout << "press 5 to exit" << endl;
		cout << "Enter selection: ";
		cin >> condition;
		if (condition == 1)
		{
			t.transaction_history();
		}
		if (condition == 2)
		{
			int senderaccount = 0, amount = 0, recieveraccount=0;
			cout << "Vui lòng nhập số tài khoản người gửi: ";
			cin >> senderaccount;
			cout << "Vui lòng nhập số tài khoản người nhận: ";
			cin >> recieveraccount;
			cout << "Vui lòng nhập số tiền: ";
			cin >> amount;
			t.transfer(senderaccount,amount,recieveraccount);
		}
		if (condition == 3)  // withdraw
		{
			int account = 0, amount = 0;
			cout << "Vui lòng nhập số tài khoản";
			cin >> account;
			cout << "Vui lòng nhập số tiền:";
			cin >> amount;
			t.with_draw(account, amount);
		}
		if (condition == 4)
		{
			int accountno = 0, amount = 0;
			cout << "Vui lòng nhập số tài khoản: ";
			cin >> accountno;
			cout << "Vui lòng nhập số tiền:";
			cin >> amount;
			t.deposit(accountno, amount);
		}
		if (condition == 5)
		{
			condition = 5;
		}

	}

}