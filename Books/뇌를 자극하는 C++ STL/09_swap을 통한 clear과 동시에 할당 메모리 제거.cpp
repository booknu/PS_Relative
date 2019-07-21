/************
<주소>		: p182
**********
<해결방안>	:

모든 컨테이너는 컨테이너 객체끼리 swap할 수 있는 멤버함수 제공
이것을 이용하여 clear()을 사용하는 대신,
임시 vector 객체와 기존 vector객체를 swap하면 capacity까지 줄이며 clear 할 수 있다.

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v(5, 12345);

	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "size = " << v.size() << ", capacity = " << v.capacity() << endl;

	//v.clear();
	vector<int>().swap(v); // clear 대신 사용

	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << v.empty() << endl;
	cout << "size = " << v.size() << ", capacity = " << v.capacity() << endl;

	return 0;
}