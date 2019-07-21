/************
<주소>		: p327
**********
<해결방안>	:

두 순차열을 비교하여 원소의 값이 서로 다른 위치를 찾아
pair<iter, iter>로 반환

만약 두 문자열의 길이가 같으면 순차열의 끝 반복자를 반환

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
	vector<int> v1, v2;
	fill(v1, 1);
	fill(v2, 1);

	pair<vector<int>::iterator, vector<int>::iterator> res;

	// 서로 같으면  끝 반복자 쌍을 반환
	res = mismatch(v1.begin(), v1.end() - 1, v2.begin());
	cout << "test 1" << endl;
	print(v1);
	print(v2);
	cout << *res.first << ", " << *res.second << endl;

	// 비교
	v2.pop_back();
	v2.push_back(-1);

	res = mismatch(v1.begin(), v1.end(), v2.begin());
	cout << "test 2" << endl;
	print(v1);
	print(v2);
	cout << *res.first << ", " << *res.second << endl;

	// b ~ e 길이가 더 길면? 오류 발생
	/*v1.push_back(-1);

	cout << "test 2" << endl;
	print(v1);
	print(v2);
	res = mismatch(v1.begin(), v1.end(), v2.begin());
	cout << *res.first << ", " << *res.second << endl;*/

	return 0;
}