///************
//<�ּ�>		: p190 - ���� 1
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include<iostream>
//using std::cout;
//using std::endl;
//using std::cin;
//
//class Point {
//private:
//	int x, y;
//
//public:
//	Point(int x, int y) : x(x), y(y) { } // �����ڷ� �ٲ�
//
//	void printInfo() const {
//		cout << "(" << x << ", " << y << ")" << endl;
//	}
//};
//
//class Circle {
//private:
//	Point center;
//	double radius;
//
//public:
//	Circle(int x, int y, double radius) : center(x, y), radius(radius) { } // �����ڷ� �ٲ� (center�� �ʱ�ȭ ��� �� ����)
//
//	void printInfo() const {
//		cout << "<center>" << endl;
//		center.printInfo();
//		cout << "<radius>" << endl;
//		cout << radius << endl;
//	}
//};
//
//class Ring {
//private:
//	Circle inside;
//	Circle outside;
//	
//public:
//	Ring(int inX, int inY, int inR, int outX, int outY, int outR) // �����ڷ� �ٲ�
//		:inside(inX, inY, inR), outside(outX, outY, outR) { // Circle ��ü���� �ʱ�ȭ ��� �� ����
//	}
//
//	void printInfo() const {
//		cout << "[inside]" << endl;
//		inside.printInfo();
//		cout << "[outside]" << endl;
//		outside.printInfo();
//	}
//};
//
//int main(void) {
//	Ring ring1(1, 1, 4, 2, 2, 9); // �����ڸ� ���� ����
//	
//	Ring ring2(-1, -1, -4, -2, -2, -9); // �����ڸ� ���� ����
//
//	cout << "**** RING 1 ****" << endl;
//	ring1.printInfo();
//	cout << endl << "**** RING 2 ****" << endl;
//	ring2.printInfo();
//}