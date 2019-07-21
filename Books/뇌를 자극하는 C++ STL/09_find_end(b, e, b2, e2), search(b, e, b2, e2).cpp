/************
<�ּ�>		: p309
**********
<�ذ���>	:

������ [b, e) �ȿ��� [b2, e2)�� ��ġ�ϴ� ������ �� "������ ������"�� "ù ����"�� �ݺ��� ��ȯ

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
	vector<int> seq(10, 1);
	vector<int> target(3, 1);

	print(target);
	print(seq);
	
	// find_end: "������ ������"�� "ù ����" ��ȯ
	vector<int>::iterator iter = find_end(seq.begin(), seq.end(), target.begin(), target.end());
	print(iter, seq.end());

	// search: "ù ������"�� "ù ����" ��ȯ
	iter = search(seq.begin(), seq.end(), target.begin(), target.end());
	print(iter, seq.end());

	return 0;
}