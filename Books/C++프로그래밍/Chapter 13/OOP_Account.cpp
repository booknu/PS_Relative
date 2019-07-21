/************
<�ּ�>		: p553 - OOP ������Ʈ 10�ܰ�
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <cstring>
#include "OOP_Account.h"
using namespace std;

Account::Account(int accID, String name, int money)
	:accID(accID), name(name), money(money) { }

// ���� �����ڰ� ���ʿ�����

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

// operator= ������ ���ʿ�����

// �Ҹ��ڿ��� �� ���� ������
Account::~Account() {
	
}