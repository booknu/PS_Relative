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
	vector<int> v1(5, -1); // -1���� �ʱ�ȭ �� size�� 5�� �迭
	v1.push_back(10);
	v1.push_back(20);
	for (vector<int>::size_type i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}
	cout << endl;

	vector<int> v2(5, -1);
	v2[0] = 10;
	v2[4] = 50;
	for (vector<int>::size_type i = 0; i < v2.size(); i++) {
		cout << v2[i] << endl;
	}

	return 0;
}