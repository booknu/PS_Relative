/************
<�ּ�>		: p182
**********
<�ذ���>	:

��� �����̳ʴ� �����̳� ��ü���� swap�� �� �ִ� ����Լ� ����
�̰��� �̿��Ͽ� clear()�� ����ϴ� ���,
�ӽ� vector ��ü�� ���� vector��ü�� swap�ϸ� capacity���� ���̸� clear �� �� �ִ�.

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

	//v.clear();
	vector<int>().swap(v); // clear ��� ���

	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << v.empty() << endl;
	cout << "size = " << v.size() << ", capacity = " << v.capacity() << endl;

	return 0;
}