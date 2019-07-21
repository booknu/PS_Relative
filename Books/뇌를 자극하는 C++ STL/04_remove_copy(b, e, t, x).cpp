/************
<주소>		: p369
**********
<해결방안>	:

[b, e)의 원소들 중 x가 아닌 원소만 [t, ret)으로 복사한다. (Overwrite)

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

int main(void) {
	vector<int> v, dest(10, -1);

	fill(v);
	print(v);
	print(dest);

	vector<int>::iterator ret = remove_copy(v.begin(), v.end(), dest.begin() + 3, 30);

	print(v); // 원본은 변하지 않음
	print(dest);

	return 0;
}