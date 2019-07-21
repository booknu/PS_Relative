///************
//<주소>		: p403
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
//	// Point 임시객체를 생성해 참조자를 반환
//	// heap에 할당하는게 아님!
//	// 연산이란 피연산자를 바꾸는게 아니고, 새 결과를 반환하는 것이므로 const를 사용함
//	Point operator+(const Point &operand) const {
//		Point pos(x + operand.x, y + operand.y);
//		return pos;
//	}
//};
//
//int main() {
//	Point p1(3, 4);
//	Point p2(10, 20);
//	Point res = p1 + p2; // p1.operator+(p2); 와 다름없음
//
//	// p1: p1
//	// +: .operator+
//	// p2: (p2)
//
//	p1.print();
//	p2.print();
//	res.print();
//}