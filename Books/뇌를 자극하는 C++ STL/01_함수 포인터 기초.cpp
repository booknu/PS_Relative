/************
<�ּ�>		: p60
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

void Print(int n) {
	cout << "����: " << n << endl;
}

int main(void) {
	void(*pf)(int) = Print; // �Լ� ������

	// test
	Print(1);
	pf(10);
	(*pf)(11);
}