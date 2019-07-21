/************
<주소>		: p358
**********
<해결방안>	:

for_each와 transform은 현재 원소와 어떤 계산을 통하여 원소의 값을 바꾼다는 점은 같으나,
transform은 원본 순차열에는 영향을 미치지 않고 목적지의 순차열로 저장된다는 점이 다르다.

따라서 transform의 함수류는 반환값에 따라 원소가 바뀐다.

반환값은 목적지 순차열의 끝 반복자이다.

또한 Overwrite 방식으로 저장된다.

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

struct Pred {
	int operator()(int n) {
		return -n;
	}
};

int main(void) {
	vector<int> src, dest(5);
	
	fill(src);
	print(src);

	// 다른 vector의 순차열에 저장
	transform(src.begin(), src.end(), dest.begin(), Pred());
	print(src);
	print(dest);

	// 같은 vector의 순차열에 저장
	transform(src.begin(), src.end(), src.begin(), Pred());
	print(src);

	return 0;
}