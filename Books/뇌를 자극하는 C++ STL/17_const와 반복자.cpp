/************
<�ּ�>		: p194
**********
<�ذ���>	:

iter�� const�� �����ϸ�
int* const p;�� ����.
��, ������(iter)�� ����Ű�� �ּҸ� �ٲ��� ���Ѵ� (++, --... ��� �Ұ�)

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> v;
	int arr[] = { 10, 20, 30, 40, 50 };

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin();
	int *p = arr;
	cout << *iter << ", " << *p << endl; // iter�� pó�� ����

	vector<int>::const_iterator c_iter = v.begin();
	const int *c_p = arr;
	cout << *c_iter << ", " << *c_p << endl; // c_iter�� c_pó�� ����

	// iter�� const�� �����ϸ� ���� ���ҷ� �̵� �Ұ�! (�����Ͱ� ����Ű�� �ּ� ���� �Ұ�)
	const vector<int>::const_iterator citer_const = v.begin();
	const int* const cp_const = arr;
	cout << *citer_const << ", " << cp_const << endl;

	return 0;
}