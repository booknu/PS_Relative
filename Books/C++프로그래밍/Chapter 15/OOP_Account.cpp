/************
<주소>		: p618 - OOP 프로젝트 11단계
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <cstring>
#include "OOP_Account.h"
using namespace std;

Account::Account(int accID, String name, int money)
	:accID(accID), name(name), money(money) { }

// 복사 생성자가 불필요해짐

void Account::deposit(int amount) throw(NegativeArgumentException) {
	if (amount < 0) {
		throw NegativeArgumentException();
	}
	money += amount;
}

void Account::withdraw(int amount) throw(NegativeArgumentException, LimitExceedException) {
	if (amount < 0) {
		throw NegativeArgumentException();
	} if (money < amount) {
		throw LimitExceedException();
	}

	money -= amount;
}

void Account::print() const {
	cout << "계좌ID: " << accID << endl;
	cout << "이 름: " << name << endl;
	cout << "잔 액: " << money << endl;
}

int Account::getID() const {
	return accID;
}

// operator= 구현이 불필요해짐

// 소멸자에서 할 일이 없어짐
Account::~Account() {
	
}