///************
//<주소>		: p407
//**********
//<해결방안>	:
//
//전역함수 연산자 오버로딩 시에는 friend 선언이 굉장히 유용함!
//(private 멤버에 접근해야 되므로)
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
//	friend Point operator+(Point &op1, Point &op2);
//};
//
//// 전역함수로 연산자 오버로딩
//Point operator+(Point &op1, Point &op2) {
//	// friend 선언이 되었기 때문에 private 접근 가능
//	return Point(op1.x + op2.x, op1.y + op2.y);
//}
//
//int main() {
//	Point p1(3, 4);
//	Point p2(10, 20);
//	Point res = p1 + p2; // p1.operator+(p2); 와 다름없음
//
//	p1.print();
//	p2.print();
//	res.print();
//}