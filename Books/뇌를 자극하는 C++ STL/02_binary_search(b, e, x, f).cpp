/************
<�ּ�>		: p410, p413
**********
<�ذ���>	:

f���·� ���ĵ� ���� [b, e)���� x�� ã�´�.

��� ���ĵ� ���� �˰��򿡴� ������ ������ �˰����� �����ȴ�.
���� default�� �ٸ� ������� ���ĵǾ��ٸ�, �̰��� �� ���ڷ� �Ѱ��־�� �Ѵ�.

���� ���, binary_search(b, e, x, f)�� �ִٸ�
[b, e)���� f�������� ���ĵ� ���ҵ��� �־�� �Ѵ�.
�� �� ==�� �Ǵ��ϴ� ���� equivalence ������� !f(a, b) && !f(b, a) �̸� ���� ���̴�.

 ==> f�� a == b�� �Ǵ��ϴ� ������ �ƴԿ� ����!!!
 ==> f�� a���� b�� �ڿ� �������� �Ǵ��ϴ� �Լ�!

O(logN)

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

	// f�� [b, e)�� ���� ����
	// ��, f�� a���� b�� �ڿ��ִ��� ���θ� ��ȯ�ϴ� �Լ� (true = ��, false = �ƴ�)
	if (binary_search(v.begin(), v.end(), 14, less<int>())) {
		cout << "14 ����!" << endl;
	} else {
		cout << "14 ����!" << endl;
	}

	return 0;
}