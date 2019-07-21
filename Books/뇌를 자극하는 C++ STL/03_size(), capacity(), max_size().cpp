/************
<주소>		: p171
**********
<해결방안>	:

capacity(): 실제 할당된 메모리 공간의 크기
max_size(): 담을 수 있는 원소 최대 개수 

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
	//v.push_back(40);
	v.push_back(50);

	// int i 대신 size_type i를 사용해 warning 메세지가 없어짐
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	cout << v.capacity() << endl; // size와는 다르다! reallocate되면 배열 크기가 달라지기 때문 (동적 배열)
	cout << v.max_size() << endl;

	return 0;
}