/************
<주소>		: p202 - OOP 프로젝트 2단계
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
	void deposit(int amount);
	bool withdraw(int amount);
	void print() const;
	int getID() const;
	~Account();
};

#endif