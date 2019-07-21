///************
//<주소>		: p409 - 문제 2
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
//	Point(int x = 0, int y = 0) : x(x), y(y) {
//		cout << "const: " << x << ", " << y << endl;
//	}
//	void print() const {
//		cout << "(" << x << ", " << y << ")" << endl;
//	}
//	// +=은 +와 다른 연산자니까 다시 overloading 해줘야 함!
//	// 반환형은 참조형으로, 어차피 이 객체가 수정되므로 복사하지 않고 이 객체의 참조만 반환하면 됨 
//	// 반환형을 void로 해도 상관없음
//	Point& operator+=(const Point &op) {
//		x += op.x;
//		y += op.y;
//		return *this; // 참조를 반환
//	}
//	Point& operator-=(const Point &op) {
//		x -= op.x;
//		y -= op.y;
//		return *this; // 참조를 반환
//	}
//	~Point() {
//		cout << "dest" << endl;
//	}
//};
//
//int main() {
//	Point p1(30, 40);
//	Point p2(3, 4);
//	p1.print();
//	p2.print();
//	p1 += p2;
//	p1.print();
//
//	p1 = Point(110, 220);
//	p2 = Point(10, 20);
//	p1.print();
//	p2.print();
//	p1 -= p2;
//	p1.print();
//}