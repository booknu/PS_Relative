/************
<�ּ�>		: p214
**********
<�ذ���>	:

vector�� insert�� ������ ������ ���Ҹ� �ڷ� �̴µ�,
deque�� insert�� ���Ұ� �� ���� ������ �б� ������ ���� �� ȿ������

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <deque>
using namespace std;

void printDQ(const deque<int> &dq) {
	for (deque<int>::size_type i = 0; i < dq.size(); i++) {
		cout << dq[i] << ' ';
	}
	cout << endl;
}

void fillDQ(deque<int> &dq) {
	for (int i = 0; i < 5; i++) {
		dq.push_back((i + 1) * 10);
	}
}

int main(void) {
	deque<int> dq;

	fillDQ(dq);
	printDQ(dq);

	dq.insert(dq.begin() + 2, 5, -1);
	printDQ(dq);

	return 0;
}