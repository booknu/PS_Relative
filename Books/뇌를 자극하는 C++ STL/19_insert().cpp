/************
<주소>		: p197
**********
<해결방안>	:

insert(iter, x)		: iter 위치에 x 삽입
insert(iter, n, x)	: iter 위치에 n개의 x 삽입
insert(iter, other_iter_begin, other_iter_end): iter 위치에 다른 vector의 begin ~ end 삽입

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int> &v) {
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(void) {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	printVector(v);

	vector<int>::iterator iter = v.begin() + 2; // 2번 index에 -1을 3개 삽입
	v.insert(iter, 3, -1);
	printVector(v);

	// 다른 vector의 특정 구간을 삽입
	vector<int> v2;
	v2.push_back(-100);
	v2.push_back(-200);
	v2.push_back(-300);

	iter = v2.begin() + 1;
	v2.insert(iter, v.begin(), v.end());
	printVector(v2);
	return 0;
}