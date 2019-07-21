/************
<�ּ�>		: p336
**********
<�ذ���>	:

copy(b, e, b2)���� 2���� ��尡 �ִ�.

�⺻�� �����(Overwrite) ����̰�,
�ݺ��� �����(insert_iterator)���� ����ϸ� ����(Insert)��嵵 �����ϴ�.

Overwrite�� �� ���� dest�� ���Ұ� src���� ���ƾ� �Ѵ�.

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
#include <algorithm>
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
void fill(vector<T, Predicate> &s, int same = 1, int add = 0) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j < same; j++) {
			s.push_back(i * 10 + add);
		}
	}
}

int main(void) {
	vector<int> src, dest(5);

	fill(src);
	print(src);

	copy(src.begin(), src.end(), dest.begin());
	print(dest);

	return 0;
}