/************
<주소>		: p86
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <functional>
using namespace std;

class Plus {
public:
	int operator()(int a, int b) {
		return a + b;
	}
};

class Minus {
public:
	int operator()(int a, int b) {
		return a - b;
	}
};

int main(void) {
	Plus p;
	plus<int> std_p;

	cout << p(10, 20) << endl;
	cout << std_p(10, 20) << endl;

	Minus m;
	minus<int> std_m;

	cout << m(10, 20) << endl;
	cout << std_m(10, 20) << endl;

	return 0;
}