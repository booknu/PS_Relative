/************
<�ּ�>		: p174
**********
<�ذ���>	:

vector�� capacity�� �̸� ������ reallocate�� �ɸ��� �ð��� ����

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v;

	// �Ҵ��� �޸𸮸� �̸� ����
	v.reserve(8);
	cout << v.capacity() << endl;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	cout << v.capacity() << endl;

	return 0;
}