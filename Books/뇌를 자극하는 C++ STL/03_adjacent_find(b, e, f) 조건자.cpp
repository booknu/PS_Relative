/************
<주소>		: p300
**********
<해결방안>	:

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
void fill(vector<T, Predicate> &s, int fill = 1) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j < fill; j++) {
			s.push_back(i * 10);
		}
	}
}

int main(void) {
	vector<int> v;

	v.push_back(20);
	v.push_back(20);
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	print(v);

	vector<int>::iterator iter = adjacent_find(v.begin(), v.end(), less<int>()); // a < b인 첫 원소를 찾음
	print(iter, v.end());

	return 0;
}