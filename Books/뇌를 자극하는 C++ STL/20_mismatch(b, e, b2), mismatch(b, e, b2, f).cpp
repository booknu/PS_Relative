/************
<�ּ�>		: p327
**********
<�ذ���>	:

�� �������� ���Ͽ� ������ ���� ���� �ٸ� ��ġ�� ã��
pair<iter, iter>�� ��ȯ

���� �� ���ڿ��� ���̰� ������ �������� �� �ݺ��ڸ� ��ȯ

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
	vector<int> v1, v2;
	fill(v1, 1);
	fill(v2, 1);

	pair<vector<int>::iterator, vector<int>::iterator> res;

	// ���� ������  �� �ݺ��� ���� ��ȯ
	res = mismatch(v1.begin(), v1.end() - 1, v2.begin());
	cout << "test 1" << endl;
	print(v1);
	print(v2);
	cout << *res.first << ", " << *res.second << endl;

	// ��
	v2.pop_back();
	v2.push_back(-1);

	res = mismatch(v1.begin(), v1.end(), v2.begin());
	cout << "test 2" << endl;
	print(v1);
	print(v2);
	cout << *res.first << ", " << *res.second << endl;

	// b ~ e ���̰� �� ���? ���� �߻�
	/*v1.push_back(-1);

	cout << "test 2" << endl;
	print(v1);
	print(v2);
	res = mismatch(v1.begin(), v1.end(), v2.begin());
	cout << *res.first << ", " << *res.second << endl;*/

	return 0;
}