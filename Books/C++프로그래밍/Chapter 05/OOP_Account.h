/************
<주소>		: p240 - OOP 프로젝트 3단계
**********
<해결방안>	:

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
	void print() const;
	int getID() const;
	~Account();
};

#endif