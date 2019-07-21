/************
<�ּ�>		: p263
**********
<�ذ���>	:

find()�� �ش� ���Ҹ� ����Ű�� iterator�� ��ȯ�Ѵ�.
���� ������, ��ǥ���� end()�� �ش��ϴ� �ݺ��ڸ� ��ȯ�Ѵ�.

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
	set<int>::iterator iter;

	fillSet(s);
	printSet(s);

	iter = s.find(30);
	if (iter != s.end()) {
		cout << *iter << "�� ������!" << endl;
	} else {
		cout << "30�� �������� ����..." << endl;
	}

	iter = s.find(60);
	if (iter != s.end()) {
		cout << *iter << "�� ������!" << endl;
	} else {
		cout << "60�� �������� ����..." << endl;
	}

	return 0;
}