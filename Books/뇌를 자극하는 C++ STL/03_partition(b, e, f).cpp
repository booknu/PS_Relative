/************
<주소>		: p379
**********
<해결방안>	:

[b, e)의 원소들을 f를 기준으로 true인 원소는 [b, p)에, false인 원소는 [p, e)에 저장한다.
반환값은 p이다.

단, 순서는 어떻게 들어갈지 예측하지 못한다.
(QuickSort처럼 왼쪽, 오른쪽 원소를 스캔해가며 교환해가는 방식이기 때문)

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

bool Pred(int n){
	return n > 20;
}

int main(void) {
	vector<int> v;

	fill(v);
	print(v);

	vector<int>::iterator p = partition(v.begin(), v.end(), Pred); // 순서는 어떻게 들어갈지 예측 못함!
	print(v.begin(), p);
	print(p, v.end());
	print(v);

	return 0;
}