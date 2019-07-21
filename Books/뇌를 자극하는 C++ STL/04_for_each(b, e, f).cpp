/************
<주소>		: p341
**********
<해결방안>	:

for_each는 순차열의 각 원소를 수정하는 일에도 쓰일 수 있다.

함수류를 순차열의 각 원소에 적용하는 알고리즘은
for_each, transform이 있는데,

for_each는 출력 매개변수(out param)를 사용하고 (& 레퍼런스)
transform은 함수의 반환값을 사용한다.

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

struct Pred {
	void operator()(int &n) {
		n *= n;
	}
};

int main(void) {
	vector<int> v;

	fill(v);
	print(v);

	for_each(v.begin(), v.end(), Pred());
	print(v);

	return 0;
}