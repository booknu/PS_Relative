///************
//<주소>		: p156 - 사각형 표현 중 Rect의 정의파일
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//#include "02_Rect.h"
//using namespace std;
//
//// const Point &p는 p의 함수들 중 const 함수만 사용 가능!!
//// (p의 상태변수를 바꾸지 않는 함수들만 사용 가능)
//// (따라서 p.getX()가 const 함수가 아니라면 컴파일 에러 발생)
//bool Rect::init(const Point &ul, const Point &dr) {
//	if (ul.getX() > dr.getX() || ul.getY() > dr.getY()) {
//		return false;
//	}
//	upLeft = ul;
//	downRight = dr;
//	return true;
//}
//
//void Rect::showInfo() const{
//	cout << "좌 상단: (" << upLeft.getX() << ", " << downRight.getY() << ")" << endl;
//	cout << "우 하단: (" << downRight.getX() << ", " << downRight.getY() << ")" << endl;
//}
