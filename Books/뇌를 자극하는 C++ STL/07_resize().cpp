/************
<주소>		: p178
**********
<해결방안>	:

x로 초기화된 n개의 원소를 가지는 vector
vector<T> v(n, x);

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v(5, -1);
	v[0] = 10;
	v[4] = 50;
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	cout << endl;

	v.resize(10, 12345); // 기본값 12345로 resize
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	cout << endl;

	return 0;
}