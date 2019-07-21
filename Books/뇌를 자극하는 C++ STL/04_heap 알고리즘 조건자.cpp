/************
<주소>		: p398
**********
<해결방안>	:

[[ 힙 ]]
트리 내의 모든 원소가 Parent가 Child보다 큰(작은)값을 갖는 완전 이진 트리

[[ 힙을 배열로 ]]
Parent = (Child - 1) / 2
Left Child = Parent * 2 + 1
Right Child = Parent * 2 + 2

[[ 힙에 삽입 ]]
배열의 마지막(last child)에 원소 삽입
parent와 비교를 하며 힙에 규칙에 맞지 않으면 swap

[[ 힙에 Pop ]]
root를 반환
배열의 마지막(last child)의 원소를 root로 옮김
left child, right child와 비교해가며 힙에 규칙에 맞지 않으면 둘 중 큰(작은) 원소와 swap

[[ make_heap 작동 방식 ]]
heap sort와 비슷하게 배열의 첫 원소부터 시작하여 앞에서부터 heap을 만들어가며 heap에 원소 추가

ex) ---: 만들어진 heap
1 2 3 4 5

1 2 3 4 5: 1을 heap에 삽입
-

2 1 3 4 5: 2를 heap에 삽입
---

3 1 2 4 5: 3을 heap에 삽입
-----

4 3 2 1 5: 4를 heap에 삽입
-------

5 4 2 1 3: 5를 heap에 삽입
---------

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

	// 힙으로 만듬
	make_heap(v.begin(), v.end(), greater<int>());
	print(v);

	// 힙에 원소 추가
	v.push_back(60);
	push_heap(v.begin(), v.end(), greater<int>());
	print(v);

	// 힙을 정렬
	sort_heap(v.begin(), v.end(), greater<int>());
	print(v);

	return 0;
}