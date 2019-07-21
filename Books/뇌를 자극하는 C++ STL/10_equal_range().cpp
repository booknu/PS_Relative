/************
<주소>		: p267
**********
<해결방안>	:

[lower, upper) 구간을 찾아 pair 형태로 반환한다.

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

	fillSet(s);
	printSet(s);

	pair<set<int>::iterator, set<int>::iterator> range = s.equal_range(30);
	cout << *range.first << endl;
	cout << *range.second << endl;

	range = s.equal_range(-1);
	cout << *range.first << endl;
	cout << *range.second << endl;
	if (range.first == range.second) {
		cout << "-1 존재하지 않음" << endl;
	}

	return 0;
}