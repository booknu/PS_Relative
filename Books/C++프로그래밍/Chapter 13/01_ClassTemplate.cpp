///************
//<주소>		: p541
//**********
//<해결방안>	:
//
//클래스 템플릿.
//
//컴파일러는 이것을 보고 자료형에 따라 템플릿 클래스를 알아서 만든다.
//이 예제에서는 3개의 템플릿 클래스가 생긴다.
//
//템플릿 클래스 객체를 생성할 때는 자료형 정보를 꼭 전해줘야 한다.
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//template <class T>
//class Point {
//private:
//	T x, y;
//
//public:
//	Point(T x, T y) : x(x), y(y) { }
//	void print() const {
//		cout << '(' << x << ", " << y << ')' << endl;
//	}
//};
//
//int main() {
//	Point<int> pos1(1, 4);
//	pos1.print();
//
//	Point<double> pos2(1.1, 2.2);
//	pos2.print();
//
//	Point<char> pos3('A', 'Z');
//	pos3.print();
//}