/************
<주소>		: p138
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>

#define pb push_back

using namespace std;


int main(void) {
	vector<int> v;

	v.pb(10);
	v.pb(20);
	v.pb(30);

	vector<int>::iterator iter; // vector을 순회하는 반복자 객체
	for (iter = v.begin(); iter < v.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}