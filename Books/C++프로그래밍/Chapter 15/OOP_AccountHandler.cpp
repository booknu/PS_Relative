/************
<�ּ�>		: p618 - OOP ������Ʈ 11�ܰ�
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
#include "OOP_AccountHandler.h"
#include "OOP_HighCreditAccount.h"
using namespace std;

AccountHandler::AccountHandler() 
	: accNum(0), accArr(1000) {

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
		return createNewAccount();
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

/**
	���ο� ���� ������ �����ϰ�, �׿� ���� ó���� �Ѵ�.

	@return ����� �� ������ �ߴ���?
*/
bool AccountHandler::createNewAccount() {
	int select;
	cout << "[ ������������ ]" << endl;
	cout << "1.���뿹�ݰ���  2.�ſ�ŷڰ���" << endl;
	cout << "����: ";
	cin >> select;
	cout << endl;

	switch (select) {
	case ACC_TYPE_CONST::NORMAL:
		createNewNormalAccount();
		return true;
	case ACC_TYPE_CONST::HIGHCREDIT:
		createNewHighCreditAccount();
		return true;
	default:
		cout << "ERROR: �߸��� �Է��Դϴ�." << endl;
		return false;
	}
}

/**
	���뿹�ݰ��¸� �����Ѵ�.
*/
void AccountHandler::createNewNormalAccount() {
	int id, money, interest;
	String name;
	cout << "[ ���뿹�ݰ��� ���� ]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�� ��: ";
	cin >> name;
	cout << "�� ��: ";
	cin >> money;
	cout << "������: ";
	cin >> interest;

	accArr[accNum++] = new NormalAccount(id, name, money, interest);
}

/**
	�ſ�ŷڰ��¸� �����Ѵ�.
*/
void AccountHandler::createNewHighCreditAccount() {
	int id, money, interest, credit;
	String name;
	cout << "[ �ſ�ŷڰ��� ���� ]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�� ��: ";
	cin >> name;
	cout << "�� ��: ";
	cin >> money;
	cout << "������: ";
	cin >> interest;
	cout << "�ſ���(1: A, 2: B, 3: C): ";
	cin >> credit;
	switch (credit) {
	case 1: 
		credit = CREDIT_LV::A;
		break;
	case 2:
		credit = CREDIT_LV::B;
		break;
	case 3:
		credit = CREDIT_LV::C;
		break;
	default:
		cout << "Error: �߸��� �ſ��� �Դϴ�." << endl;
		return;
	}

	accArr[accNum++] = new HighCreditAccount(id, name, money, interest, credit);
}

void AccountHandler::deposit() {
	int id, money;
	cout << "[ ��   �� ]" << endl;
	cout << "����ID: ";
	cin >> id;
	

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getID() == id) {
			while (1) {
				cout << "�Աݾ�: ";
				cin >> money;
				try {
					accArr[i]->deposit(money);
					cout << "�Ա� �Ϸ�!!" << endl;
					break;
				} catch (NegativeArgumentException &e) {
					e.printStackTrace("�߸��� �Է��Դϴ�.");
					cout << "���Է��� ���ּ���." << endl;
				}
			}
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

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getID() == id) {
			while (1) {
				cout << "��ݾ�: ";
				cin >> money;
				try {
					accArr[i]->withdraw(money);
					cout << "��� �Ϸ�!" << endl;
					break;
				} catch (NegativeArgumentException &e) {
					e.printStackTrace("�߸��� �Է��Դϴ�.");
					cout << "���Է��� ���ּ���." << endl;
				} catch (LimitExceedException &e) {
					e.printStackTrace("�ܾ��� �ʰ��ϴ� �ݾ��Դϴ�.");
					cout << "���Է��� ���ּ���." << endl;
				}
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
		cout << "----------------" << endl;
	}
}

// �Ҵ�� ��� Account ��ü�� ����
AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++) {
		delete accArr[i];
	}
}