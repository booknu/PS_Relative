/************
<주소>		: p202 - OOP 프로젝트 2단계
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
	this->name = new char[len + 1]; // heap에 동적 할당 후, (메모리 확보)
	strcpy_s(this->name, len + 1, name); // 그 곳에 name을 복사
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
	cout << "-------------" << endl;
}

int Account::getID() const {
	return accID;
}

Account::~Account() {
	// 할당된 메모리 해제
	delete[] name;
}