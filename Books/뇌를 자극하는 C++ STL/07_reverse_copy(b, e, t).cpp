/************
<�ּ�>		: p386
**********
<�ذ���>	:

[b, e)�� ���ҵ��� ������ [t, p)�� ����
p�� ��ȯ

Overwrite ������� �����ϹǷ� dest�� [b, e)�� ���� ���� �̻��� ������ �־�� ��

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
	vector<int> v, dest(5);

	fill(v);
	print(v);

	reverse_copy(v.begin(), v.end(), dest.begin());
	print(v);
	print(dest);

	return 0;
}