/************
<�ּ�>		: p431
**********
<�ذ���>	:

������ [b, e) [b2, b2+e-b)�� f2������ f1������ ���Ѵ�.

������ Sum of Product�̹Ƿ� 
Product ������ Sum �̶�� ��
���� �Լ� ���� ������ f1 of f2
f2 ������ f1 �̶�� ��

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
#include <numeric> // ��ġ �˰���
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

int f1(int a, int b) {
	return a + b;
}

int f2(int a, int b) {
	return a * b;
}

int main(void) {
	vector<int> v1, v2;

	fill(v1, 1, 1, 2);
	fill(v2, 1, 10, 10);
	print(v1);
	print(v2);

	cout << inner_product(v1.begin(), v1.end(), v2.begin(), 0, f1, f2) << endl;
	cout << inner_product(v1.begin(), v1.end(), v2.begin(), 1, f2, f1) << endl;

	return 0;
}