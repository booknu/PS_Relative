/************
<주소>		: p296
**********
<해결방안>	:

adjacent_find(b, e)

[b, e) 구간 중 *p = *(p + 1)인 첫 원소를 가리키는 반복자 반환
없다면, 찾는 구간의 끝 반복자 반환

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

	fill(v, 2);
	print(v);

	vector<int>::iterator iter = adjacent_find(v.begin(), v.end()); // 만약 못 찾으면 "찾는 구간"의 끝 반복자 반환

	print(iter, v.end());

	return 0;
}