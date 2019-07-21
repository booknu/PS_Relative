/************
<�ּ�>		: p151
**********
<�ذ���>	:

reverse_iterator�� iterator�� ++, --������ �ݴ�
�����ڿ� iterator ���ڸ� �ִ� ������ ����

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

	vector<int>::reverse_iterator rIter(v.end()); // �̷������� ����
	vector<int>::reverse_iterator end_rIter(v.begin());

	while (rIter != end_rIter) {
		cout << *rIter << endl;
		rIter++; // ������ �ݺ��ڿʹ� �ݴ�� ����
	}

	return 0;
}