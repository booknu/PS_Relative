///************
//<�ּ�>		: p409 - ���� 1�� ���� �Լ� ��� �����ε�
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
//	// ������ �����ε����� friend ������ ������ ����!
//	friend Point operator-(const Point &op1, const Point &op2);
//};
//
//Point operator-(const Point &op1, const Point &op2) {
//	return Point(op1.x - op2.x, op1.y - op2.y);
//}
//
//int main() {
//	Point a(330, 220);
//	Point b(30, 20);
//	Point res = a - b;
//
//	a.print();
//	b.print();
//	res.print();
//
//	return 0;
//}