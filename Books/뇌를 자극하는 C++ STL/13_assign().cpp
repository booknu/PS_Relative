/************
<�ּ�>		: p188
**********
<�ذ���>	:

assign�� resize�� �ٸ��� n���� ���ҿ� x���� �Ҵ��Ų��.
���� ���� vector���°� ���, x���� ���� n���� ���ҵ�� �ȴ�.

**********
<�����Ʈ>	:

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

	v.assign(5, -1); // 5���� ���ҿ� -1 ���� �Ҵ�
	printVector(v);

	return 0;
}