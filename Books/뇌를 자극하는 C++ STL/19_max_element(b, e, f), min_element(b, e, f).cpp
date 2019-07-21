/************
<주소>		: p326
**********
<해결방안>	:

min, max 원소를 가리키는 반복자를 반환

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

struct Comparator {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int main(void) {
	vector<int> v;
	v.push_back(30);
	v.push_back(20);
	v.push_back(10);
	v.push_back(40);
	v.push_back(50);
	print(v);

	cout << *max_element(v.begin(), v.end(), Comparator()) << endl;
	cout << *min_element(v.begin(), v.end(), Comparator()) << endl;

	return 0;
}