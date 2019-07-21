/************
<주소>		: p334
**********
<해결방안>	:

인자로 주는 f는 이항 조건자로,
인자로 주어지는 x와 비교

f(*p, x)

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

bool Pred(int a, int x) {
	return abs(a - x) < 3;
}

int main(void) {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(31);
	v.push_back(32);
	v.push_back(40);
	v.push_back(50);
	print(v);

	vector<int>::iterator iter = search_n(v.begin(), v.end(), 3, 30, Pred);
	print(iter, v.end());

	return 0;
}