/************
<�ּ�>		: p178
**********
<�ذ���>	:

x�� �ʱ�ȭ�� n���� ���Ҹ� ������ vector
vector<T> v(n, x);

**********
<�����Ʈ>	:

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

	v.resize(10, 12345); // �⺻�� 12345�� resize
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	cout << endl;

	return 0;
}