/************
<주소>		: p336
**********
<해결방안>	:

copy(b, e, b2)에는 2가지 모드가 있다.

기본은 덮어쓰기(Overwrite) 모드이고,
반복자 어댑터(insert_iterator)등을 사용하면 삽입(Insert)모드도 가능하다.

Overwrite를 할 때는 dest의 원소가 src보다 많아야 한다.

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
	vector<int> src, dest(5);

	fill(src);
	print(src);

	copy(src.begin(), src.end(), dest.begin());
	print(dest);

	return 0;
}