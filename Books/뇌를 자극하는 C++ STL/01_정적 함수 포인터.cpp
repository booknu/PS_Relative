/************
<�ּ�>		: p63
**********
<�ذ���>	:

���� �Լ� ������

1. �����Լ�
2. namespace ���� �����Լ�
3. ��ü�� static ����Լ�

�� ����ų �� ����

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

void Print(int n) {
	cout << "�����Լ�: " << n << endl;
}

namespace A {
	void Print(int n) {
		cout << "namespace A �����Լ�: " << n << endl;
	}
}

class Point {
public:
	static void Print(int n) {
		cout << "Point Ŭ������ static ����Լ�: " << n << endl;
	}
};

int main(void) {
	void(*pf)(int);
	
	// �Լ� �̸����� ȣ��
	Print(10);
	A::Print(11);
	Point::Print(12);

	// �Լ� �����ͷ� ȣ��
	pf = Print;
	pf(10);
	pf = A::Print;
	pf(11);
	pf = Point::Print;
	pf(12);

	return 0;
}