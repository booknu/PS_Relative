/************
<주소>		: p237
**********
<해결방안>	:

시퀀스 컨테이너는 모두 sort를 지원한다.
vector, deque는 알고리즘의 qsort()를 이용하여 가능하지만,
list는 random access가 불가능하기 때문에 안 된다.
따라서 list는 자체적으로 sort() 멤버함수를 제공한다.

**********
<오답노트>	:

*/

#include <iostream>
#include <list>
using namespace std;

void printList(const list<int> &ls) {
	// const list<int>를 순회하는 반복자이기 때문에 const_iterator을 사용!
	for (list<int>::const_iterator iter = ls.begin(); iter != ls.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;
}

int main(void) {
	list<int> lt;

	lt.push_back(20);
	lt.push_back(40);
	lt.push_back(50);
	lt.push_back(10);
	lt.push_back(30);
	lt.push_back(60);
	printList(lt);

	lt.sort();
	printList(lt);

	return 0;
}