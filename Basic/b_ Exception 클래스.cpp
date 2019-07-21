/************
<�ּ�>		: p606, p609
**********
<�ذ���>	:

p606: ���� Ŭ���� ����
p609: ���� Ŭ���� ���

**********
<�����Ʈ>	:

�����Ϸ����� �߻��ϴ� Warning �޼���
"__declspec(nothrow)�� �ƴ��� ��Ÿ������ ��츦 �����ϰ� C++ ���� ����� ���õ˴ϴ�."
��, c++������ ����ó���� �ǹ������� �ƴ϶�

"throw()"�� ������ ���� ���ܰ� �߻����� �ʴ� �Լ���°� Ȯ���� �� ������,
"throw(����...)"�� ������ ���� �����ϴ� ���� ���� ���ܵ� �߻��� �� �ִٴ� ���� �˷��ִ� ����

==> ������ ������ �ƴ�, �׷� ���� �ִٴ� ���

*/

#include <iostream>
#include <cstring>
using namespace std;

/**
 *	Exception Ŭ�������� ��ü�� �Ǵ� Abstract Class.
 *	�̰��� ����� ����� �� �ִ�.
 */
class AccountException {
public:
	virtual void printStackTrace() = 0;
};

/**
 *	Exception Ŭ����.
 *	AccountException�� �����Ͽ� ���.
 */
class DepositException : public AccountException {
private:
	int reqDep;

public:
	DepositException(int money) : reqDep(money) { }
	void printStackTrace() {
		cout << "DepositException (" << reqDep << ')' << endl;
	}
};

/**
 *	Exception Ŭ����.
 *	AccountException�� �����Ͽ� ���.
 */
class WithdrawException : public AccountException {
private:
	int balance;

public:
	WithdrawException(int money) : balance(money) { }
	void printStackTrace() {
		cout << "WithdrawException (balance = " << balance << ')' << endl;
	}
};

class Account {
private:
	char accNum[50];
	int balance;

public:
	Account(char *acc, int money) : balance(money) {
		strcpy_s(accNum, acc);
	}

	/**
	 *	���ܸ� ������ �Լ�
	 *
	 *	@throw AccountException	�Աݾ��� ������ ��
	 */
	void deposit(int amount) throw (AccountException) {
		if (amount < 0) {
			throw DepositException(amount);
		}
		balance += amount;
	}

	/**
	 *	���ܸ� ������ �Լ�
	 *	
	 *	@throw AccountException	������� �ܾ׺��� Ŭ ��
	 */
	void withdraw(int amount) throw (AccountException) {
		if (balance < amount) {
			throw WithdrawException(balance);
		}
		balance -= amount;
	}

	void print() {
		cout << "�ܰ�: " << balance << endl;
	}
};

class Main {
public:
	static int main() {
		Account acc("1234-1234", 5000);

		try {
			acc.deposit(2000);
			acc.deposit(-100);
		} catch (AccountException &e) {
			// AccountException�� catch �� ���� �ְ�, DepositException�� catch �� ���� ����
			e.printStackTrace();
		}
		acc.print();

		try {
			acc.withdraw(3000);
			acc.withdraw(100000);
		} catch (AccountException &e) {
			// AccountException�� catch �� ���� �ְ�, WithdrawException�� catch �� ���� ����
			e.printStackTrace();
		}
		acc.print();

		return 0;
	}
};