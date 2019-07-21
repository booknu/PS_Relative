/************
<주소>		: p606, p609
**********
<해결방안>	:

p606: 예외 클래스 정의
p609: 예외 클래스 상속

**********
<오답노트>	:

컴파일러에서 발생하는 Warning 메세지
"__declspec(nothrow)가 아님을 나타내려는 경우를 제외하고 C++ 예외 사양은 무시됩니다."
는, c++에서는 예외처리가 의무사항이 아니라

"throw()"로 지정된 경우는 예외가 발생하지 않는 함수라는걸 확신할 수 있지만,
"throw(인자...)"로 지정된 경우는 지정하는 인자 외의 예외도 발생할 수 있다는 것을 알려주는 것임

==> 문법적 문제가 아닌, 그럴 수도 있다는 얘기

*/

#include <iostream>
#include <cstring>
using namespace std;

/**
 *	Exception 클래스들의 모체가 되는 Abstract Class.
 *	이것을 상속해 사용할 수 있다.
 */
class AccountException {
public:
	virtual void printStackTrace() = 0;
};

/**
 *	Exception 클래스.
 *	AccountException을 구현하여 사용.
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
 *	Exception 클래스.
 *	AccountException을 구현하여 사용.
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
	 *	예외를 던지는 함수
	 *
	 *	@throw AccountException	입금액이 음수일 때
	 */
	void deposit(int amount) throw (AccountException) {
		if (amount < 0) {
			throw DepositException(amount);
		}
		balance += amount;
	}

	/**
	 *	예외를 던지는 함수
	 *	
	 *	@throw AccountException	인출액이 잔액보다 클 때
	 */
	void withdraw(int amount) throw (AccountException) {
		if (balance < amount) {
			throw WithdrawException(balance);
		}
		balance -= amount;
	}

	void print() {
		cout << "잔고: " << balance << endl;
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
			// AccountException을 catch 할 수도 있고, DepositException을 catch 할 수도 있음
			e.printStackTrace();
		}
		acc.print();

		try {
			acc.withdraw(3000);
			acc.withdraw(100000);
		} catch (AccountException &e) {
			// AccountException을 catch 할 수도 있고, WithdrawException을 catch 할 수도 있음
			e.printStackTrace();
		}
		acc.print();

		return 0;
	}
};