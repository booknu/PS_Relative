///************
//<주소>		: p154 - 사각형 표현 중 Point의 정의파일
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include "02_Point.h"
//
//bool Point::init(int x, int y) {
//	return set(x, y);
//}
//
//int Point::getX() const {
//	return x;
//}
//
//int Point::getY() const {
//	return y;
//}
//
//bool Point::setX(int x) {
//	if (x < 0 || x > 100) {
//		return false;
//	}
//	Point::x = x;
//	return true;
//}
//
//bool Point::setY(int y) {
//	if (y < 0 || y > 100) {
//		return false;
//	}
//	Point::y = y;
//	return true;
//}
//
//bool Point::set(int x, int y) {
//	if (x < 0 || y < 0 || x > 100 || y > 100) {
//		return false;
//	}
//	Point::x = x;
//	Point::y = y;
//	return true;
//}