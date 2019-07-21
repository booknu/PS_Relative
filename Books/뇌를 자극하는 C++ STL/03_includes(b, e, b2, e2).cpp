/************
<주소>		: p414
**********
<해결방안>	:

[b2, e2) ⊂ [b, e)인지 판단한다. 

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
	vector<int> v1, v2, v3;

	fill(v1, 2);
	fill(v2);
	fill(v3, 2, 5);

	print(v1);
	print(v2);
	print(v3);
	cout << "======" << endl;

	cout << (includes(v1.begin(), v1.end(), v2.begin(), v2.end()) ? "v1이 v2를 포함" : "v1이 v2를 불포함") << endl;
	cout << (includes(v1.begin(), v1.end(), v3.begin(), v3.end()) ? "v1이 v3를 포함" : "v1이 v3를 불포함") << endl;

	v2.push_back(55);
	cout << (includes(v1.begin(), v1.end(), v2.begin(), v2.end()) ? "v1이 v2를 포함" : "v1이 v2를 불포함") << endl;

	return 0;
}