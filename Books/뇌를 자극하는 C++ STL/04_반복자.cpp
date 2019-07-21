/************
<주소>		: p213
**********
<해결방안>	:

deque는 Random Access Iterator

+, -, +=, -=, [] 연산도 가능

**********
<오답노트>	:

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

	deque<int>::iterator iter;
	for (iter = dq.begin(); iter != dq.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;

	iter = dq.begin() + 2;
	cout << *iter << endl;

	return 0;
}