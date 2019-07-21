///************
//<주소>		: p166 - 문제
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
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
//	void init(int x, int y) {
//		this->x = x;
//		this->y = y;
//	}
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
//	void init(int x, int y, double radius) {
//		center.init(x, y);
//		this->radius = radius;
//	}
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
//	void init(int inX, int inY, int inR, int outX, int outY, int outR) {
//		inside.init(inX, inY, inR);
//		outside.init(outX, outY, outR);
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
//	Ring ring1;
//	ring1.init(1, 1, 4, 2, 2, 9);
//	
//	Ring ring2;
//	ring2.init(-1, -1, -4, -2, -2, -9);
//
//	cout << "**** RING 1 ****" << endl;
//	ring1.printInfo();
//	cout << endl << "**** RING 2 ****" << endl;
//	ring2.printInfo();
//}