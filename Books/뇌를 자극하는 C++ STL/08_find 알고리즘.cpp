/************
<주소>		: p143
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	vector<int>::iterator iter = find(v.begin(), v.end(), 20);
	cout << *iter << endl;

	iter = find(v.begin(), v.end(), 100);
	// 찾는 원소가 없는지 확인
	if (iter == v.end()) {
		cout << "100이 없음" << endl;
	}

	return 0;
}