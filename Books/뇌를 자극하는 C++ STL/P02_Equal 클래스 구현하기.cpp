/************
<주소>		: p87 - 문제 2
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Equal {
public:
	bool operator()(int a, int b) {
		return a == b;
	}
};

int main(void) {
	Equal cmp;

	cout << (cmp(10, 20) ? "같다" : "다르다") << endl;

	return 0;
}