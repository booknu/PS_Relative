/************
<주소>		: p284
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <map>
using namespace std;

template <typename T1, typename T2, typename Predicate>
void printMap(const map<T1, T2, Predicate> &s) {
	for (map<T1, T2, Predicate>::const_iterator iter = s.begin(); iter != s.end(); iter++) {
		//cout << "(" << (*iter).first << ", " << (*iter).second << ") "; // 이것도 가능!
		cout << "(" << iter->first << ", " << iter->second << ") ";
	}
	cout << endl;
}

void printMap(map<int, int>::iterator from, map<int, int>::iterator to) {
	for (; from != to; from++) {
		//cout << "(" << (*iter).first << ", " << (*iter).second << ") "; // 이것도 가능!
		cout << "(" << from->first << ", " << from->second << ") ";
	}
	cout << endl;
}

template <typename T1, typename T2, typename Predicate>
void fillMap(map<T1, T2, Predicate> &s) {
	for (int i = 1; i <= 5; i++) {
		s.insert(make_pair(i, i * 100));
	}
}

int main(void) {
	map<int, int> m;

	fillMap(m);
	printMap(m);

	// find
	map<int, int>::iterator iter = m.find(3);
	printMap(iter, m.end());

	// lower_bound, upper_bound
	map<int, int>::iterator lo, up;
	lo = m.lower_bound(3);
	up = m.upper_bound(3);
	printMap(lo, up);

	// equal_range
	pair<map<int, int>::iterator, map<int, int>::iterator> range = m.equal_range(4);
	printMap(range.first, range.second);

	return 0;
}