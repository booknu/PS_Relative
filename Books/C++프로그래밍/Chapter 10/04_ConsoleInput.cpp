///************
//<�ּ�>		: p436
//**********
//<�ذ���>	:
//
//ostream ��ü�� �ٸ� ��ü ���� << �����ڸ� �����ε� �� �� ó��,
//istream ��ü�� �ٸ� ��ü ���� >> �����ڸ� �����ε� �Ѵ�.
//
//��, 'cin >> �ٸ� ��ü' �� �����ϰ� �����.
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
//	is >> p.x >> p.y; // cin�� �������� ����!
//	// = is.operator>>(p.x).operator>>(p.y);
//	//is >> p.x;
//	//is >> p.y;
//	return is;
//}
//
//int main() {
//	Point p1;
//	cout << "x, y ��ǥ ������ �Է�: ";
//	cin >> p1;
//	cout << p1 << endl << endl;
//
//	Point p2;
//	cout << "x, y ��ǥ ������ �Է�: ";
//	cin >> p2;
//	cout << p2 << endl;
//
//	Point p3, p4;
//	cout << "2�� point ���ؼ�: ";
//	cin >> p3 >> p4;
//	// operator>>(operator>>(cin, p3), p4);  �� ���� ���
//	cout << p3 << endl;
//	cout << p4 << endl;
//}