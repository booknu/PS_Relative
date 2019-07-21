/************
<주소>		: p618 - OOP 프로젝트 11단계
**********
<해결방안>	:

Entity 클래스
신용도 높은 고객에게만 개설하는 높은 이율의 계좌

**********
<오답노트>	:

*/

#ifndef __HIGHCREDIT_ACCOUNT_H
#define __HIGHCREDIT_ACCOUNT_H
#include "OOP_NormalAccount.h"

namespace CREDIT_LV {
	enum { A = 7, B = 4, C = 2 };
}

class HighCreditAccount : public NormalAccount {
private:
	int credit;

public:
	HighCreditAccount(int accID, String name, int money, int interest, int credit);
	virtual void deposit(int amount);
	virtual void print() const;
};

#endif