///************
//<�ּ�>		: p114 - ����
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//
//using namespace std;
//
//// ���� (y, x)�� �������� ����
//struct Point {
//	int y, x;
//
//	// ��ǥ �̵�
//	void move(int y, int x) {
//		Point::y += y; // this�� ���� ���
//		Point::x += x; // this�� ���� ���
//	}
//
//	// ��ǥ �̵�
//	void move(const Point &pos) {
//		y += pos.y;
//		x += pos.x;
//	}
//
//	// ��ǥ ���
//	void showPos() {
//		cout << "(" << y << ", " << x << ")" << endl;
//	}
//};
//
//int main(void) {
//	Point pos1 = { 12, 4 };
//	Point pos2 = { 20, 30 };
//
//	pos1.move(-7, 10);
//	pos1.showPos();
//
//	pos1.move(pos2);
//	pos1.showPos();
//
//	return 0;
//}