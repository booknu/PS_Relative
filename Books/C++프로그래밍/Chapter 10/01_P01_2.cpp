///************
//<주소>		: p409 - 문제 1의 멤버 함수 기반 오버로딩
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Point {
//private:
//	int x, y;
//
//public:
//	Point(int x = 0, int y = 0) : x(x), y(y) { }
//	void print() const {
//		cout << "(" << x << ", " << y << ")" << endl;
//	}
//	Point operator-(const Point &op) const {
//		return Point(x - op.x, y - op.y);
//	}
//};
//
//int main() {
//	Point a(330, 220);
//	Point b(30, 20);
//	Point res = a - b;
//
//	a.print();
//	b.print();
//	res.print();
//
//	return 0;
//}