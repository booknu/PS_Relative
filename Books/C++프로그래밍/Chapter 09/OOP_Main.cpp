/************
<�ּ�>		: p390 - OOP ������Ʈ 7�ܰ�
**********
<�ذ���>	:

Main ������

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <crtdbg.h>
#include "OOP_AccountHandler.h"
#include "OOP_Account.h"

using namespace std;

int main(void) {
	AccountHandler *handler = new AccountHandler();

	while (true) {
		int select = handler->infoAndSelect();
		if (select == INPUT_CONST::EXIT) {
			break;
		}
		handler->processSelection(select);
	}

	delete handler; // ���� handler�� ���������� �ƴϿ��� ���⼭ delete�� �� �ƴٸ�,
					// �޸� ���� üũ���� �����Ǵ� �ɷ� ���� ���� ����

	_CrtDumpMemoryLeaks(); // �޸� ���� üũ
}