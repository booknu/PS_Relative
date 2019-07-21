/************
<주소>		: p401
**********
<해결방안>	:

QuickSort 방식으로 정렬한다.
qsort에 비해 좋은 점은, Random Access가 가능한 컨테이너라면 무엇이든 정렬 가능하다.
(qsort는 c에서 지원, sort는 stl에서 지원)

평균: O(N*logN)
최악: O(N^2)

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <ctime>
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

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++) {
		v.push_back(rand() % 1000);
	}
	print(v);
	cout << endl;

	sort(v.begin(), v.end());
	print(v);

	return 0;
}