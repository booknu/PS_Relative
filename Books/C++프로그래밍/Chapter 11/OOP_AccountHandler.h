/************
<주소>		: p494 - OOP 프로젝트 8단계
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

protected: // 객체 내부에서만 쓰이니까 protected 걸기!
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