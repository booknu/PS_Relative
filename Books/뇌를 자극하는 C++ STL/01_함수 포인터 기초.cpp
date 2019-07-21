/************
<주소>		: p60
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

void Print(int n) {
	cout << "정수: " << n << endl;
}

int main(void) {
	void(*pf)(int) = Print; // 함수 포인터

	// test
	Print(1);
	pf(10);
	(*pf)(11);
}