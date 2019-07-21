/************
<주소>		: p314 - OOP 프로젝트 5단계
**********
<해결방안>	:

Entity 클래스
Entity 클래스란 데이터적 성격이 강함 (데이터의 종류를 파악하는데 도움)

**********
<오답노트>	:

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
	void deposit(int amount);
	bool withdraw(int amount);
	void print() const; // 여기에 const 키워드 추가
	int getID() const; // 여기에 const 키워드 추가
	~Account();
};

#endif