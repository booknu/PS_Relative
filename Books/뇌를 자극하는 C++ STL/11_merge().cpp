/************
<주소>		: p239
**********
<해결방안>	:

두 list를 하나의 정렬된 list로 합병한다.
두 list는 같은 조건으로 정렬되어 있어야 한다. (아니면 오류남)

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

void print(const list<int> &list1, const list<int> &list2) {
	cout << "list1: ";
	printList(list1);
	cout << "list2: ";
	printList(list2);
}

int main(void) {
	list<int> list1;
	list<int> list2;

	list1.push_back(10);
	list1.push_back(20);
	list1.push_back(30);
	list1.push_back(40);
	list1.push_back(50);

	list2.push_back(25);
	list2.push_back(45);
	list2.push_back(55);

	print(list1, list2);
	cout << "===========" << endl;
	
	list1.merge(list2);
	print(list1, list2);
 
	return 0;
}