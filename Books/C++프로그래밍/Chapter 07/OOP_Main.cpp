/************
<�ּ�>		: p314 - OOP ������Ʈ 5�ܰ�
**********
<�ذ���>	:

Main ������

**********
<�����Ʈ>	:

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