/************
<�ּ�>		: p618 - OOP ������Ʈ 11�ܰ�
**********
<�ذ���>	:

Entity Ŭ����
�ſ뵵 ���� �����Ը� �����ϴ� ���� ������ ����

**********
<�����Ʈ>	:

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