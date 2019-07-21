///************
//<주소>		: p544 - Point 구현파일
//**********
//<해결방안>	:
//
//이렇게 .h 파일과 .cpp 파일이 분리되어 있을 때는,
//클래스 템플릿일 경우 사용 시에 .h, .cpp 파일을 모두 include 해줘야 한다.
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//#include "03_PointTemplate.h"
//using namespace std;
//
//template <class T>
//Point<T>::Point(T x, T y) : x(x), y(y) { } // 이니셜라이저는 구현에서
//
//template <class T>
//void Point<T>::print() const {
//	cout << '(' << x << ", " << y << ')' << endl;
//}