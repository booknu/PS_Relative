/************
<�ּ�>		: p143
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	vector<int>::iterator iter = find(v.begin(), v.end(), 20);
	cout << *iter << endl;

	iter = find(v.begin(), v.end(), 100);
	// ã�� ���Ұ� ������ Ȯ��
	if (iter == v.end()) {
		cout << "100�� ����" << endl;
	}

	return 0;
}