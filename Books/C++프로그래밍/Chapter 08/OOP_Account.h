/************
<�ּ�>		: p363 - OOP ������Ʈ 6�ܰ�
**********
<�ذ���>	:

Entity Ŭ����
Entity Ŭ������ �������� ������ ���� (�������� ������ �ľ��ϴµ� ����)

**********
<�����Ʈ>	:

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
	virtual void print() const; // ���⿡ virtual Ű���� �߰�
	int getID() const;
	virtual ~Account(); // ���⿡ virtual Ű���� �߰�
};

#endif