/************
<�ּ�>		: p171
**********
<�ذ���>	:

capacity(): ���� �Ҵ�� �޸� ������ ũ��
max_size(): ���� �� �ִ� ���� �ִ� ���� 

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
	//v.push_back(40);
	v.push_back(50);

	// int i ��� size_type i�� ����� warning �޼����� ������
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	cout << v.capacity() << endl; // size�ʹ� �ٸ���! reallocate�Ǹ� �迭 ũ�Ⱑ �޶����� ���� (���� �迭)
	cout << v.max_size() << endl;

	return 0;
}