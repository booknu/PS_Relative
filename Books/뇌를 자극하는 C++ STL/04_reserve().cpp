/************
<주소>		: p174
**********
<해결방안>	:

vector에 capacity를 미리 결정해 reallocate에 걸리는 시간을 절약

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v;

	// 할당할 메모리를 미리 정함
	v.reserve(8);
	cout << v.capacity() << endl;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	cout << v.capacity() << endl;

	return 0;
}