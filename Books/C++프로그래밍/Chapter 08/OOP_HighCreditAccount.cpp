/************
<�ּ�>		: p363 - OOP ������Ʈ 6�ܰ�
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
#include "OOP_HighCreditAccount.h"
using namespace std;

HighCreditAccount::HighCreditAccount(int accID, char *name, int money, int interest, int credit) 
	: NormalAccount(accID, name, money, interest), credit(credit) { }

void HighCreditAccount::print() const {
	NormalAccount::print();
	cout << "�ſ���: ";
	switch (credit) {
	case CREDIT_LV::A :
		cout << "A" << endl;
		break;
	case CREDIT_LV::B:
		cout << "B" << endl;
		break;
	case CREDIT_LV::C:
		cout << "C" << endl;
		break;
	default:
		cout << "Error: �� �� ���� �ſ���";
	}
}

void HighCreditAccount::deposit(int amount) {
	NormalAccount::deposit(amount);
	Account::deposit(amount * (credit / 100.0));
}