/************
<�ּ�>		: p262
**********
<�ذ���>	:

���� �����̳��� �ٽ��� "ã��" ����Լ�
�̰͵��� O(log n) �ð��� �ɸ���.

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

	cout << "���� 10�� ����: " << s.count(10) << endl;
	cout << "���� 60�� ����: " << s.count(60) << endl;

	return 0;
}