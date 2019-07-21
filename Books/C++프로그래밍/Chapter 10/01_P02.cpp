///************
//<�ּ�>		: p409 - ���� 2
//**********
//<�ذ���>	:
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
//	void print() const {
//		cout << "(" << x << ", " << y << ")" << endl;
//	}
//	// +=�� +�� �ٸ� �����ڴϱ� �ٽ� overloading ����� ��!
//	// ��ȯ���� ����������, ������ �� ��ü�� �����ǹǷ� �������� �ʰ� �� ��ü�� ������ ��ȯ�ϸ� �� 
//	// ��ȯ���� void�� �ص� �������
//	Point& operator+=(const Point &op) {
//		x += op.x;
//		y += op.y;
//		return *this; // ������ ��ȯ
//	}
//	Point& operator-=(const Point &op) {
//		x -= op.x;
//		y -= op.y;
//		return *this; // ������ ��ȯ
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