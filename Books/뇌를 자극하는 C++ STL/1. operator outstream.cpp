/************
<주소>		: p30
**********
<해결방안>	:

cout.operator<<(Obj &a);
처럼 멤버 함수를 통해 << 연산자를 오버로딩 하려면, ostream 객체 내부에서 해야 한다.
but, 그것은 불가능하기 때문에

operator<<(ostream& cout, Obj &a);
처럼 전역 함수를 통해 << 연산자를 오버로딩 해야한다.

이 때, Obj의 private 필드에 접근하기 위해 friend 선언을 Obj 객체 내부에 한다.

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