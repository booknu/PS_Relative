/************
<�ּ�>		: p156
**********
<�ذ���>	:

bool not2(Functional &func) �Լ���ü
bool�� ��ȯ�ϴ� ������ �Լ���ü�� func�� �ݴ� ���� ��ȯ

**********
<�����Ʈ>	:

*/

#include <iostream>
#include <functional> // not2, less, greater
using namespace std;

int main(void) {
	// �ӽ� ��ü�� ��
	cout << less<int>()(10, 20) << endl;
	cout << less<int>()(20, 20) << endl;
	cout << less<int>()(20, 10) << endl;
	cout << "================" << endl;
	cout << not2(less<int>())(10, 20) << endl;
	cout << not2(less<int>())(20, 20) << endl;
	cout << not2(less<int>())(20, 10) << endl;
	cout << endl;

	// ��ü�� ��
	less<int> l;
	cout << l(10, 20) << endl;
	cout << l(20, 20) << endl;
	cout << l(20, 10) << endl;
	cout << "================" << endl;
	cout << not2(l)(10, 20) << endl;
	cout << not2(l)(20, 20) << endl;
	cout << not2(l)(20, 10) << endl;

	return 0;
}