///************
//<�ּ�>		: p403
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
//	Point(int x = 0, int y = 0) : x(x), y(y) { }
//	void print() const {
//		cout << "(" << x << ", " << y << ")" << endl;
//	}
//	// Point �ӽð�ü�� ������ �����ڸ� ��ȯ
//	// heap�� �Ҵ��ϴ°� �ƴ�!
//	// �����̶� �ǿ����ڸ� �ٲٴ°� �ƴϰ�, �� ����� ��ȯ�ϴ� ���̹Ƿ� const�� �����
//	Point operator+(const Point &operand) const {
//		Point pos(x + operand.x, y + operand.y);
//		return pos;
//	}
//};
//
//int main() {
//	Point p1(3, 4);
//	Point p2(10, 20);
//	Point res = p1 + p2; // p1.operator+(p2); �� �ٸ�����
//
//	// p1: p1
//	// +: .operator+
//	// p2: (p2)
//
//	p1.print();
//	p2.print();
//	res.print();
//}