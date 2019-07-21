///************
//<주소>		: p418 - 문제 1, 문제 2
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
//	Point operator-() {
//		return Point(-x, -y);
//	}
//	Point operator~() {
//		return Point(y, x);
//	}
//};
//
//int main() {
//	Point p1(50, 100);
//	p1.print();
//	Point p2 = -p1;
//	p2.print();
//	Point p3 = ~p2;
//	p3.print();
//}
