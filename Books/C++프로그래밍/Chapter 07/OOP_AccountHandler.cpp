/************
<�ּ�>		: p314 - OOP ������Ʈ 5�ܰ�
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
#include "OOP_AccountHandler.h"
using namespace std;

AccountHandler::AccountHandler() 
	: accNum(0) {
}

int AccountHandler::infoAndSelect() {
	cout << endl;
	cout << "----- Menu -----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
	int ret;
	cin >> ret;
	cout << endl;
	return ret;
}

bool AccountHandler::processSelection(int select) {
	switch (select) {
	case INPUT_CONST::NEWACCOUNT:
		createNewAccount();
		return false;
	case INPUT_CONST::DEPOSIT:
		deposit();
		return false;
	case INPUT_CONST::WITHDRAW:
		withdraw();
		return false;
	case INPUT_CONST::PRINTALL:
		printAll();
		return false;
	case INPUT_CONST::EXIT:
		cout << "���α׷��� �����մϴ�..." << endl;
		return true;
	default:
		cout << "ERROR: �߸��� �Է��Դϴ�." << endl;
		return false;
	}
}

void AccountHandler::createNewAccount() {
	int id, money;
	char name[NAME_LEN];
	cout << "[ ���°��� ]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�� ��: ";
	cin >> name;
	cout << "�� ��: ";
	cin >> money;

	accArr[accNum++] = new Account(id, name, money);
}

void AccountHandler::deposit() {
	int id, money;
	cout << "[ ��   �� ]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�Աݾ�: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getID() == id) {
			accArr[i]->deposit(money);
			cout << "�Ա� �Ϸ�!!" << endl;
			return;
		}
	}
	cout << "ERROR: �ش� ���¸� ã�� ���߽��ϴ�..." << endl;
}

void AccountHandler::withdraw() {
	int id, money;
	cout << "[ ��   �� ]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "��ݾ�: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getID() == id) {
			if (accArr[i]->withdraw(money)) {
				cout << "��� �Ϸ�!!" << endl;
			} else {
				cout << "ERROR: �ܾ��� �����մϴ�..." << endl;
			}
			return;
		}
	}
	cout << "ERROR: �ش� ���¸� ã�� ���߽��ϴ�..." << endl;
}

void AccountHandler::printAll() {
	cout << "[ ������ ]" << endl;
	for (int i = 0; i < accNum; i++) {
		accArr[i]->print();
	}
}

// �Ҵ�� ��� Account ��ü�� ����
AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++) {
		delete accArr[i];
	}
}