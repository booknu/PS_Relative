/************
<주소>		: p553 - OOP 프로젝트 10단계
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

void Account::deposit(int amount) {
	money += amount;
}

bool Account::withdraw(int amount) {
	if (amount > money) {
		return false;
	}
	money -= amount;
	return true;
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