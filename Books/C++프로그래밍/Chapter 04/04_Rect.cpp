///************
//<주소>		: p178
//**********
//<해결방안>	:
//멤버 이니셜라이저(초기화 리스트) 테스트용
//Rect 구현부
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//#include "06_Rect.h"
//using namespace std;
//
//Rect::Rect(const int &ulX, const int &ulY, const int &drX, const int &drY) 
//	:upLeft(ulX, ulY), downRight(drX, drY) {
//	// 멤버 이니셜라이저로 초기화 함
//}
//
//void Rect::print() const {
//	cout << "좌 상단: (" << upLeft.getX() << ", " << upLeft.getY() << ")" << endl;
//	cout << "우 하단: (" << downRight.getX() << ", " << downRight.getY() << ")" << endl;
//}