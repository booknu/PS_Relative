/************
<�ּ�>		: p196
**********
<�ذ���>	:

reverse_iterator�� �ݺ��� ����ͷ� typedef �Ǿ� ����
++, --�����ڴ� iterator�� �ݴ�� ���
rbegin(), rend() ��� ����

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
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::reverse_iterator riter = v.rbegin(); riter != v.rend(); riter++) {
		cout << *riter << endl;
	}

	return 0;
}