/************
<주소>		: p255
**********
<해결방안>	:

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

void fillSet(set<int> &s) {
	for (int i = 1; i <= 5; i++) {
		s.insert(i * 10);
	}
}

void printPair(const pair<set<int>::iterator, bool> p) {
	cout << *p.first << (p.second ? " 삽입 성공!" : " 삽입 실패...") << endl;
}

int main(void) {
	set<int> s;
	pair<set<int>::iterator, bool> ret;

	fillSet(s);
	printSet(s);

	ret = s.insert(60);
	printPair(ret);
	printSet(s);

	ret = s.insert(10);
	printPair(ret);
	printSet(s);

	return 0;
}