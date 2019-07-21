/************
<�ּ�>		: p494 - OOP ������Ʈ 8�ܰ�
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

class Account {
private:
	int accID;
	int money;
	char *name;

public:
	Account(int accID, char *name, int money);
	Account(Account &another);

	virtual void deposit(int amount);
	bool withdraw(int amount);
	virtual void print() const;
	int getID() const;

	Account& operator=(const Account& copy); // ���� �����ڵ� ���� ���縦 �� �� �ְ� �����ε�

	virtual ~Account();
};

#endif