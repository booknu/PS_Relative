/************
<�ּ�>		: p296
**********
<�ذ���>	:

adjacent_find(b, e)

[b, e) ���� �� *p = *(p + 1)�� ù ���Ҹ� ����Ű�� �ݺ��� ��ȯ
���ٸ�, ã�� ������ �� �ݺ��� ��ȯ

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
void fill(vector<T, Predicate> &s, int fill = 1) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j < fill; j++) {
			s.push_back(i * 10);
		}
	}
}

int main(void) {
	vector<int> v;

	fill(v, 2);
	print(v);

	vector<int>::iterator iter = adjacent_find(v.begin(), v.end()); // ���� �� ã���� "ã�� ����"�� �� �ݺ��� ��ȯ

	print(iter, v.end());

	return 0;
}