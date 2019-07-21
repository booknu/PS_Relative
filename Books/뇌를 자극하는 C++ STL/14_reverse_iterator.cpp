/************
<주소>		: p151
**********
<해결방안>	:

reverse_iterator은 iterator와 ++, --동작이 반대
생성자에 iterator 인자를 주는 식으로 생성

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::reverse_iterator rIter(v.end()); // 이런식으로 생성
	vector<int>::reverse_iterator end_rIter(v.begin());

	while (rIter != end_rIter) {
		cout << *rIter << endl;
		rIter++; // 정방향 반복자와는 반대로 동작
	}

	return 0;
}