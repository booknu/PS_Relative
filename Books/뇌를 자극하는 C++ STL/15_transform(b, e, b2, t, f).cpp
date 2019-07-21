/************
<주소>		: p358
**********
<해결방안>	:

transform은 2개의 순차열을 처리해 나머지 1개의 순차열에 저장할 수도 있다.
이에따라 함수류의 인자는 2개가 된다.

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
void fill(vector<T, Predicate> &s, int same = 1, int add = 0) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j < same; j++) {
			s.push_back(i * 10 + add);
		}
	}
}

struct Pred {
	int operator()(int a, int b) {
		return a + b;
	}
};

int main(void) {
	vector<int> v1, v2(5, 5), res(5);

	fill(v1);
	print(v1);
	print(v2);

	vector<int>::iterator iter = transform(v1.begin(), v1.end(), v2.begin(), res.begin(), Pred());
	print(res);

	return 0;
}