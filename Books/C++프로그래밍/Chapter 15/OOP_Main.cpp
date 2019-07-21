/************
<주소>		: p618 - OOP 프로젝트 11단계
**********
<해결방안>	:

Main 구현부

**********
<오답노트>	:

*/

#include <iostream>
#include <crtdbg.h>
#include "OOP_AccountHandler.h"
#include "OOP_Account.h"

using namespace std;

class Main {
public:
	static int main(void) {
		AccountHandler *handler = new AccountHandler();

		while (true) {
			int select = handler->infoAndSelect();
			if (select == INPUT_CONST::EXIT) {
				break;
			}
			handler->processSelection(select);
		}

		delete handler; // 만약 handler가 포인터형이 아니여서 여기서 delete가 안 됐다면,
						// 메모리 누수 체크에서 누수되는 걸로 나올 수도 있음
		return 0;
	}
};

