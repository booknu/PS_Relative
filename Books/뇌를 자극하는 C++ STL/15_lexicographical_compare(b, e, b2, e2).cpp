/************
<주소>		: p320
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
	vector<int> v1, v2, v3, v4;

	fill(v1, 1);
	fill(v2, 1);
	fill(v3, 1);
	v3.push_back(1);
	
	cout << "original" << endl;
	print(v1);
	print(v2);
	print(v3);

	bool cmp1 = lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
	if (cmp1) {
		cout << "v1 < v2" << endl;
	} else {
		cout << "v1 >= v2" << endl;
	}

	bool cmp2 = lexicographical_compare(v2.begin(), v2.end(), v3.begin(), v3.end());
	if (cmp2) {
		cout << "v2 < v3" << endl;
	} else {
		cout << "v2 >= v3" << endl;
	}

	bool cmp3 = lexicographical_compare(v3.begin(), v3.end(), v2.begin(), v2.end());
	if (cmp3) {
		cout << "v3 < v2" << endl;
	} else {
		cout << "v3 >= v2" << endl;
	}

	return 0;
}