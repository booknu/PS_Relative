/************
<�ּ�>		: p184
**********
<�ذ���>	:

������ ��ȯ��
���� �̰��� �̿��Ͽ� �� ���� ����

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v;
	
	v.push_back(10);
	v.push_back(50);

	cout << v.front() << endl;
	cout << v.back() << endl;

	return 0;
}