///************
//<�ּ�>		: p419
//**********
//<�ذ���>	:
//
//++a, a++�� ���� ����, ���� �������� �����ε� �ϴ� ��
//[ ��� �Լ� ]
//Obj& operation++() { } : ���� ����
//Obj& operation++(int) { } : ���� ����
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//#include <cassert>
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
//
//	bool operator==(Point &op) {
//		return (x == op.x && y == op.y);
//	}
//
//	bool operator!=(Point &op) {
//		return !(*this == op);
//	}
//
//	// ���� ����
//	Point& operator++() {
//		x++;
//		y++;
//		return *this;
//	}
//
//	// ���� ����
//	// ���� ������ ���� ���� ��ȯ�� ��, ���� ���� �ٲٴ� ���̹Ƿ�,
//	// �ٲ�� �� ��(const Obj)�� ��ȯ�ϰ�, �� ���� ���� �ٲ���Ѵ�.
//	// ��ȯ���� const Obj�̱� ������, (p++)++ �� ���� const Obj�� ��ȯ�� ���� ���� �ٲ� �� ����
//	const Point operator++(int) {
//		const Point curr = *this; // ���� ��ü�� �����ص�
//		x++;
//		y++;
//		return curr;
//	}
//
//	friend Point& operator--(Point &op);
//	friend const Point operator--(Point &op, int);
//};
//
//// ���� ����
//Point& operator--(Point &op) {
//	op.x--;
//	op.y--;
//	return op;
//}
//
//// ���� ����
//// �ٲ�� �� ���� curr�� �����صΰ�, ���� �ٲ� ��, curr ���� ��ȯ�Ѵ�.
//const Point operator--(Point &op, int) {
//	Point curr = op;
//	op.x--;
//	op.y--;
//	// op != curr�̾�� ������ �� ��
//	assert(op != curr);
//	return curr;
//}
//
//int main() {
//	Point p(3, 5);
//	// Point cpy = (p--)-- �� ������ ����! (p--)�� ��ȯ���� const ��ü�̱� ����!
//	Point cpy = p--; // cpy���� p�� ���� ���� 3, 5�� ����ǰ�, p ���� 2, 4���� ��
//	cpy.print();
//	p.print();
//
//	cpy = p++; // cpy���� p�� ���� ���� 2, 4�� ����ǰ�, p ���� 3, 5���� ��
//	cpy.print();
//	p.print();
//}