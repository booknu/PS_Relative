/************
<�ּ�>		: p363 - OOP ������Ʈ 6�ܰ�
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
	NormalAccount(int accID, char *name, int money, int interest);
	void deposit(int amount);
	void print() const;
};

#endif