///************
//<�ּ�>		: p425
//**********
//<�ذ���>	:
//
//������ �����ε��� ����ϸ� ���� �ٸ� �ڷ��� ���� ������ ������.
//������,
//Obj1 * Obj2 ��
//Obj2 * Obj1 �� ���� ��ȯ��Ģ�� �����ϴ� ���꿡 ���ؼ��� �� ���� ��� ��������� �Ѵ�.
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
//	// int * Point ����(��ȯ��Ģ)�� ���ؼ��� ��������� ��
//	friend Point operator*(int times, Point &p);
//};
//
//Point operator*(int times, Point &p) {
//	return p * times;
//}
//
//int main() {
//	Point p(1, 2);
//	p.print();
//
//	Point mult = p * 2;
//	mult.print();
//
//	// operator*(int times) �Լ��� 2�� ȣ���2
//	// p*2�� ��� �ӽ� ��ü�� �ٽ� *5�� �ؼ� ������� �ӽð�ü�� mult �̸����� ���
//	mult = p * 2 * 5;
//	mult.print();
//
//	// ���� ��ȯ��Ģ�� �����Ǵ� ���꿡 ���ؼ� ������ ������� ���� ��� ����
//	mult = 2 * p * 5;
//	mult.print();
//
//	return 0;
//}