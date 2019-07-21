///************
//<�ּ�>		: p535 - ���� 1
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using std::cout;
//using std::endl;
//
//class Point {
//private:
//	int x, y;
//
//public:
//	Point(int x = 0, int y = 0) : x(x), y(y) { }
//	Point(Point &copy) : x(copy.x), y(copy.y) { cout << "copy const" << endl; }
//	Point& operator=(Point& copy) {
//		cout << "operator= " << endl;
//		x = copy.x;
//		y = copy.y;
//		return *this;
//	}
//	void print() const {
//		cout << '(' << x << ", " << y << ')' << endl;
//	}
//};
//
///**
// * �����ڸ� �̿��� swap (a�� b�� ����, b�� a�� �����ϴ� ���)
// * �� ��쿡�� ���� ������, ���� ������ ȣ��Ǽ� ��ȿ����!
// *
// * @param a, b: �ٲ� ��ü�� ��������
// */
//template <class T>
//void swap(T &a, T &b) {
//	T temp = a; // ���� ������
//	a = b;		// ���� ������
//	b = temp;	// ���� ������
//}
//
///**
// * �����͸� �̿��� swap (���� ����Ű�� ���� �ٲ�)
// * �� ��쿡�� ���� ������, ���� ������ ȣ�� �� ��!
// * 
// * @param a, b: �ٲ� ��ü�� ��������
// */
//template <class T>
//void swap(T *a, T *b) {
//	T *temp = a;
//	a = b;
//	b = temp;
//}
//
//int main() {
//	Point p1(10, 20);
//	Point p2(-100, -200);
//	swap(p1, p2);
//
//	p1.print();
//	p2.print();
//
//	swap(&p1, &p2);
//
//	p1.print();
//	p2.print();
//}