/************
<주소>		: p315
**********
<해결방안>	:

구간 [b, e)에서 구간 [b2, e2)의 원소 중 하나라도 발견되면, 그 첫 원소의 반복자를 반환
만약 발견하지 못했다면, [b, e)의 끝 반복자 반환

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

bool Pred(int a, int b) {
	return abs(a - b) == 1;
}

int main(void) {
	vector<int> seq, targetList;

	seq.push_back(3);
	seq.push_back(4);
	seq.push_back(5);
	seq.push_back(6);
	seq.push_back(7);

	targetList.push_back(1);
	targetList.push_back(2);
	targetList.push_back(5);

	cout << "original" << endl;
	print(seq);
	print(targetList);

	cout << "find_first_of" << endl;
	vector<int>::iterator first = find_first_of(seq.begin(), seq.end(), targetList.begin(), targetList.end(), Pred);
	cout << *first << endl;

	return 0;
}