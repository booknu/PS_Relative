/************
<주소>		: p272
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <set>
using namespace std;

template <typename T, typename Predicate>
void printSet(const multiset<T, Predicate> &s) {
	for (multiset<T, Predicate>::iterator iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;
}

void printSet(multiset<int>::iterator from, multiset<int>::iterator to) {
	for (; from != to; from++) {
		cout << *from << ' ';
	}
	cout << endl;
}

template <typename T, typename Predicate>
void fillSet(multiset<T, Predicate> &s) {
	for (int i = 1; i <= 5; i++) {
		s.insert(i * 10);
		s.insert(i * 10);
	}
}

int main(void) {
	multiset<int> s;

	fillSet(s);
	printSet(s);

	// count
	cout << "10원소의 개수: " << s.count(10) << endl;

	// find
	multiset<int>::iterator iter = s.find(30);
	cout << "30 찾기: ";
	printSet(iter, s.end());

	// lower_bound, upper_bound
	multiset<int>::iterator lo, up;
	lo = s.lower_bound(30);
	up = s.upper_bound(30);
	cout << "30 찾기 [lo, up): ";
	printSet(lo, up);

	return 0;
}