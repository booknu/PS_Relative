/************
<주소>		: p211
**********
<해결방안>	:

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

int main(void) {
	deque<int> dq(5, -1);

	dq.push_front(12345);

	printDQ(dq);

	return 0;
}