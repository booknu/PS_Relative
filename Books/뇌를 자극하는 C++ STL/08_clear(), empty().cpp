/************
<�ּ�>		: p181
**********
<�ذ���>	:

clear();�� ����ϸ� ���Ҹ� ��� ����(size�� 0����)�� �� ������,
�Ҵ�� �޸𸮴� �������� �ʴ´�.
���� �޸� ���� �� �� �ִ�.
�̰��� swap�� ���� "�ӽ� ��ü vector"�� "���� vector"�� �ٲ����μ� �ذ��� �����ϴ�.

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v(5, 12345);
	
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << "size = " << v.size() << ", capacity = " << v.capacity() << endl;
	
	v.clear();

	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << v.empty() << endl;
	cout << "size = " << v.size() << ", capacity = " << v.capacity() << endl;

	return 0;
}