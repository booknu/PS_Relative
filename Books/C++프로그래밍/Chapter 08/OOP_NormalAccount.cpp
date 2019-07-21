/************
<주소>		: p363 - OOP 프로젝트 6단계
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include "OOP_NormalAccount.h"
using namespace std;

NormalAccount::NormalAccount(int accID, char *name, int money, int interest)
	: Account(accID, name, money), interest(interest) { }

void NormalAccount::deposit(int amount) {
	Account::deposit(amount);
	Account::deposit(amount * (interest / 100.0));
}

void NormalAccount::print() const {
	Account::print();
	cout << "이자율: " << interest << endl;
}