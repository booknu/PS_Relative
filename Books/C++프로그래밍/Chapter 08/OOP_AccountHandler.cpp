/************
<주소>		: p363 - OOP 프로젝트 6단계
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include "OOP_AccountHandler.h"
#include "OOP_HighCreditAccount.h"
using namespace std;

AccountHandler::AccountHandler() 
	: accNum(0) {
}

int AccountHandler::infoAndSelect() {
	cout << endl;
	cout << "----- Menu -----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
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
		cout << "프로그램을 종료합니다..." << endl;
		return true;
	default:
		cout << "ERROR: 잘못된 입력입니다." << endl;
		return false;
	}
}

/**
	새로운 계좌 종류를 선택하고, 그에 따라 처리를 한다.

	@return 제대로 된 선택을 했는지?
*/
bool AccountHandler::createNewAccount() {
	int select;
	cout << "[ 계좌종류선택 ]" << endl;
	cout << "1.보통예금계좌  2.신용신뢰계좌" << endl;
	cout << "선택: ";
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
		cout << "ERROR: 잘못된 입력입니다." << endl;
		return false;
	}
}

/**
	보통예금계좌를 개설한다.
*/
void AccountHandler::createNewNormalAccount() {
	int id, money, interest;
	char name[NAME_LEN];
	cout << "[ 보통예금계좌 개설 ]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이 름: ";
	cin >> name;
	cout << "잔 액: ";
	cin >> money;
	cout << "이자율: ";
	cin >> interest;

	accArr[accNum++] = new NormalAccount(id, name, money, interest);
}

/**
	신용신뢰계좌를 개설한다.
*/
void AccountHandler::createNewHighCreditAccount() {
	int id, money, interest, credit;
	char name[NAME_LEN];
	cout << "[ 신용신뢰계좌 개설 ]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이 름: ";
	cin >> name;
	cout << "잔 액: ";
	cin >> money;
	cout << "이자율: ";
	cin >> interest;
	cout << "신용등급(1: A, 2: B, 3: C): ";
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
		cout << "Error: 잘못된 신용등급 입니다." << endl;
		return;
	}

	accArr[accNum++] = new HighCreditAccount(id, name, money, interest, credit);
}

void AccountHandler::deposit() {
	int id, money;
	cout << "[ 입   금 ]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getID() == id) {
			accArr[i]->deposit(money);
			cout << "입금 완료!!" << endl;
			return;
		}
	}
	cout << "ERROR: 해당 계좌를 찾지 못했습니다..." << endl;
}

void AccountHandler::withdraw() {
	int id, money;
	cout << "[ 출   금 ]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->getID() == id) {
			if (accArr[i]->withdraw(money)) {
				cout << "출금 완료!!" << endl;
			} else {
				cout << "ERROR: 잔액이 부족합니다..." << endl;
			}
			return;
		}
	}
	cout << "ERROR: 해당 계좌를 찾지 못했습니다..." << endl;
}

void AccountHandler::printAll() {
	cout << "[ 모든계좌 ]" << endl;
	for (int i = 0; i < accNum; i++) {
		accArr[i]->print();
		cout << "----------------" << endl;
	}
}

// 할당된 모든 Account 객체들 삭제
AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++) {
		delete accArr[i];
	}
}