/************
<주소>		: p376
**********
<해결방안>	:

[b, e)구간의 원소들로 순열을 만든다 (P)

예를 들어 10, 20, 30이 있으면

10 20 30
10 30 20
20 10 30
20 30 10
30 10 20
30 20 10

이 가능한 순열인데, next_permutation 같은 경우는 정방향의 순서대로 진행된다.
만약 30, 20, 10을 반환하는 순간에는 false를 반환한다. (더 이상의 순열이 없기 때문)

==> 이 때, 원래 원소의 순서가 어떻게 되었든 30, 20, 10인 순간에는 무조건 false가 반환된다.

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
	vector<int>v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	print(v);
	cout << next_permutation(v.begin(), v.end()) << endl;

	print(v);
	cout << next_permutation(v.begin(), v.end()) << endl;

	print(v);
	cout << next_permutation(v.begin(), v.end()) << endl;

	print(v);
	cout << next_permutation(v.begin(), v.end()) << endl;

	print(v);
	cout << next_permutation(v.begin(), v.end()) << endl;

	print(v);
	cout << next_permutation(v.begin(), v.end()) << endl;

	print(v);

	return 0;
}