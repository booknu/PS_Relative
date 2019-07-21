/************
<주소>		: p181
**********
<해결방안>	:

clear();을 사용하면 원소를 모두 삭제(size를 0으로)할 수 있지만,
할당된 메모리는 없어지지 않는다.
따라서 메모리 낭비가 될 수 있다.
이것은 swap을 통해 "임시 객체 vector"과 "기존 vector"을 바꿈으로서 해결이 가능하다.

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
	
	v.clear();

	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << v.empty() << endl;
	cout << "size = " << v.size() << ", capacity = " << v.capacity() << endl;

	return 0;
}