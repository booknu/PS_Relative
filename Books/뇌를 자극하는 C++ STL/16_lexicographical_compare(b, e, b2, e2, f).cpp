/************
<주소>		: p321
**********
<해결방안>	:

두 순차열을 사전순(less)으로 비교한다.

반환값은 기본 비교값인 less에 맞는지 여부 (true, false)이다.
즉, a < b인지, a >= b인지만 알 수 있다.

따라서 ==의 여부는 a < b, b > a 여부를 다 따져봐야 한다.

**********
<오답노트>	:

*/
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

// 일반 함수포인터를 인자로 사용하면, 명시적으로 같은 타입의 함수만 받을 수 있고,
// 또한 Functor은 받을 수 없다.
// 따라서 std::function을 사용하면 둘 다 가능하다.
// 여기어 bool(int, int)는 bool을 return하는 int, int를 인자로 받는 함수라는 뜻
typedef std::function<bool(int, int)> Comparator;

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

void test(Comparator comparator) {
	vector<int> v1, v2, v3;

	fill(v1, 1);
	fill(v2, 1);
	fill(v3, 1);
	v3.pop_back();
	v3.push_back(1);

	cout << "original" << endl;
	print(v1);
	print(v2);
	print(v3);

	bool cmp1 = lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), comparator);
	if (cmp1) {
		cout << "f(v1, v2) == true" << endl;
	} else {
		cout << "f(v1, v2) == false" << endl;
	}

	bool cmp2 = lexicographical_compare(v2.begin(), v2.end(), v3.begin(), v3.end(), comparator);
	if (cmp2) {
		cout << "f(v2, v3) == true" << endl;
	} else {
		cout << "f(v2, v3) == false" << endl;
	}

	bool cmp3 = lexicographical_compare(v3.begin(), v3.end(), v2.begin(), v2.end(), comparator);
	if (cmp3) {
		cout << "f(v3, v2) == true" << endl;
	} else {
		cout << "f(v3, v2) == false" << endl;
	}
}

int main(void) {
	test(less<int>());
	test(greater<int>());

	return 0;
}