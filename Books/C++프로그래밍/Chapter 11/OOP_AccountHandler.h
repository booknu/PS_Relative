/************
<�ּ�>		: p494 - OOP ������Ʈ 8�ܰ�
**********
<�ذ���>	:

Handler Ŭ����
Handler Ŭ������ ���α׷� ��ü�� ����� ��� (����� ����)
���α׷� ��ü ���, �帧�� �ľ��� �� �ִ�.

**********
<�����Ʈ>	:

*/

#ifndef __ACCOUNTHANDLER_H_
#define __ACCOUNTHANDLER_H_
#include "OOP_AccountArray.h"

const int NAME_LEN = 100;

namespace INPUT_CONST {
	enum { NEWACCOUNT = 1, DEPOSIT, WITHDRAW, PRINTALL, EXIT };
}

namespace ACC_TYPE_CONST {
	enum { NORMAL = 1, HIGHCREDIT };
}

class AccountHandler {
private:
	AccountArray accArr;
	int accNum;

protected: // ��ü ���ο����� ���̴ϱ� protected �ɱ�!
	void createNewNormalAccount();
	void createNewHighCreditAccount();

public:
	AccountHandler();

	int infoAndSelect();
	bool processSelection(int select);
	bool createNewAccount();
	void deposit();
	void withdraw();
	void printAll();

	virtual ~AccountHandler();
};

#endif