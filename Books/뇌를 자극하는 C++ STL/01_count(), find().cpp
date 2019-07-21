/************
<주소>		: p288
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <map>
using namespace std;

template <typename T1, typename T2, typename Predicate>
void printMap(const multimap<T1, T2, Predicate> &s) {
	for (multimap<T1, T2, Predicate>::const_iterator iter = s.begin(); iter != s.end(); iter++) {
		//cout << "(" << (*iter).first << ", " << (*iter).second << ") "; // 이것도 가능!
		cout << "(" << iter->first << ", " << iter->second << ") ";
	}
	cout << endl;
}

void printMap(multimap<int, int>::iterator from, multimap<int, int>::iterator to) {
	for (; from != to; from++) {
		//cout << "(" << (*iter).first << ", " << (*iter).second << ") "; // 이것도 가능!
		cout << "(" << from->first << ", " << from->second << ") ";
	}
	cout << endl;
}

template <typename T1, typename T2, typename Predicate>
void fillMap(multimap<T1, T2, Predicate> &s) {
	for (int i = 1; i <= 5; i++) {
		s.insert(make_pair(i, i * 100));
		s.insert(make_pair(i, -i * 100));
	}
}

int main(void) {
	multimap<int, int> m;
	
	fillMap(m);
	printMap(m);

	cout << m.count(3) << endl;
	
	multimap<int, int>::iterator iter = m.find(3);
	printMap(iter, m.end());

	return 0;
}