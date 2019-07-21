/************
<주소>		: p307
**********
<해결방안>	:

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

struct Pred {
	bool operator()(int a) {
		return a > 40;
	}
};

int main(void) {
	vector<int> v;
	vector<int>::iterator finded;

	fill(v);
	print(v);

	// find
	finded = find(v.begin(), v.end(), 20);
	cout << *finded << endl;

	// Predicate 이용해 find_if
	finded = find_if(v.begin(), v.end(), Pred());
	cout << *finded << endl;

	// 구간 내에 찾는 원소가 없을 시 구간의 끝 반복자 반환
	// end()가 반환되는게 아님에 주의!
	finded = find_if(v.begin(), v.begin() + 3, Pred());
	print(finded, v.end());

	return 0;
}