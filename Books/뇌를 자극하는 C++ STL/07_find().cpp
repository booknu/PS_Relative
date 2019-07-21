/************
<주소>		: p263
**********
<해결방안>	:

find()는 해당 원소를 가리키는 iterator을 반환한다.
만약 없을시, 끝표시인 end()에 해당하는 반복자를 반환한다.

**********
<오답노트>	:

*/

#include <iostream>
#include <set>
using namespace std;

template <typename T, typename Predicate>
void printSet(const set<T, Predicate> &s) {
	for (set<T, Predicate>::iterator iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;
}

template <typename T, typename Predicate>
void fillSet(set<T, Predicate> &s) {
	for (int i = 1; i <= 5; i++) {
		s.insert(i * 10);
	}
}

int main(void) {
	set<int> s;
	set<int>::iterator iter;

	fillSet(s);
	printSet(s);

	iter = s.find(30);
	if (iter != s.end()) {
		cout << *iter << "이 존재함!" << endl;
	} else {
		cout << "30이 존재하지 않음..." << endl;
	}

	iter = s.find(60);
	if (iter != s.end()) {
		cout << *iter << "이 존재함!" << endl;
	} else {
		cout << "60이 존재하지 않음..." << endl;
	}

	return 0;
}