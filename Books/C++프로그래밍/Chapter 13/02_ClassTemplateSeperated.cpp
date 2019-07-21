///************
//<주소>		: p543
//**********
//<해결방안>	:
//
//클래스 템플릿의 선언과 구현의 분리
//
//구현을 할 때도 template<class T> 를 삽입해줘야 한다.
//또한 해당 함수의 클래스를 명시할 때도 Object<T>::func() {} 와 같이 해야 한다.
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
//	Point(T x = 0, T y = 0); // default 값은 선언에서
//	void print() const;
//};
//
//template <class T>
//Point<T>::Point(T x, T y) : x(x), y(y) { } // 이니셜라이저는 구현에서
//
//template <class T>
//void Point<T>::print() const {
//	cout << '(' << x << ", " << y << ')' << endl;
//}
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