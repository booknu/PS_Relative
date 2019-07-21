/************
<주소>		: p196
**********
<해결방안>	:

reverse_iterator은 반복자 어댑터로 typedef 되어 있음
++, --연산자는 iterator와 반대로 기능
rbegin(), rend() 사용 가능

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

	for (vector<int>::reverse_iterator riter = v.rbegin(); riter != v.rend(); riter++) {
		cout << *riter << endl;
	}

	return 0;
}