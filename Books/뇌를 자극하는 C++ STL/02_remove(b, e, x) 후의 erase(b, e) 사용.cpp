/************
<주소>		:p366
**********
<해결방안>	:

원소를 제거하는 알고리즘은, 원소를 수정하는 알고리즘의 특수한 버전으로서
실제 원소를 제거하는 것이 아니고, Overwrite 방식을 통해 제거한 것 처럼 보이게 만든다.
따라서 size는 변하지 않는다.

size까지 변하게 하고 싶으면 컨테이너 멤버 함수인 erase()를 사용해야한다.

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

	fill(v);
	print(v);

	vector<int>::iterator ret = remove(v.begin(), v.end(), 30);

	// 실제로 size는 변하지 않는다!
	cout << "size = " << v.size() << endl;
	print(v); // begin ~ end
	print(v.begin(), ret); // begin ~ remove반환값

	// size까지 변하게 하고 싶다면 erase 사용!
	v.erase(ret, v.end());
	print(v);

	return 0;
}