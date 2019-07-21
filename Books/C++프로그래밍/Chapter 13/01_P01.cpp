///************
//<주소>		: p535 - 문제 1
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
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
// * 참조자를 이용해 swap (a에 b를 복사, b에 a를 복사하는 방법)
// * 이 경우에는 복사 생성자, 대입 연산자 호출되서 비효율적!
// *
// * @param a, b: 바꿀 객체의 참조자형
// */
//template <class T>
//void swap(T &a, T &b) {
//	T temp = a; // 복사 생성자
//	a = b;		// 대입 연산자
//	b = temp;	// 대입 연산자
//}
//
///**
// * 포인터를 이용해 swap (서로 가리키는 곳만 바꿈)
// * 이 경우에는 복사 생성자, 대입 연산자 호출 안 됨!
// * 
// * @param a, b: 바꿀 객체의 포인터형
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