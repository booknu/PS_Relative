/************
<�ּ�>		: p99
**********
<�ذ���>	:

Ư��ȭ �Լ� ���ø��� �Ϲ����� �Լ� ���ø��� ó������ ���ϴ� ��츦 ���� ó���ϰ� �ϴ� ��

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Point {
private:
	int x, y;

public:
	explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
	void Print() const { cout << x << ", " << y << endl; }
};

// �Ϲ�ȭ �Լ� ���ø�
template <typename T>
void Print(T a) {
	// �� ������δ� Point ��� �Ұ�!
	cout << a << endl;
}

// Ư��ȭ �Լ� ���ø�
template <>
void Print(Point a) {
	// ���� Point�� ��츦 Ư��ȭ
	cout << "PrintƯ��ȭ ����: ";
	a.Print();
}

int main(void) {
	Print(10);				// �Ϲ�ȭ �Լ� ���ø�
	Print(20.2);			// �Ϲ�ȭ �Լ� ���ø�
	Print(Point(10, 20));	// Ư��ȭ �Լ� ���ø�

	return 0;
}