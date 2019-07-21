/************
<주소>		: p553 - OOP 프로젝트 10단계
**********
<해결방안>	:

**********
<오답노트>	:

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
	cout << "이자율: " << interest << endl;
}