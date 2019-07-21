/************
<주소>		: p22
**********
<해결방안>	:

**********
<오답노트>	:

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

	// 전위 ++
	const Point& operator++() {
		x++;
		y++;
		return *this;
	}

	// 후위 ++
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