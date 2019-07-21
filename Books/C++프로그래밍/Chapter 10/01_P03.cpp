///************
//<�ּ�>		:
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
//
//	bool operator==(const Point &op) const {
//		return (x == op.x && y == op.y);
//	}
//
//	bool operator!=(const Point &op) const {
//		return !(*this == op); // == �����ڸ� �̿��� ����
//	}
//
//	~Point() {
//		cout << "dest" << endl;
//	}
//};
//
//int main() {
//	Point p1(1, 1);
//	Point p2(1, 1);
//	cout << "equals: " << (p1 == p2) << endl;
//	cout << "not equals: " << (p1 != p2) << endl;
//
//	p1 = Point(100, 100); // ���ο� ��ü�� �Ҵ�Ǹ� ���� �ִ� ��ü�� �Ҹ�� (heap�� �ƴ� ��)
//	p2 = Point(200, 200);
//	cout << "equals: " << (p1 == p2) << endl;
//	cout << "not equals: " << (p1 != p2) << endl;
//}