/************
<주소>		: p323
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
#include <algorithm>
using namespace std;

class Point {
private:
	int x, y;

public:
	explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
	int getX() const { return x; }
	int getY() const { return y; }
	void Print() const { cout << "(" << x << ", " << y << ")" << endl; }
};

bool XCompare(const Point &a, const Point &b) {
	return a.getX() < b.getX();
}

bool YCompare(const Point &a, const Point &b) {
	return a.getY() < b.getY();
}

int main(void) {
	Point a(10, 20), b(20, 10);

	max(a, b, XCompare).Print();
	max(a, b, YCompare).Print();

	return 0;
}