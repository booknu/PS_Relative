/************
<�ּ�>		: p338
**********
<�ذ���>	:

[b, e) ������ ���ҵ���
[b2-(e-b), b2)�� �����Ѵ�

������, �Ųٷ� �������� ����Ǵ°� �ƴϰ�, b2�� ������ ������ ���� ä��ٴ� �ǹ̿��� backward�̴�.
���� �Ųٷ� �������� ���簡 �ƴٸ� reverse�������̴�.

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
	vector<int> v1, v2(10);

	fill(v1);
	print(v1);

	copy_backward(v1.begin(), v1.end(), v2.end());
	print(v2);

	return 0;
}