///************
//<�ּ�>		: p150
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
//public:
//	int x, y;
//};
//
//class Rect {
//public:
//	Point upLeft;
//	Point downRight;
//public:
//	void showRecInfo() {
//		cout << "�� ���: (" << upLeft.x << ", " << upLeft.y << ")" << endl;
//		cout << "�� �ϴ�: (" << downRight.x << ", " << downRight.y << ")" << endl;
//	}
//};
//
//int main(void) {
//	Point pos1 = {-2, 4}; // ���º����� public���� ����Ǿ����Ƿ� structó�� ���� ����
//	Point pos2 = {5, 9};
//	Rect rect = {pos2, pos1};
//	rect.showRecInfo();
//	// ���� ���α׷����� �Ǽ��� �̿� ���� �߸��� ������ ��ü�� �����ϸ�, ���� ����� ����.
//	// ���� �� �簢���� UL, DR�� ��ġ�� �ٲ����, ��ǥ�� [0, 100]�� ������� ���ѿ� ���� �ʴ´�.
//
//	return 0;
//}