/************
<주소>		: p394
**********
<해결방안>	:

[b, e)에서 마지막 원소를 heap에 삽입한다.
따라서 push_back()과 함께 쓰인다.

heap의 원소 추가 방식은 last child에 원소 삽입 후 heap에 맞게 swap하는 것인데,
이것을 사용한다고 보면 된다.

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

	make_heap(v.begin(), v.end()); // v를 힙의 규칙에 맞게 재배열 
	print(v);

	// heap에 삽입! (push_back과 push_heap은 함께 쓰임)
	v.push_back(60);
	push_heap(v.begin(), v.end());
	print(v);

	return 0;
}