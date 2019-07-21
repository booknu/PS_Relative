/************
<�ּ�>		: p22
**********
<�ذ���>	:

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

	void print() const {
		cout << '(' << x << ", " << y << ')' << endl;
	}

	// ���� ++
	const Point& operator++() {
		x++;
		y++;
		return *this;
	}

	// ���� ++
	const Point operator++(int) {
		Point ret(x, y);
		x++;
		y++;
		return ret;
	}
};

int main(void) {
	Point a(1, 10);
	a++.print();
	a.print();

	Point b(1, 10);
	++b;
	b.print();
}