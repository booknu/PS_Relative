/************
<�ּ�>		: p389
**********
<�ذ���>	:

[b, e)�� �������� m - b��ŭ ȸ���� ���� [t, p)�� �����Ѵ�. (p�� ��ȯ)
��, b...m...e �� �ִٸ�,
m........�� �ȴ�.
m�� b�� �ڸ��� �������� �̵��ϴ� ���̴�.

==> �������� ȸ���ϴ� �Ϳ� ����!!!

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

	rotate_copy(v.begin(), v.begin() + 2, v.end(), dest.begin()); // �������� ȸ���ϴ� ���ӿ� ����!
	print(v);
	print(dest);

	return 0;
}