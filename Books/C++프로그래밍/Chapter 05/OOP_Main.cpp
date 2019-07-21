/************
<�ּ�>		: p240 - OOP ������Ʈ 3�ܰ�
**********
<�ذ���>	:

Main ������

**********
<�����Ʈ>	:

*/

#include <iostream>
#include "OOP_Account.h"

using namespace std;
const int NAME_LEN = 100;

int infoAndSelect();
bool processSelection(int select);
void createNewAccount();
void deposit();
void withdraw();
void printAll();

namespace INPUT_CONST {
	enum { NEWACCOUNT = 1, DEPOSIT, WITHDRAW, PRINTALL, EXIT };
}

Account *accArr[1000];
int accNum = 0;

int main(void) {
	while (true) {
		int select = infoAndSelect();
		if (select == INPUT_CONST::EXIT) {
			break;
		}
		processSelection(select);
	}

	for (int i = 0; i < accNum; i++) {
		delete accArr[i];
	}
}

int infoAndSelect() {
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

bool processSelection(int select) {
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

void createNewAccount() {
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

void deposit() {
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

void withdraw() {
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

void printAll() {
	cout << "[ ������ ]" << endl;
	for (int i = 0; i < accNum; i++) {
		accArr[i]->print();
	}
}