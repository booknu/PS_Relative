/************
<주소>		: p416
**********
<해결방안>	:

연관 컨테이너의 lower_bound, upper_bound와 같은 기능
연관 컨테이너에서는 정렬 기준이 내장되어 있기 때문에 인자 f를 받는 버전이 없지만,
여기에서는 정렬 기준을 직접 넘겨줘야 하기 때문에 f를 받는 버전이 있다.

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

	fill(v, 3);
	print(v);

	vector<int>::iterator lo, up;
	lo = lower_bound(v.begin(), v.end(), 30);
	up = upper_bound(v.begin(), v.end(), 30);
	print(lo, up);

	return 0;
}