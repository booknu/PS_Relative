/************
<주소>		: p618 - OOP 프로젝트 11단계 
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include "OOP_HighCreditAccount.h"
using namespace std;

HighCreditAccount::HighCreditAccount(int accID, String name, int money, int interest, int credit) 
	: NormalAccount(accID, name, money, interest), credit(credit) { }

void HighCreditAccount::print() const {
	NormalAccount::print();
	cout << "신용등급: ";
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
		cout << "Error: 알 수 없는 신용등급";
	}
}

void HighCreditAccount::deposit(int amount) {
	NormalAccount::deposit(amount);
	Account::deposit(amount * (credit / 100.0));
}