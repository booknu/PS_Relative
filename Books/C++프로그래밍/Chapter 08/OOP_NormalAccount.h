/************
<주소>		: p363 - OOP 프로젝트 6단계
**********
<해결방안>	:

Entity 클래스
최소한의 이자를 지급하는 자율 입출금 계좌

**********
<오답노트>	:

*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
#include "OOP_Account.h"

class NormalAccount : public Account {
private:
	int interest;

public:
	NormalAccount(int accID, char *name, int money, int interest);
	void deposit(int amount);
	void print() const;
};

#endif