/************
<주소>		: p188
**********
<해결방안>	:

assign은 resize와 다르게 n개의 원소에 x값을 할당시킨다.
따라서 이전 vector상태가 어떻든, x값을 가진 n개의 원소들로 된다.

**********
<오답노트>	:

*/

#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int> &v) {
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(void) {
	vector<int> v(10, 12345);
	printVector(v);

	v.assign(5, -1); // 5개의 원소에 -1 값을 할당
	printVector(v);

	return 0;
}