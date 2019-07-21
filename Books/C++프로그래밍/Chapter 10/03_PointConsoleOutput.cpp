///************
//<주소>		: p435
//**********
//<해결방안>	:
//
//cout << Point 연산을 오버로딩 함으로써
//멤버 함수 print(); 대신 cout << Point 객체 << ... 연산을 직접 할 수 있게 만듬
//(자바의 toString(); 과 비슷한 기능, 다른 구현)
//(toString()은 String을 반환하지만, c++의 cout << 연산은 직접 operator<< 함수를 호출해, 그 곳에서 출력을 실시함
//
//std의 ostream 안에 들어가 멤버함수를 추가하는 것은 불가능하므로, 전역함수로 오버로딩 하여야 한다.
//
//따라서 함수 형태는 ostream& operator<<(ostream&, Point) 가 된다.
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
//	// 전역함수로 operator<<를 오버로딩 하므로
//	// 인자는 ostream&, Point가 되어야 한다.
//	// (호출시 operator<<(cout, p);)
//	friend ostream& operator<<(ostream&, const Point &p);
//};
//
//ostream& operator<<(ostream& os, const Point &p) {
//	os << '(' << p.x << ", " << p.y << ')';
//	return os;
//}
//
//int main() {
//	Point p(3, 4);
//	cout << p << endl; // 이제는 이렇게 Point를 인자로 operator<<(cout, p); 호출 가능!
//	operator<<(cout, p).operator<<(endl); // 위 식은 이것과 같은 기능을 한다.
//}