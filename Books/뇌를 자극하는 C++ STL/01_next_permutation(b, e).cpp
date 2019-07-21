/************
<�ּ�>		: p376
**********
<�ذ���>	:

[b, e)������ ���ҵ�� ������ ����� (P)

���� ��� 10, 20, 30�� ������

10 20 30
10 30 20
20 10 30
20 30 10
30 10 20
30 20 10

�� ������ �����ε�, next_permutation ���� ���� �������� ������� ����ȴ�.
���� 30, 20, 10�� ��ȯ�ϴ� �������� false�� ��ȯ�Ѵ�. (�� �̻��� ������ ���� ����)

==> �� ��, ���� ������ ������ ��� �Ǿ��� 30, 20, 10�� �������� ������ false�� ��ȯ�ȴ�.

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T, typename Predicate>
void print(const vector<T, Predicate> &s) {
	for (vector<T, Predicate>::const_iterator iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << endl;
}

void print(vector<int>::iterator from, vector<int>::iterator to) {
	for (; from != to; from++) {
		cout << *from << ' ';
	}
	cout << endl;
}

template <typename T, typename Predicate>
void fill(vector<T, Predicate> &s, int same = 1, int init = 10, int add = 10) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j < same; j++) {
			s.push_back(init);
		}
		init += add;
	}
}

int main(void) {
	vector<int>v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	print(v);
	cout << next_permutation(v.begin(), v.end()) << endl;

	print(v);
	cout << next_permutation(v.begin(), v.end()) << endl;

	print(v);
	cout << next_permutation(v.begin(), v.end()) << endl;

	print(v);
	cout << next_permutation(v.begin(), v.end()) << endl;

	print(v);
	cout << next_permutation(v.begin(), v.end()) << endl;

	print(v);
	cout << next_permutation(v.begin(), v.end()) << endl;

	print(v);

	return 0;
}