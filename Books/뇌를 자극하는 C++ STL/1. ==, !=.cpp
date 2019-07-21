/************
<주소>		: p25
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

	bool operator==(const Point& other) const {
		return x == other.x && y == other.y;
	}

	bool operator!=(const Point& other) const {
		return !(*this == other);
	}
};

int main(void) {
	Point a(1, 10);
	Point b(1, 10);
	Point c(1, 20);
	cout << "a == b " << (a == b) << endl;
	cout << "a == c " << (a == c) << endl;
	cout << "a != b " << (a != b) << endl;
	cout << "a != c " << (a != c) << endl;
}