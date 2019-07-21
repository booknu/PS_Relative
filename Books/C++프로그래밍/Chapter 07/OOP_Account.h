/************
<�ּ�>		: p314 - OOP ������Ʈ 5�ܰ�
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
	void deposit(int amount);
	bool withdraw(int amount);
	void print() const; // ���⿡ const Ű���� �߰�
	int getID() const; // ���⿡ const Ű���� �߰�
	~Account();
};

#endif