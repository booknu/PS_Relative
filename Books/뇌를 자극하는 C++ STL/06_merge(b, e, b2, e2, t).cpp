/************
<주소>		: p419
**********
<해결방안>	:

[b, e) [b2, e2)를 합병 정렬하여 [t, p)에 저장한다.
p를 반환한다.

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
	vector<int> v1, v2, v3(10);

	fill(v1);
	fill(v2, 1, 5);
	print(v1);
	print(v2);

	vector<int>::iterator end = merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	print(v3.begin(), end);

	return 0;
}