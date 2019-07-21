/************
<주소>		: p406
**********
<해결방안>	:

HeapSort 방식으로 정렬된다.
구간 [b, e)에서 상위 e2-b2개만을 정렬해 [b2, e2)에 저장한다.

항상: O(N*log2N)

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
	vector<int> v, sorted(20);

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++) {
		v.push_back(rand() % 1000);
	}
	print(v);
	cout << endl;

	partial_sort_copy(v.begin(), v.end(), sorted.begin(), sorted.end(), greater<int>());
	cout << "[ 복사된 20개 ]" << endl;
	print(sorted.begin(), sorted.end());
	cout << "[ 원본 100개 ]" << endl;
	print(v.begin(), v.end());
	
	return 0;
}