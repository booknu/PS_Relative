/************
<주소>		: p221
**********
<해결방안>	:

list의 insert(), erase()는 O(1)
또한 이것은 Node 기반 컨테이너들에서는 반복자가 무효화 되지 않는다.
(원소 자체가 제거되지 않는한)

하지만, Array 기반 컨테이너들에서는 반복자가 무효화 된다.
(그 동작 중 메모리가 재할당 되거나, 원소가 이동할 수 있기 때문)

**********
<오답노트>	:

*/

#include <iostream>
#include <list>
using namespace std;

void fillList(list<int> &ls) {
	for (int i = 1; i <= 5; i++) {
		ls.push_back((i + 1) * 10);
	}
}

void printList(const list<int> &ls) {
	// const list<int>를 순회하는 반복자이기 때문에 const_iterator을 사용!
	for (list<int>::const_iterator iter = ls.begin(); iter != ls.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;
}

int main(void) {
	list<int> ls;

	fillList(ls);
	printList(ls);

	// list의 iterator은 양방향 반복자이기 때문에 ++, --연산만 지원
	list<int>::iterator iter1 = ls.begin();
	iter1++;
	iter1++;

	// erase
	iter1 = ls.erase(iter1);
	printList(ls);

	// insert
	ls.insert(iter1, 5, -1);
	printList(ls);
	cout << *iter1 << endl; // list에서는 원소가 삭제되지 않는한 iterator가 무효화 되지 않는다!

	return 0;
}