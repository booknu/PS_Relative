/************
<주소>		: p428
**********
<해결방안>	:

수치 알고리즘은 <numeric>에 있다.

x를 초기값으로 하는 [b, e)의 연산을 구한다.

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
#include <numeric> // 수치 알고리즘
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

int Oper(int a, int b) {
	return a * b;
}

int main(void) {
	vector<int> v;

	fill(v);
	print(v);

	cout << accumulate(v.begin(), v.end(), 1, Oper) << endl;
	cout << accumulate(v.begin(), v.end(), 1, multiplies<int>());

	return 0;
}