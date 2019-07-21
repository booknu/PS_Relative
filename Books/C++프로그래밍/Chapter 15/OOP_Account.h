/************
<주소>		: p618 - OOP 프로젝트 11단계
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

#include "OOP_String.h"
#include "OOP_Exceptions.h"

class Account {
private:
	int accID;
	int money;
	String name;

public:
	Account(int accID, String name, int money);

	virtual void deposit(int amount) throw(NegativeArgumentException);
	void withdraw(int amount) throw(NegativeArgumentException, LimitExceedException);
	virtual void print() const;
	int getID() const;

	virtual ~Account();
};

#endif