/************
<주소>		: p553 - OOP 프로젝트 10단계
**********
<해결방안>	:

Handler 클래스
Handler 클래스란 프로그램 전체의 기능을 담당 (기능적 성격)
프로그램 전체 기능, 흐름을 파악할 수 있다.

**********
<오답노트>	:

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