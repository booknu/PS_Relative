///************
//<주소>		: p190 - 문제 1
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
//	Point(int x, int y) : x(x), y(y) { } // 생성자로 바꿈
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
//	Circle(int x, int y, double radius) : center(x, y), radius(radius) { } // 생성자로 바꿈 (center의 초기화 방식 잘 보기)
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
//	Ring(int inX, int inY, int inR, int outX, int outY, int outR) // 생성자로 바꿈
//		:inside(inX, inY, inR), outside(outX, outY, outR) { // Circle 객체들의 초기화 방식 잘 보기
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
//	Ring ring1(1, 1, 4, 2, 2, 9); // 생성자를 통해 생성
//	
//	Ring ring2(-1, -1, -4, -2, -2, -9); // 생성자를 통해 생성
//
//	cout << "**** RING 1 ****" << endl;
//	ring1.printInfo();
//	cout << endl << "**** RING 2 ****" << endl;
//	ring2.printInfo();
//}