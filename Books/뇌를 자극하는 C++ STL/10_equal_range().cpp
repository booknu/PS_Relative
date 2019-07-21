/************
<�ּ�>		: p267
**********
<�ذ���>	:

[lower, upper) ������ ã�� pair ���·� ��ȯ�Ѵ�.

**********
<�����Ʈ>	:

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
		cout << "-1 �������� ����" << endl;
	}

	return 0;
}