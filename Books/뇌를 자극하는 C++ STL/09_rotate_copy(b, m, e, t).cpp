/************
<주소>		: p389
**********
<해결방안>	:

[b, e)를 왼쪽으로 m - b만큼 회전한 것을 [t, p)에 저장한다. (p는 반환)
즉, b...m...e 가 있다면,
m........이 된다.
m이 b의 자리로 왼쪽으로 이동하는 것이다.

==> 왼쪽으로 회전하는 것에 주의!!!

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
	vector<int> v, dest(5);

	fill(v);
	print(v);

	rotate_copy(v.begin(), v.begin() + 2, v.end(), dest.begin()); // 왼쪽으로 회전하는 것임에 주의!
	print(v);
	print(dest);

	return 0;
}