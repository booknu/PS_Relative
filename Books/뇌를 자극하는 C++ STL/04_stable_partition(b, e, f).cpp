/************
<�ּ�>		: p381
**********
<�ذ���>	:

[b, e)�� ���ҵ��� f�� �������� true�� ���Ҵ� [b, p)��, false�� ���Ҵ� [p, e)�� �����Ѵ�.
��ȯ���� p�̴�.

������� ������ ����������, partition���ٴ� ������ ��������.

partition�� QuickSort�� ����� ���������,
stable_partition�� ��ȯ�� ���Ҹ� ����Ű�� �� �ݺ��ڰ� �� �� ���ʿ��� �����ؼ� ã�´�.
(���� buffer�� ����Ͽ� ����)

O(N), ������ ���� O(N*logN)

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

bool Pred(int n) {
	return n > 20;
}

int main(void) {
	vector<int> v;

	fill(v);
	print(v);

	vector<int>::iterator p = stable_partition(v.begin(), v.end(), Pred); // ������ ������
	print(v.begin(), p);
	print(p, v.end());
	print(v);

	return 0;
}