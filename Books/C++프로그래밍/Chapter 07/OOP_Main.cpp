/************
<주소>		: p314 - OOP 프로젝트 5단계
**********
<해결방안>	:

Main 구현부

**********
<오답노트>	:

*/

#include <iostream>
#include "OOP_AccountHandler.h"
#include "OOP_Account.h"

using namespace std;

int main(void) {
	AccountHandler handler;

	while (true) {
		int select = handler.infoAndSelect();
		if (select == INPUT_CONST::EXIT) {
			break;
		}
		handler.processSelection(select);
	}
}