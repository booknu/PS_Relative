/************
<주소>		: p169
**********
<해결방안>	:

v.size()는 unsigned int 타입이다.
따라서 vector내에서 지원하는 typedef된 타입인 "size_type"을 사용하는게 좋다.

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
	
	// int i 대신 size_type i를 사용해 warning 메세지가 없어짐
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	cout << typeid(vector<int>::size_type).name() << endl;

	return 0;
}