/************
<�ּ�>		: p494 - OOP ������Ʈ 8�ܰ�
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
}

int Account::getID() const {
	return accID;
}

Account& Account::operator=(const Account& copy) {
	// �ϴ� �޸� ����
	delete[] name;

	// ���� ����
	accID = copy.accID;
	money = copy.money;

	int len = strlen(copy.name) + 1;
	name = new char[len];
	strcpy_s(name, len, copy.name);

	// �� ��ü ���� ��ȯ
	return *this;
}

Account::~Account() {
	delete[] name;
}