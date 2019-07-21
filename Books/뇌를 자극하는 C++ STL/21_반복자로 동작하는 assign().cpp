/************
<�ּ�>		: p202
**********
<�ذ���>	:

������ ���� [v.begin(), v.end())�� assing�� �� �� �ִ�.
�����ڿ��� ����

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
	vector<int> v1(10, 12345);
	printVector(v1);

	vector<int> v2(v1.begin(), v1.end()); // ������ [v1.begin(), v1.end()) �� v2 �ʱ�ȭ
	printVector(v2);

	vector<int> v3(15, -1);
	printVector(v3);
	v3.assign(v1.begin(), v1.end()); // ������ [v1.begin(), v1.end()) �� v3 �Ҵ�
	printVector(v3);

	return 0;
}