/************
<�ּ�>		: p348
**********
<�ذ���>	:

���ĵ� �� ������ [b, e)�� [b2, e2)��
t�������� ���۵Ǵ� �������� �պ� �����Ѵ�.

�� ��, t�������� ���۵Ǵ� �������� ������ �����ϸ� ���� �߻�

��ȯ������ dest�� �� �ݺ��ڸ� ��ȯ�Ѵ�.
��, [t, returnIter)������ �պ������� �ϴ� ���̴�.

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
	vector<int> src1, src2, dest(10);
	fill(src1, 1, 0);
	fill(src2, 1, 5);
	print(src1);
	print(src2);

	vector<int>::iterator iter;
	iter = merge(src1.begin(), src1.end(), src2.begin(), src2.end(), dest.begin()); // �պ��� ������ �� �ݺ��ڸ� ��ȯ��
	print(dest.begin(), iter);

	return 0;
}