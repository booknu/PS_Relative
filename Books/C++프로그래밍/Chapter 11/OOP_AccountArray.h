/************
<�ּ�>		: p494 - OOP ������Ʈ 8�ܰ�
**********
<�ذ���>	:

Account ��ü���� �����ϱ� ���� Array Ŭ����

**********
<�����Ʈ>	:

1. [] �����ڸ� �����ε� �� �� ��ȯ���� ��� �� �� �����
   ó������ Account&�� ��ȯ�ϰ� ������µ�, �迭�� ���� �� new �� ���� �ִ´ٴ� ���� ���ݰ�
   Account*�� ��ȯ�ϰ� ���������,
   �� ���� ��ȯ�� �����ͷ� ���� �������� ���ϴ� ������ �־���.
   ==> ���� �����ϰ� �Ϸ��� ACC_PTR&�� ��ȯ�ϰ� ����

*/

#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "OOP_Account.h"
typedef Account* ACC_PTR;

class AccountArray {
private:
	ACC_PTR *arr;
	// ����ؼ��� �� �� ���� ������, ���� ������
	AccountArray(const AccountArray &copy);
	AccountArray& operator=(const AccountArray &copy);

public:
	const int length;

public:
	AccountArray(int length);

	// [] ������ �����ε�
	// ���� �����ϰ� �Ϸ��� ACC_PTR& �� ��ȯ���Ѿ� ��!!!!
	ACC_PTR& operator[](int index);
	ACC_PTR operator[](int index) const;

	~AccountArray();
};

#endif