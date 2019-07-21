/************
<주소>		: p141
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <deque>
using namespace std;

int main(void) {
	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);
	dq.push_back(50);
	
	deque<int>::iterator iter = dq.begin();
	cout << iter[0] << endl;
	cout << iter[1] << endl;
	cout << iter[2] << endl;
	cout << endl;

	iter += 2;
	cout << *iter << endl;
	cout << endl;

	deque<int>::iterator iter2 = iter + 2;
	cout << *iter2 << endl;

	return 0;
}