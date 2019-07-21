/************
<�ּ�>		: p202 - OOP ������Ʈ 2�ܰ�
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
	this->name = new char[len + 1]; // heap�� ���� �Ҵ� ��, (�޸� Ȯ��)
	strcpy_s(this->name, len + 1, name); // �� ���� name�� ����
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
	// �Ҵ�� �޸� ����
	delete[] name;
}