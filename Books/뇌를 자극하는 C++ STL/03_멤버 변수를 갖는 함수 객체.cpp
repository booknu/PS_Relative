/************
<주소>		: p79
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Adder {
private:
	int total; // 멤버 변수를 가질 수 있다!

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