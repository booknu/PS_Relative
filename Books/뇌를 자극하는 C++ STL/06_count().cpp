/************
<주소>		: p262
**********
<해결방안>	:

연관 컨테이너의 핵심은 "찾기" 멤버함수
이것들은 O(log n) 시간이 걸린다.

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

	cout << "원소 10의 개수: " << s.count(10) << endl;
	cout << "원소 60의 개수: " << s.count(60) << endl;

	return 0;
}