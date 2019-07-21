/************
<�ּ�>		: p50 - OOP ������Ʈ �ܰ� 1
**********
<�ذ���>	:

**********
<�����Ʈ>	:
1. �Լ��� �����Ͽ� ������ ����, �Ա�, ���...�� �� �� �ֵ��� �ϴ� ���� ����
2. ��ݽ� �ܾ׺��� üũ

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
		cout << "1. ���°���" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "����: ";
		int input;
		cin >> input;
		cout << endl;

		// c++������ �ٸ� ���� �־ �ϳ��� function�̳� �װͿ� ȣ��� function�鳢�� �������� �ߺ��Ǹ� �� ��
		int id, deposit, withdraw;
		account* newacct;
		switch (input) {
		// create account
		case 1:
			newacct = &accounts[acctnum++]; // newacct�� �ʱ�ȭ�� ����� �ٸ��ٿ��� �ؾ� compilation error�� ���� ����
			cout << "[���°���]" << endl;
			cout << "����id: ";
			cin >> newacct->id;
			cout << "�� ��: ";
			cin >> newacct->name;
			cout << "�Աݾ�: ";
			cin >> newacct->balance;
			cout << "���°� �����Ǿ����ϴ�!" << endl << endl;
			break;
		// deposit
		case 2:
			cout << "[��   ��]" << endl;
			cout << "����id: ";
			cin >> id;
			cout << "�Աݾ�: ";
			cin >> deposit;
			for (int i = 0; i < acctnum; i++) {
				if (accounts[i].id == id) {
					accounts[i].balance += deposit;
					goto found_depos;
				}
			}
		notfound_depos:
			cout << "error: �ش� ���¸� ã�� ���߽��ϴ�..." << endl << endl;
			break;
		found_depos:
			cout << "�Ա��� �Ϸ�Ǿ����ϴ�!" << endl << endl;
			break;
		// withdraw
		case 3:
			cout << "[��   ��]" << endl;
			cout << "����id: ";
			cin >> id;
			cout << "��ݾ�: ";
			cin >> withdraw;;
			for (int i = 0; i < acctnum; i++) {
				if (accounts[i].id == id) {
					accounts[i].balance -= withdraw;
					goto found_withdraw;
				}
			}
		notfound_withdraw:
			cout << "error: �ش� ���¸� ã�� ���߽��ϴ�..." << endl << endl;
			break;
		found_withdraw:
			cout << "����� �Ϸ�Ǿ����ϴ�!" << endl << endl;
			break;
		// print all
		case 4:
			cout << "[�������� ��ü ���]" << endl;
			for (int i = 0; i < acctnum; i++) {
				account *curr;
				curr = &accounts[i];
				cout << "(id = " << curr->id << ", name = " << curr->name << ", balance = " << curr->balance << ")" << endl;
			}
			cout << "����� �Ϸ�Ǿ����ϴ�!" << endl << endl;
			break;
		// program exit
		case 5:
			cout << "���α׷��� �����մϴ�..." << endl;
			finished = true;
			break;
		// wrong input
		default:
			cout << "error: �߸��� �Է��Դϴ�..." << endl;
		}
	}
}