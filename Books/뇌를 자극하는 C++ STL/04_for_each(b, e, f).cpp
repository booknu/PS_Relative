/************
<�ּ�>		: p341
**********
<�ذ���>	:

for_each�� �������� �� ���Ҹ� �����ϴ� �Ͽ��� ���� �� �ִ�.

�Լ����� �������� �� ���ҿ� �����ϴ� �˰�����
for_each, transform�� �ִµ�,

for_each�� ��� �Ű�����(out param)�� ����ϰ� (& ���۷���)
transform�� �Լ��� ��ȯ���� ����Ѵ�.

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

struct Pred {
	void operator()(int &n) {
		n *= n;
	}
};

int main(void) {
	vector<int> v;

	fill(v);
	print(v);

	for_each(v.begin(), v.end(), Pred());
	print(v);

	return 0;
}