/************
<주소>		: p494 - OOP 프로젝트 8단계
**********
<해결방안>	:

Entity 클래스
Entity 클래스란 데이터적 성격이 강함 (데이터의 종류를 파악하는데 도움)

**********
<오답노트>	:

1. 인자로 받는 copy를 const형으로 하지 않았음

*/

#ifndef __ACCOUNT_H_
#define __ACCOUNT_H_

class Account {
private:
	int accID;
	int money;
	char *name;

public:
	Account(int accID, char *name, int money);
	Account(Account &another);

	virtual void deposit(int amount);
	bool withdraw(int amount);
	virtual void print() const;
	int getID() const;

	Account& operator=(const Account& copy); // 대입 연산자도 깊은 복사를 할 수 있게 오버로딩

	virtual ~Account();
};

#endif