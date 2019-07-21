/************
<주소>		: p145
**********
<해결방안>	:

less, greater 함수 객체를 이용해 sort 방식을 바꿀 수 있음!

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(void) {
	vector<int> v;
	v.push_back(30);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);

	// 오름차순 정렬
	sort(v.begin(), v.end(), less<int>());
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << endl;
	}
	cout << endl;

	// 내림차순 정렬
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}