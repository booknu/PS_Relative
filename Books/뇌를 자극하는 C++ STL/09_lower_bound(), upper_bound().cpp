/************
<주소>		: p256
**********
<해결방안>	:

lower_bound()는 찾은 원소의 시작 반복자를 반환
upper_bound()는 찾은 원소의 다음 반복자를 반환
따라서 찾은 원소는 [lower_bound(), upper_bound()]에 존재한다.
그러므로 lower == upper인 경우는 찾는 원소가 존재하지 않는다.
==> 이 범위는 equal_range()로도 찾을 수 있다.

이것은 원소가 중복되는 multiset에서 유용하게 쓰인다.

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

	set<int>::iterator lo, up;
	lo = s.lower_bound(30);
	up = s.upper_bound(30);
	cout << *lo << endl;
	cout << *up << endl;

	lo = s.lower_bound(-1);
	up = s.upper_bound(-1);
	cout << *lo << endl;
	cout << *up << endl;
	if (lo == up) {
		cout << "-1 존재하지 않음" << endl;
	}

	return 0;
}