/************
<�ּ�>		: p154
**********
<�ذ���>	:

��κ��� �˰����� +�����ڸ����� �����Ǿ� ������,
�̷��� ������ �˰����� ������, ������ ��ȸ�� ��� �����ϴ�.

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

	vector<int>::iterator iter = v.begin() + 3; // 40�� ����Ű�� ������ �ݺ���
	vector<int>::reverse_iterator rIter(iter);

	// iter, rIter�� ���� ��ġ�� ����Ű����, ���� �ٸ���.
	cout << "������ �ݺ����� ��: " << *iter << endl;
	cout << "������ �ݺ����� ��: " << *rIter << endl;


	return 0;
}