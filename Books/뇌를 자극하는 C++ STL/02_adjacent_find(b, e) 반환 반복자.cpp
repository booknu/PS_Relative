/************
<주소>		: p298
**********
<해결방안>	:

찾지 못했을 경우, 찾는 구간의 끝 반복자를 반환
(end()가 아님!!)

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

	fill(v);
	print(v);

	vector<int>::iterator iter;
	vector<int>::iterator b = v.begin();
	vector<int>::iterator e = v.begin() + 2;
	iter = adjacent_find(b, e);

	cout << *iter << endl; // 찾지 못하면 end()가 아닌 구간의 끝 반복자, 즉 e를 반환!

	// 맞는 표현 (구간의 끝 반복자가 반환됐는지)
	if (iter != e) {
		cout << "NOT FOUND (iter != e)" << endl;
	}

	// 틀린 표현 (end가 아닌 구간의 끝 반복자를 확인해야)
	if (iter != v.end()) {
		cout << "NOT FOUND (iter != v.end())" << endl;
	}

	return 0;
}