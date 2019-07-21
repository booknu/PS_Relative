/************
<주소>		: p316
**********
<해결방안>	:

순차열의 모든 원소에 사용자의 동작을 적용할 때 사용.

원소를 수정하지 않는 버전, 원소를 수정하는 버전이 있음

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

class Print {
	char fmt;

public:
	explicit Print(char c = ' ') : fmt(c) { }
	void operator()(int n) {
		cout << n << fmt;
	}
};

int main(void) {
	vector<int> v;

	fill(v, 2);
	for_each(v.begin(), v.end(), Print());
	cout << endl;
	for_each(v.begin(), v.end(), Print(','));
	cout << endl;

	return 0;
}