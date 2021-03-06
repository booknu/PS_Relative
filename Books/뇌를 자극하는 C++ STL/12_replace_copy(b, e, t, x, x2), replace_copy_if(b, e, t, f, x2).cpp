/************
<주소>		: p354
**********
<해결방안>	:

구간 [b, e)에서 조건에 맞는 원소의 값을 x2로 바꾸어 [t, t+(e-b))로 복사한다.

**********
<오답노트>	:

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
	bool operator()(int n) {
		return n >= 30 && n <= 40;
	}
};

int main(void) {
	vector<int> v, dest(15);

	fill(v, 3);
	print(v);

	replace_copy(v.begin() + 3, v.end() - 3, dest.begin(), 30, -1);
	print(v);
	print(dest);

	replace_copy_if(v.begin(), v.end(), dest.begin(), Pred(), -1);
	print(v);
	print(dest);

	return 0;
}