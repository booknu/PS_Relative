/************
<�ּ�>		: p553 - OOP ������Ʈ 10�ܰ�
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
#include "OOP_Array.h"

const int NAME_LEN = 100;

namespace INPUT_CONST {
	enum { NEWACCOUNT = 1, DEPOSIT, WITHDRAW, PRINTALL, EXIT };
}

namespace ACC_TYPE_CONST {
	enum { NORMAL = 1, HIGHCREDIT };
}

class AccountHandler {
private:
	Array<Account> accArr;
	int accNum;

protected:
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