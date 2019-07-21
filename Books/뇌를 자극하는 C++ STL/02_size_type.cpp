/************
<�ּ�>		: p169
**********
<�ذ���>	:

v.size()�� unsigned int Ÿ���̴�.
���� vector������ �����ϴ� typedef�� Ÿ���� "size_type"�� ����ϴ°� ����.

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
	
	// int i ��� size_type i�� ����� warning �޼����� ������
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	cout << typeid(vector<int>::size_type).name() << endl;

	return 0;
}