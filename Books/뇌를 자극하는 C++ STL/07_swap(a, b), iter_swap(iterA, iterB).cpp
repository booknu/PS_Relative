/************
<주소>		: p347
**********
<해결방안>	:

swap은 a, b값을 바꾸고
iter_swap은 iterator인 a, b가 가리키는 값을 바꾼다.

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
void fill(vector<T, Predicate> &s, int same = 1, int add = 0) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j < same; j++) {
			s.push_back(i * 10 + add);
		}
	}
}

int main(void) {
	// swap
	int a = 3, b = 7;
	cout << a << ", " << b << endl;
	
	swap(a, b);
	cout << a << ", " << b << endl;

	// iter_swap
	vector<int> v1(5, 10), v2(5, -1);
	print(v1);
	print(v2);

	iter_swap(v1.begin() + 1, v2.begin() + 3);
	print(v1);
	print(v2);

	return 0;
}