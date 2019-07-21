///************
//<�ּ�>		: p483
//**********
//<�ذ���>	:
//
//�Լ�ó�� �����ϴ� Ŭ������ Functor = Function Object ��� �Ѵ�.
//
//�̰��� Java�� Comparator ó�� �Լ�, ��ü�� ���ۿ� �������� ������ �� ���ȴ�.
//Java������ comp.compareTo(a, b); ó�� ��� ����ؾ� ������,
//C++������ comp(a, b); ó�� ª�� ����� �����ϴ�!
//
//**********
//<�����Ʈ>	:
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
// *	@brief	�Լ�ó�� �����ϴ� Ŭ���� (Function Object = Functor)
// *			��ü�� ���� ��Ŀ� �������� ������ �� ����!
// *			Java������ sort�� Comparator�� ������ ��ü�� �Ѱ������μ� sort �ȿ��� comp.compareTo(a, b); �� ����� �� �ִ� ��ó��
// *			C++������ comp(a, b); �� ���� ��� �� �� �ִ�! (�� ������!)
// */
//class Adder {
//public:
//	// () �����ڸ� �����ε� �Ͽ� ��ü�̸�(); �� ���� �Լ�ó�� ��� ����!
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