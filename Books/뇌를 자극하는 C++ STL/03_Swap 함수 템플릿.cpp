/************
<주소>		: p97
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

template <typename T>
void Swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	int n1 = 1, n2 = 2;
	Swap(n1, n2);
	cout << n1 << ", " << n2 << endl;

	double d1 = 1.1, d2 = 2.2;
	Swap(d1, d2);
	cout << d1 << ", " << d2 << endl;

	return 0;
}