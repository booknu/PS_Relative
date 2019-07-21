/************
<�ּ�>		: p298
**********
<�ذ���>	:

ã�� ������ ���, ã�� ������ �� �ݺ��ڸ� ��ȯ
(end()�� �ƴ�!!)

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

	fill(v);
	print(v);

	vector<int>::iterator iter;
	vector<int>::iterator b = v.begin();
	vector<int>::iterator e = v.begin() + 2;
	iter = adjacent_find(b, e);

	cout << *iter << endl; // ã�� ���ϸ� end()�� �ƴ� ������ �� �ݺ���, �� e�� ��ȯ!

	// �´� ǥ�� (������ �� �ݺ��ڰ� ��ȯ�ƴ���)
	if (iter != e) {
		cout << "NOT FOUND (iter != e)" << endl;
	}

	// Ʋ�� ǥ�� (end�� �ƴ� ������ �� �ݺ��ڸ� Ȯ���ؾ�)
	if (iter != v.end()) {
		cout << "NOT FOUND (iter != v.end())" << endl;
	}

	return 0;
}