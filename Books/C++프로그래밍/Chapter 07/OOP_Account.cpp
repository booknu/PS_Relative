/************
<�ּ�>		: p314 - OOP ������Ʈ 5�ܰ�
**********
<�ذ���>	:

**********
<�����Ʈ>	:

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
	cout << "����ID: " << accID << endl;
	cout << "�� ��: " << name << endl;
	cout << "�� ��: " << money << endl;
	cout << "-------------" << endl;
}

int Account::getID() const {
	return accID;
}

Account::~Account() {
	delete[] name;
}