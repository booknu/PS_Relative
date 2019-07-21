/************
<�ּ�>		: p515 - OOP ������Ʈ 9�ܰ�
**********
<�ذ���>	:

Entity Ŭ����
�ּ����� ���ڸ� �����ϴ� ���� ����� ����

**********
<�����Ʈ>	:

*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
#include "OOP_Account.h"

class NormalAccount : public Account {
private:
	int interest;

public:
	NormalAccount(int accID, String name, int money, int interest);
	virtual void deposit(int amount);
	virtual void print() const;
};

#endif