/************
<주소>		: p381
**********
<해결방안>	:

[b, e)의 원소들을 f를 기준으로 true인 원소는 [b, p)에, false인 원소는 [p, e)에 저장한다.
반환값은 p이다.

상대적인 순서가 유지되지만, partition보다는 성능이 떨어진다.

partition은 QuickSort와 비슷한 방식이지만,
stable_partition은 교환할 원소를 가리키는 두 반복자가 둘 다 왼쪽에서 시작해서 찾는다.
(또한 buffer를 사용하여 구현)

O(N), 사정에 따라 O(N*logN)

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

bool Pred(int n) {
	return n > 20;
}

int main(void) {
	vector<int> v;

	fill(v);
	print(v);

	vector<int>::iterator p = stable_partition(v.begin(), v.end(), Pred); // 순서가 유지됨
	print(v.begin(), p);
	print(p, v.end());
	print(v);

	return 0;
}