///************
//<�ּ�>		: p425
//**********
//<�ذ���>	:
//
//������ �����ε��� ����ϸ� ���� �ٸ� �ڷ��� ���� ������ ������.
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
//		cout << '(' << x << ", " << y << ')' << endl;
//	}
//	// Point * int ���� �ٸ� �ڷ��� ���� ���� ����!
//	Point operator*(int times) {
//		return Point(x * times, y * times);
//	}
//};
//
//int main() {
//	Point p(1, 2);
//	p.print();
//
//	Point mult = p * 2;
//	mult.print();
//
//	// operator*(int times) �Լ��� 2�� ȣ���
//	// p*2�� ��� �ӽ� ��ü�� �ٽ� *5�� �ؼ� ������� �ӽð�ü�� mult �̸����� ���
//	mult = p * 2 * 5;
//	mult.print();
//
//	// mult = 2 * p; ���� int * Point�� �������� �ʾ����Ƿ� �Ұ� (�����Լ��� ���� ��������� ��)
//
//	return 0;
//}