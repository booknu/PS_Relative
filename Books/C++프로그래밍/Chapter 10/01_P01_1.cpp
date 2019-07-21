///************
//<주소>		: p409 - 문제 1의 전역 함수 기반 오버로딩
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
//	// 연산자 오버로딩에는 friend 선언이 굉장히 유용!
//	friend Point operator-(const Point &op1, const Point &op2);
//};
//
//Point operator-(const Point &op1, const Point &op2) {
//	return Point(op1.x - op2.x, op1.y - op2.y);
//}
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