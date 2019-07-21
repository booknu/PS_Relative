///************
//<주소>		: p544 - Point 헤더파일
//**********
//<해결방안>	:
//
//.h 파일만을 include 하여 클래스 템플릿을 사용하고 싶다면,
//.h 파일 안에서 '선언', '구현'을 동시에 하여야 한다. (따라서 .cpp 파일 내용을 여기에 적으면 됨)
//
//**********
//<오답노트>	:
//
//*/
//
//#ifndef __POINT_TEMPLATE_H__
//#define __POINT_TEMPLATE_H__
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
//#endif