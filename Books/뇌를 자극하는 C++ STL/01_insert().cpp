/************
<주소>		: p254
**********
<해결방안>	:

set은 중복된 원소를 허용하지 않음
insert의 반환값은 pair(삽입된 원소의 위치, 성공여부)

또한 반복자가 set을 순회하는 순서는 Inorder (LAR)

**********
<오답노트>	:

*/

#include <iostream>
#include <set>
using namespace std;

void printSet(const set<int> &s) {
	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;
}

int main(void) {
	set<int> s;

	s.insert(50);
	s.insert(20);
	s.insert(30);
	s.insert(10);
	s.insert(70);
	s.insert(40);
	s.insert(60);
	printSet(s);

	// 중복된 원소를 insert하면 삽입이 되지 않음!
	// 반환 값은 pair로 (삽입된 원소의 위치, 성공여부)
	s.insert(10);
	s.insert(10);
	printSet(s);

	return 0;
}