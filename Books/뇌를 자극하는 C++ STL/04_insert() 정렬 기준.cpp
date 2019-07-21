/************
<주소>		: p258
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <set>
#include <functional>
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
	set<int, greater<int>> s; // 정렬 기준이 greater인 set

	fillSet(s);
	printSet(s);

	return 0;
}