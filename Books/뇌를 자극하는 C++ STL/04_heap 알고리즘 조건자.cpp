/************
<�ּ�>		: p398
**********
<�ذ���>	:

[[ �� ]]
Ʈ�� ���� ��� ���Ұ� Parent�� Child���� ū(����)���� ���� ���� ���� Ʈ��

[[ ���� �迭�� ]]
Parent = (Child - 1) / 2
Left Child = Parent * 2 + 1
Right Child = Parent * 2 + 2

[[ ���� ���� ]]
�迭�� ������(last child)�� ���� ����
parent�� �񱳸� �ϸ� ���� ��Ģ�� ���� ������ swap

[[ ���� Pop ]]
root�� ��ȯ
�迭�� ������(last child)�� ���Ҹ� root�� �ű�
left child, right child�� ���ذ��� ���� ��Ģ�� ���� ������ �� �� ū(����) ���ҿ� swap

[[ make_heap �۵� ��� ]]
heap sort�� ����ϰ� �迭�� ù ���Һ��� �����Ͽ� �տ������� heap�� ������ heap�� ���� �߰�

ex) ---: ������� heap
1 2 3 4 5

1 2 3 4 5: 1�� heap�� ����
-

2 1 3 4 5: 2�� heap�� ����
---

3 1 2 4 5: 3�� heap�� ����
-----

4 3 2 1 5: 4�� heap�� ����
-------

5 4 2 1 3: 5�� heap�� ����
---------

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
	vector<int> v;

	fill(v);
	print(v);

	// ������ ����
	make_heap(v.begin(), v.end(), greater<int>());
	print(v);

	// ���� ���� �߰�
	v.push_back(60);
	push_heap(v.begin(), v.end(), greater<int>());
	print(v);

	// ���� ����
	sort_heap(v.begin(), v.end(), greater<int>());
	print(v);

	return 0;
}