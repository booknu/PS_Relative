/************
<�ּ�>		: p145
**********
<�ذ���>	:

less, greater �Լ� ��ü�� �̿��� sort ����� �ٲ� �� ����!

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(void) {
	vector<int> v;
	v.push_back(30);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);

	// �������� ����
	sort(v.begin(), v.end(), less<int>());
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << endl;
	}
	cout << endl;

	// �������� ����
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}