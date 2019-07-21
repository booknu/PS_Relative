/************
<주소>		: p371
**********
<해결방안>	:

[b, e)의 원소들 중 인접한 중복 원소가 남지 않게 만든다.
제거 방식은 논리적 Overwrite이다. (size 변화x) (size까지 줄이고 싶으면 erase 병행 사용)
만약 구간 내에 유일한 원소들만 남기고 싶으면 정렬 후 사용하면 된다.

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
	vector<int> v;

	fill(v, 3);
	print(v);

	vector<int>::iterator ret = unique(v.begin(), v.end());
	cout << "size = " << v.size() << endl;
	
	// 실제 size는 바뀌지 않음!
	print(v);
	print(v.begin(), ret);

	// size까지 줄이고 싶으면 erase
	ret = v.erase(ret, v.end());
	print(v);

	return 0;
}