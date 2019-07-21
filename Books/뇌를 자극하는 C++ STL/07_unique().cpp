/************
<주소>		: p233
**********
<해결방안>	:

list의 인접한 원소가 같으면, 원소를 하나만 남기고 나머지는 지운다.
인접한 원소에만 적용될 뿐, 전체적으로 같은 원소가 있을 수도 있음에 주의해야 한다.

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

	lt.push_back(10);
	lt.push_back(10);
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(20);
	lt.push_back(10);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(40);
	lt.push_back(30);
	printList(lt);

	lt.unique();
	printList(lt);

	return 0;
}