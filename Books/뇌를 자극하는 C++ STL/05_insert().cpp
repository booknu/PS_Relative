/************
<주소>		: p214
**********
<해결방안>	:

vector의 insert는 무조건 나머지 원소를 뒤로 미는데,
deque의 insert는 원소가 더 적은 쪽으로 밀기 때문에 조금 더 효율적임

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
	printDQ(dq);

	dq.insert(dq.begin() + 2, 5, -1);
	printDQ(dq);

	return 0;
}