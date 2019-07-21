/************
<주소>		: p494 - OOP 프로젝트 8단계
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <cstring>
#include "OOP_Account.h"
using namespace std;

Account::Account(int accID, char *name, int money)
	:accID(accID), money(money) {
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, name);
}

Account::Account(Account &another)
	:accID(another.accID), money(another.money) {
	int len = strlen(another.name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, another.name);
}

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

Account& Account::operator=(const Account& copy) {
	// 일단 메모리 해제
	delete[] name;

	// 깊은 복사
	accID = copy.accID;
	money = copy.money;

	int len = strlen(copy.name) + 1;
	name = new char[len];
	strcpy_s(name, len, copy.name);

	// 이 객체 참조 반환
	return *this;
}

Account::~Account() {
	delete[] name;
}