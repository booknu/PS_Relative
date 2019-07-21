/************
<�ּ�>		: p618 - OOP ������Ʈ 11�ܰ�
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