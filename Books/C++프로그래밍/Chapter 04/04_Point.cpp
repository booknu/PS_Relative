///************
//<주소>		: p177
//**********
//<해결방안>	:
//멤버 이니셜라이저(초기화 리스트) 테스트용
//Point 구현부
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//#include "06_Point.h"
//using namespace std;
//
//Point::Point(const int &x, const int &y) {
//	this->x = x;
//	this->y = y;
//}
//
//int Point::getX() const { return x; }
//int Point::getY() const { return y; }
//
//bool Point::setX(const int &x) {
//	if (x < 0 || x > 100) {
//		cout << "벗어난 범위의 값 전달 (x = " << x << ")" << endl;
//		return false;
//	}
//	this->x = x;
//	return true;
//}
//
//bool Point::setY(const int &y) {
//	if (y < 0 || y > 100) {
//		cout << "벗어난 범위의 값 전달 (y = " << y << ")" << endl;
//		return false;
//	}
//	this->y = y;
//	return true;
//}