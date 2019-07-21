/************
<주소>		: p348
**********
<해결방안>	:

정렬된 두 순차열 [b, e)와 [b2, e2)를
t에서부터 시작되는 순차열에 합병 정렬한다.

이 때, t에서부터 시작되는 순차열에 공간이 부족하면 에러 발생

반환값으로 dest의 끝 반복자를 반환한다.
즉, [t, returnIter)구간에 합병정렬을 하는 것이다.

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
	vector<int> src1, src2, dest(10);
	fill(src1, 1, 0);
	fill(src2, 1, 5);
	print(src1);
	print(src2);

	vector<int>::iterator iter;
	iter = merge(src1.begin(), src1.end(), src2.begin(), src2.end(), dest.begin()); // 합병된 구간의 끝 반복자를 반환함
	print(dest.begin(), iter);

	return 0;
}