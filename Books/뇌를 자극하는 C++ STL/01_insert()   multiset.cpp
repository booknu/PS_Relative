/************
<�ּ�>		: p271
**********
<�ذ���>	:

multiset�� insert�� �����ϴ� ���� ���� ������ pair<iter, bool>�� ��ȯ�ϴ� ���
iter���� ��ȯ�Ѵ�.

**********
<�����Ʈ>	:

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

template <typename T, typename Predicate>
void fillSet(multiset<T, Predicate> &s) {
	for (int i = 1; i <= 5; i++) {
		s.insert(i * 10);
		s.insert(i * 10);
	}
}

int main(void) {
	multiset<int> s;
	multiset<int>::iterator iter;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(80); // �ߺ�
	s.insert(30); // �ߺ�
	s.insert(70);
	iter = s.insert(30);

	printSet(s);
	cout << *iter << endl;

	return 0;
}