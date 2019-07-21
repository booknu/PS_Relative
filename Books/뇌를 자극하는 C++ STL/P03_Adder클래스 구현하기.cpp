/************
<주소>		: p87 - 문제 3
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

template <typename T>
class Adder {
public:
	T operator()(T a, T b) {
		return a + b;
	}
};

int main(void) {
	Adder<int> add;

	int sum = add(10, 20);
	cout << sum << endl;

	return 0;
}