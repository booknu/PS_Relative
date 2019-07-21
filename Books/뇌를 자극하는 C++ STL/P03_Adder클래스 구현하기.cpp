/************
<�ּ�>		: p87 - ���� 3
**********
<�ذ���>	:

**********
<�����Ʈ>	:

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