/************
<주소>		: p410, p413
**********
<해결방안>	:

f상태로 정렬된 구간 [b, e)에서 x를 찾는다.

모든 정렬된 범위 알고리즘에는 조건자 버전의 알고리즘이 제공된다.
만약 default와 다른 방식으로 정렬되었다면, 이것을 꼭 인자로 넘겨주어야 한다.

예를 들어, binary_search(b, e, x, f)가 있다면
[b, e)에는 f기준으로 정렬된 원소들이 있어야 한다.
이 때 ==을 판단하는 것은 equivalence 방식으로 !f(a, b) && !f(b, a) 이면 같은 값이다.

 ==> f가 a == b를 판단하는 기준이 아님에 주의!!!
 ==> f는 a보다 b가 뒤에 오는지를 판단하는 함수!

O(logN)

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
	print(v);

	// f는 [b, e)의 정렬 기준
	// 즉, f는 a보다 b가 뒤에있는지 여부를 반환하는 함수 (true = 뒤, false = 아님)
	if (binary_search(v.begin(), v.end(), 14, less<int>())) {
		cout << "14 있음!" << endl;
	} else {
		cout << "14 없음!" << endl;
	}

	return 0;
}