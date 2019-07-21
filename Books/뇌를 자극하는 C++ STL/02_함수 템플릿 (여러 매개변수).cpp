/************
<주소>		: p95
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

template <class T1, class T2>
void Print(T1 a, T2 b) {
	cout << a << ", " << b << endl;
}

int main(void) {
	Print(10, 10.1);
	Print(20, "World!");
	Print("Hello", 20.2);

	return 0;
}