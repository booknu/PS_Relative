/************
<�ּ�>		: p256
**********
<�ذ���>	:

lower_bound()�� ã�� ������ ���� �ݺ��ڸ� ��ȯ
upper_bound()�� ã�� ������ ���� �ݺ��ڸ� ��ȯ
���� ã�� ���Ҵ� [lower_bound(), upper_bound()]�� �����Ѵ�.
�׷��Ƿ� lower == upper�� ���� ã�� ���Ұ� �������� �ʴ´�.
==> �� ������ equal_range()�ε� ã�� �� �ִ�.

�̰��� ���Ұ� �ߺ��Ǵ� multiset���� �����ϰ� ���δ�.

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

	set<int>::iterator lo, up;
	lo = s.lower_bound(30);
	up = s.upper_bound(30);
	cout << *lo << endl;
	cout << *up << endl;

	lo = s.lower_bound(-1);
	up = s.upper_bound(-1);
	cout << *lo << endl;
	cout << *up << endl;
	if (lo == up) {
		cout << "-1 �������� ����" << endl;
	}

	return 0;
}