///************
//<�ּ�>		: p402
//**********
//<�ذ���>	:
//
//������ �����ε��� �� ���� ���
//
//1. ��� �Լ� ���
//Obj operator+(Obj &operand); �� ���� ����
//a.operator+(b); ���� ����
//
//2. ���� �Լ� ���
//Obj operator+(Obj &op1, Obj &op2); �� ���� ����
//operator+(op1, op2); ���� ����
//
//==> �� �� a + b; �� ���� ��� ����
//==> �� �� �����Ǿ� ���� �� ��� �Լ��� �켱���� ����
//
//����Լ� ��� = Java Comparable �������̽� ����
//�����Լ� ��� = Java Comparator ���ڷ� �ѱ��
//�� �����
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
//	Point operator+(const Point &operand) {
//		Point pos(x + operand.x, y + operand.y);
//		return pos;
//	}
//};
//
//int main() {
//	Point p1(3, 4);
//	Point p2(10, 20);
//	Point res = p1.operator+(p2); // operator+ �Լ��� �ҷ� ������ �����ϰ�, �� ����� ����Ǿ� ��ȯ�� Point�� res��� �̸����� ���
//								  // (&res�� �ٸ� ����) (���� ������ é�� ����)
//	p1.print();
//	p2.print();
//	res.print();
//}