/************
<�ּ�>		: p61
**********
<�ذ���>	:

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

void Print() {
	cout << "���� �����Լ�" << endl;
}

class Point {
public:
	void Print() {
		cout << "��� �Լ�" << endl;
	}
};

int main(void) {
	Point pt;
	Point *p_pt = &pt;

	Print();		// 1. ���� �����Լ� ȣ��
	pt.Print();		// 2. ��ü�� ����Լ� ȣ��
	p_pt->Print();	// 3. ��ü�� �ּҷ� ����Լ� ȣ��

	return 0;
}