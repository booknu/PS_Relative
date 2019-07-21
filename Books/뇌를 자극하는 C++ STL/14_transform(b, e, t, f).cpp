/************
<�ּ�>		: p358
**********
<�ذ���>	:

for_each�� transform�� ���� ���ҿ� � ����� ���Ͽ� ������ ���� �ٲ۴ٴ� ���� ������,
transform�� ���� ���������� ������ ��ġ�� �ʰ� �������� �������� ����ȴٴ� ���� �ٸ���.

���� transform�� �Լ����� ��ȯ���� ���� ���Ұ� �ٲ��.

��ȯ���� ������ �������� �� �ݺ����̴�.

���� Overwrite ������� ����ȴ�.

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
void fill(vector<T, Predicate> &s, int same = 1, int add = 0) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j < same; j++) {
			s.push_back(i * 10 + add);
		}
	}
}

struct Pred {
	int operator()(int n) {
		return -n;
	}
};

int main(void) {
	vector<int> src, dest(5);
	
	fill(src);
	print(src);

	// �ٸ� vector�� �������� ����
	transform(src.begin(), src.end(), dest.begin(), Pred());
	print(src);
	print(dest);

	// ���� vector�� �������� ����
	transform(src.begin(), src.end(), src.begin(), Pred());
	print(src);

	return 0;
}