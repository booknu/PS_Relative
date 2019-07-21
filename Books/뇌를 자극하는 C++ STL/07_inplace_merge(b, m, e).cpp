/************
<주소>		: p421
**********
<해결방안>	:

하나의 순차열에 두 개로 나누어진 정렬된 순차열이 있을 때, 이 둘을 merge한다.
[b, m) [m, e)를 merge하여 하나의 정렬된 [b, e)로 만든다

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
	fill(v, 1, 5);
	print(v);

	inplace_merge(v.begin(), v.begin() + 5, v.end());
	print(v);

	return 0;
}