/************
<�ּ�>		: p553 - OOP ������Ʈ 10�ܰ�
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
#include "OOP_NormalAccount.h"
using namespace std;

NormalAccount::NormalAccount(int accID, String name, int money, int interest)
	: Account(accID, name, money), interest(interest) { }

void NormalAccount::deposit(int amount) {
	Account::deposit(amount);
	Account::deposit(amount * (interest / 100.0));
}

void NormalAccount::print() const {
	Account::print();
	cout << "������: " << interest << endl;
}