/************
<�ּ�>		: p30
**********
<�ذ���>	:

cout.operator<<(Obj &a);
ó�� ��� �Լ��� ���� << �����ڸ� �����ε� �Ϸ���, ostream ��ü ���ο��� �ؾ� �Ѵ�.
but, �װ��� �Ұ����ϱ� ������

operator<<(ostream& cout, Obj &a);
ó�� ���� �Լ��� ���� << �����ڸ� �����ε� �ؾ��Ѵ�.

�� ��, Obj�� private �ʵ忡 �����ϱ� ���� friend ������ Obj ��ü ���ο� �Ѵ�.

**********
<�����Ʈ>	:

*/

#include <iostream>
using namespace std;

class Point {
private:
	int x, y;

public:
	Point(int _x, int _y) : x(_x), y(_y) {

	}
	
	friend ostream& operator<<(ostream& out, Point &p);
};

ostream& operator<<(ostream& out, Point &p) {
	out << '(' << p.x << ", " << p.y << ')';
	return out;
}

int main(void) {
	Point a(1, 10);
	Point b(99, 999);

	cout << a << " " << b << endl;
}