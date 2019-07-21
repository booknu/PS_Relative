/************
<주소>		: p184
**********
<해결방안>	:

참조를 반환함
따라서 이것을 이용하여 값 수정 가능

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v;
	
	v.push_back(10);
	v.push_back(50);

	cout << v.front() << endl;
	cout << v.back() << endl;

	return 0;
}