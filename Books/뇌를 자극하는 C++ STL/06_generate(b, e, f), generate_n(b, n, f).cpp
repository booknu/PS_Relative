/************
<주소>		: p345
**********
<해결방안>	:

generate는 순차열을 단순한 함수 계산값으로 채우는데 이용됨
함수의 return값이 곧 원소 값이 됨

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

class Pred {
	int data;

public:
	explicit Pred(int init = 0) : data(init) { }
	int operator()() {
		return data++;
	}
};

int main(void) {
	vector<int> v(5);

	generate(v.begin() + 1, v.end() - 1, Pred(1));
	print(v);

	generate_n(v.begin() + 1, 3, Pred(5));
	print(v);

	return 0;
}