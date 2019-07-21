///************
//<주소>		: p436
//**********
//<해결방안>	:
//
//ostream 객체와 다른 객체 간의 << 연산자를 오버로딩 한 것 처럼,
//istream 객체와 다른 객체 간의 >> 연산자를 오버로딩 한다.
//
//즉, 'cin >> 다른 객체' 를 가능하게 만든다.
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
//	friend ostream& operator<<(ostream&, const Point &p);
//	friend istream& operator>>(istream&, Point &p);
//};
//
//ostream& operator<<(ostream& os, const Point &p) {
//	os << '(' << p.x << ", " << p.y << ')';
//	return os;
//}
//
//istream& operator>>(istream& is, Point &p) {
//	is >> p.x >> p.y; // cin도 연속으로 가능!
//	// = is.operator>>(p.x).operator>>(p.y);
//	//is >> p.x;
//	//is >> p.y;
//	return is;
//}
//
//int main() {
//	Point p1;
//	cout << "x, y 좌표 순으로 입력: ";
//	cin >> p1;
//	cout << p1 << endl << endl;
//
//	Point p2;
//	cout << "x, y 좌표 순으로 입력: ";
//	cin >> p2;
//	cout << p2 << endl;
//
//	Point p3, p4;
//	cout << "2개 point 대해서: ";
//	cin >> p3 >> p4;
//	// operator>>(operator>>(cin, p3), p4);  과 같은 기능
//	cout << p3 << endl;
//	cout << p4 << endl;
//}