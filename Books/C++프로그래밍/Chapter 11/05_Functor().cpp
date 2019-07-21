///************
//<주소>		: p483
//**********
//<해결방안>	:
//
//함수처럼 동작하는 클래스를 Functor = Function Object 라고 한다.
//
//이것은 Java의 Comparator 처럼 함수, 객체의 동작에 유연함을 제공할 때 사용된다.
//Java에서는 comp.compareTo(a, b); 처럼 길게 사용해야 하지만,
//C++에서는 comp(a, b); 처럼 짧게 사용이 가능하다!
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
//	Point operator+(const Point &o) const {
//		return Point(x + o.x, y + o.y);
//	}
//	friend ostream& operator<<(ostream &os, Point &p);
//};
//
//ostream& operator<<(ostream &os, Point &p) {
//	os << '(' << p.x << ", " << p.y << ')';
//	return os;
//}
//
///**
// *	@class	Adder
// *	@brief	함수처럼 동작하는 클래스 (Function Object = Functor)
// *			객체의 동작 방식에 유연함을 제공할 때 사용됨!
// *			Java에서의 sort시 Comparator를 구현한 객체를 넘겨줌으로서 sort 안에서 comp.compareTo(a, b); 를 사용할 수 있는 것처럼
// *			C++에서는 comp(a, b); 와 같이 사용 할 수 있다! (더 간결함!)
// */
//class Adder {
//public:
//	// () 연산자를 오버로딩 하여 객체이름(); 과 같이 함수처럼 사용 가능!
//	int operator()(const int &n1, const int &n2) {
//		return n1 + n2;
//	}
//	double operator()(const double &n1, const double &n2) {
//		return n1 + n2;
//	}
//	Point operator()(const Point &n1, const Point &n2) {
//		return n1 + n2;
//	}
//};
//
//int main() {
//	Adder adder;
//	cout << adder(1, 3) << endl;
//	cout << adder(1.11, 2.22) << endl;
//	cout << adder(Point(3, 4), Point(10, 20)) << endl;
//
//	return 0;
//}