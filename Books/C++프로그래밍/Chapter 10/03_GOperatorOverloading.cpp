///************
//<�ּ�>		: p407
//**********
//<�ذ���>	:
//
//�����Լ� ������ �����ε� �ÿ��� friend ������ ������ ������!
//(private ����� �����ؾ� �ǹǷ�)
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
//	friend Point operator+(Point &op1, Point &op2);
//};
//
//// �����Լ��� ������ �����ε�
//Point operator+(Point &op1, Point &op2) {
//	// friend ������ �Ǿ��� ������ private ���� ����
//	return Point(op1.x + op2.x, op1.y + op2.y);
//}
//
//int main() {
//	Point p1(3, 4);
//	Point p2(10, 20);
//	Point res = p1 + p2; // p1.operator+(p2); �� �ٸ�����
//
//	p1.print();
//	p2.print();
//	res.print();
//}