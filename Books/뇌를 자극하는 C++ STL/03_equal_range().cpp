/************
<주소>		: p274
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

	pair<multiset<int>::iterator, multiset<int>::iterator> range = s.equal_range(30);
	printSet(range.first, range.second);

	return 0;
}