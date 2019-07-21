/************
<주소>		: p304
**********
<해결방안>	:

**********
<오답노트>	:

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
void fill(vector<T, Predicate> &s, int fill = 1) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j < fill; j++) {
			s.push_back(i * 10);
		}
	}
}

int main(void) {
	vector<int> v1, v2;

	fill(v1, 1);
	fill(v2, 1);
	v2.push_back(-1);
	v2.push_back(-1);
	print(v1);
	print(v2);

	vector<int>::iterator b, e, b2;
	b = v1.begin();
	e = v1.end();
	b2 = v2.begin();

	// [b, e) [b2, b2+(e-b)) 구간 비교
	if (equal(b, e, b2)) {
		cout << "같음" << endl;
	}

	return 0;
}