/************
<주소>		: p424
**********
<해결방안>	:

교집합, 차집합, 대칭 차집합

대칭 차집합은 AB - (A + B)

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
	vector<int> v1, v2, v3(8);

	fill(v1);

	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(60);

	print(v1);
	print(v2);
	cout << "=====" << endl;

	vector<int>::iterator end;

	end = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	print(v3);
	print(v3.begin(), end);
	cout << "=====" << endl;

	end = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	print(v3);
	print(v3.begin(), end);
	cout << "=====" << endl;

	end = set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	print(v3);
	print(v3.begin(), end);
	cout << "=====" << endl;

	return 0;
}