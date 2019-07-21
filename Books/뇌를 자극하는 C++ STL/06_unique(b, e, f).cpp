/************
<�ּ�>		: p373
**********
<�ذ���>	:

[b, e)�� ���ҵ� �� ������ �ߺ� ���Ұ� ���� �ʰ� �����.
���� ����� ���� Overwrite�̴�. (size ��ȭx) (size���� ���̰� ������ erase ���� ���)
���� ���� ���� ������ ���ҵ鸸 ����� ������ ���� �� ����ϸ� �ȴ�.

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

class Pred {
public:
	bool operator()(int l, int r) {
		return abs(l - r) <= 5;
	}
};

int main(void) {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(25);
	v.push_back(35);
	v.push_back(40);
	v.push_back(45);
	v.push_back(50);
	print(v);

	vector<int>::iterator ret = unique(v.begin(), v.end(), Pred());
	cout << "size = " << v.size() << endl;

	// ���� size�� �ٲ��� ����!
	print(v);
	print(v.begin(), ret);

	// size���� ���̰� ������ erase
	ret = v.erase(ret, v.end());
	print(v);

	return 0;
}