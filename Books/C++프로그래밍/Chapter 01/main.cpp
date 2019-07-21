/************
<주소>		: p50 - OOP 프로젝트 단계 1
**********
<해결방안>	:

**********
<오답노트>	:
1. 함수를 분할하여 각각이 개설, 입금, 출금...을 할 수 있도록 하는 것이 좋음
2. 출금시 잔액부족 체크

*/

#include <iostream>

using namespace std;

typedef struct {
	int id;
	char name[100];
	int balance;
} account;

int main(void) {

	account accounts[1000];
	int acctnum = 0;

	bool finished = false;
	while (!finished) {
		cout << "----- menu -----" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택: ";
		int input;
		cin >> input;
		cout << endl;

		// c++에서는 다른 블럭에 있어도 하나의 function이나 그것에 호출된 function들끼리 변수명이 중복되면 안 됨
		int id, deposit, withdraw;
		account* newacct;
		switch (input) {
		// create account
		case 1:
			newacct = &accounts[acctnum++]; // newacct의 초기화는 선언과 다른줄에서 해야 compilation error가 나지 않음
			cout << "[계좌개설]" << endl;
			cout << "계좌id: ";
			cin >> newacct->id;
			cout << "이 름: ";
			cin >> newacct->name;
			cout << "입금액: ";
			cin >> newacct->balance;
			cout << "계좌가 생성되었습니다!" << endl << endl;
			break;
		// deposit
		case 2:
			cout << "[입   금]" << endl;
			cout << "계좌id: ";
			cin >> id;
			cout << "입금액: ";
			cin >> deposit;
			for (int i = 0; i < acctnum; i++) {
				if (accounts[i].id == id) {
					accounts[i].balance += deposit;
					goto found_depos;
				}
			}
		notfound_depos:
			cout << "error: 해당 계좌를 찾지 못했습니다..." << endl << endl;
			break;
		found_depos:
			cout << "입금이 완료되었습니다!" << endl << endl;
			break;
		// withdraw
		case 3:
			cout << "[출   금]" << endl;
			cout << "계좌id: ";
			cin >> id;
			cout << "출금액: ";
			cin >> withdraw;;
			for (int i = 0; i < acctnum; i++) {
				if (accounts[i].id == id) {
					accounts[i].balance -= withdraw;
					goto found_withdraw;
				}
			}
		notfound_withdraw:
			cout << "error: 해당 계좌를 찾지 못했습니다..." << endl << endl;
			break;
		found_withdraw:
			cout << "출금이 완료되었습니다!" << endl << endl;
			break;
		// print all
		case 4:
			cout << "[계좌정보 전체 출력]" << endl;
			for (int i = 0; i < acctnum; i++) {
				account *curr;
				curr = &accounts[i];
				cout << "(id = " << curr->id << ", name = " << curr->name << ", balance = " << curr->balance << ")" << endl;
			}
			cout << "출력이 완료되었습니다!" << endl << endl;
			break;
		// program exit
		case 5:
			cout << "프로그램을 종료합니다..." << endl;
			finished = true;
			break;
		// wrong input
		default:
			cout << "error: 잘못된 입력입니다..." << endl;
		}
	}
}