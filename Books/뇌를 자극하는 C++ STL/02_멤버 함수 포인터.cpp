/************
<�ּ�>		: p65
**********
<�ذ���>	:

[[ ��� �Լ� ������ ���� ]]

��ȯ�� (Ŭ����::*�Լ�������)(args);
�Լ������� = &Ŭ����::�Լ��̸�;				& �� �־�� ��!

[[ ��� �Լ� ������ ȣ�� ]]
1. ��ü�� ȣ��
	(��ü.*�Լ�������)(args);				*�Լ������� �������� ȣ��

2. ��ü�����ͷ� ȣ��
	(��ü������->*�Լ�������)(args);

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Point {
	int x, y;

public:
	explicit Point(int _x = 0, int _y = 0): x(_x), y(_y) { } // �ڵ� �� ��ȯ�� ���� �����ڰ� ȣ��Ǵ� ���� ����
	void Print() const { cout << x << ',' << y << endl; }
	void PrintInt(int n) { cout << "����: " << n << endl; }
};

int main(void) {
	Point pt(2, 3);
	Point *p_pt = &pt;

	// ����Լ� ������ ����
	void (Point::*pf1)() const;
	pf1 = &Point::Print;
	void (Point::*pf2)(int);
	pf2 = &Point::PrintInt;

	// ��ü�� �Լ� ȣ��
	pt.Print();
	pt.PrintInt(10);
	cout << endl;

	// ��ü�� ����Լ� �����͸� ���� �Լ� ȣ��
	(pt.*pf1)();
	(pt.*pf2)(10);
	cout << endl;

	// �ּҷ� ����Լ� �����͸� ���� �Լ� ȣ��
	(p_pt->*pf1)();
	(p_pt->*pf2)(10);
	cout << endl;

	return 0;
}