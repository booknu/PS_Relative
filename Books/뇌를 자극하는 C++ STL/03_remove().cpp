/************
<주소>		: p226
**********
<해결방안>	:

remove(n)은 n에 해당하는 원소를 모두 지운다.

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
	list<int> lt;

	fillList(lt);
	lt.push_back(20);
	lt.push_back(20);
	printList(lt);

	lt.remove(20);
	printList(lt);

	return 0;
}