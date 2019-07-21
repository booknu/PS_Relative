/************
<주소>		: p301
**********
<해결방안>	:

구간에서 x의 개수를 셈

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
	vector<int> v;

	fill(v, 3);
	print(v);

	cout << count(v.begin(), v.end(), 30) << endl;

	return 0;
}