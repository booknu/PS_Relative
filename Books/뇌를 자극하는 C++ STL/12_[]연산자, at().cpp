/************
<�ּ�>		: p186
**********
<�ذ���>	:

[]�����ڴ� ���� Ȯ�� x
at()�Լ��� ���� Ȯ�� o (������ ��ȯ) ==> ������ ����� out_of_range ���� ����

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	cout << endl;

	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}
	cout << endl;

	try {
		cout << v.at(4);
	} catch (out_of_range &e) {
		cout << e.what() << endl;
	}
	

	return 0;
}