/************
<주소>		: p417
**********
<해결방안>	:

연관 컨테이너의 equal_range와 같은 기능

반환 값으로 x값을 가지는 순차열의 첫 반복자, 끝 반복자를 반환한다.

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

	pair<vector<int>::iterator, vector<int>::iterator> range = equal_range(v.begin(), v.end(), 30);
	print(range.first, range.second);

	return 0;
}