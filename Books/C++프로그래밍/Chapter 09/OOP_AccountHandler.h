/************
<주소>		: p390 - OOP 프로젝트 7단계
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
#include "OOP_Account.h"

const int NAME_LEN = 100; // 이건 배열 생성할 때 쓰이므로 객체 내부의 const 로 선언되면 안 됨! (배열 개수는 compile time에 결정되야 하기 때문)

namespace INPUT_CONST {
	enum { NEWACCOUNT = 1, DEPOSIT, WITHDRAW, PRINTALL, EXIT };
}

namespace ACC_TYPE_CONST {
	enum { NORMAL = 1, HIGHCREDIT };
}

class AccountHandler {
private:
	Account *accArr[1000];
	int accNum;

protected: // 객체 내부에서만 쓰이니까 protected 걸기!
	void createNewNormalAccount(); // 추가
	void createNewHighCreditAccount(); // 추가

public:
	AccountHandler();

	int infoAndSelect();
	bool processSelection(int select);
	bool createNewAccount(); // 변경
	void deposit();
	void withdraw();
	void printAll();

	virtual ~AccountHandler();
};

#endif