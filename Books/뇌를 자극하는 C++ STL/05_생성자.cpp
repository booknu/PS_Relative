/************
<주소>		: p177
**********
<해결방안>	:

0으로 초기화된 n개의 원소를 가지는 vector
vector<T> v(n);

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v1(5); // 0으로 초기화 된 size가 5인 배열
	v1.push_back(10);
	v1.push_back(20);
	for (vector<int>::size_type i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}
	cout << endl;

	vector<int> v2(5);
	v2[0] = 10;
	v2[4] = 50;
	//v2[10] = -1111; // 에러!
	for (vector<int>::size_type i = 0; i < v2.size(); i++) {
		cout << v2[i] << endl;
	}

	return 0;
}