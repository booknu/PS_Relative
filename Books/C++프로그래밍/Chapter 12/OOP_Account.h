/************
<�ּ�>		: p515 - OOP ������Ʈ 9�ܰ�
**********
<�ذ���>	:

Entity Ŭ����
Entity Ŭ������ �������� ������ ���� (�������� ������ �ľ��ϴµ� ����)

**********
<�����Ʈ>	:

1. ���ڷ� �޴� copy�� const������ ���� �ʾ���

*/

#ifndef __ACCOUNT_H_
#define __ACCOUNT_H_

#include "OOP_String.h"

class Account {
private:
	int accID;
	int money;
	String name;

public:
	Account(int accID, String name, int money);

	virtual void deposit(int amount);
	bool withdraw(int amount);
	virtual void print() const;
	int getID() const;

	virtual ~Account();
};

#endif