/************
<주소>		: p203
**********
<해결방안>	:

vector끼리의 비교도 연산자를 통해 가능

==, !=: 두 vector의 원소가 같은지
<, <=, >, >=: 두 vector 비교 (문자열 비교 방식)

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v1, v2;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(50);

	if (v1 == v2) {
		cout << "v1 == v2" << endl;
	} else {
		cout << "v1 != v2" << endl;
	}

	if (v1 < v2) {
		cout << "v1 < v2" << endl;
	}

	return 0;
}