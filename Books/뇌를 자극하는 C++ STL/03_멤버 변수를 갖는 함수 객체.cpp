/************
<�ּ�>		: p79
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Adder {
private:
	int total; // ��� ������ ���� �� �ִ�!

public:
	explicit Adder(int n = 0): total(n) { }
	int operator()(int n) {
		return total += n;
	}
};

int main(void) {
	Adder add(0);

	cout << add(10) << endl;
	cout << add(20) << endl;
	cout << add(30) << endl;

	return 0;

	return 0;
}