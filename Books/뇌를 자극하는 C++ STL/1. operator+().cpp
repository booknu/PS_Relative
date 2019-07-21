/************
<주소>		: p18
**********
<해결방안>	:

const Obj operator+(const Obj &other) const

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

	const Point operator+(const Point& other) {
		return Point(x + other.x, y + other.y);
	}
};

int main(void) {
	Point a(1, 2);
	Point b(90, 80);
	Point c = a + b;
	c.print();
}