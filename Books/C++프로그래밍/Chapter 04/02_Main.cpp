///************
//<주소>		: p157 - 사각형 표현 중 Main 파일
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//#include "02_Point.h"
//#include "02_Rect.h"
//using namespace std;
//
//int main(void) {
//	Point pos1;
//	if (!pos1.init(-2, 4)) {
//		cout << "pos1 초기화 실패..." << endl;
//	}
//	if (!pos1.init(2, 4)) {
//		cout << "pos1 초기화 실패... (2)" << endl;
//	}
//
//	Point pos2;
//	if (!pos2.init(5, 9)) {
//		cout << "pos2 초기화 실패..." << endl;
//	}
//
//	Rect rec;
//	if (!rec.init(pos2, pos1)) {
//		cout << "rect 초기화 실패..." << endl;
//	}
//	if (!rec.init(pos1, pos2)) {
//		cout << "rect 초기화 실패... (2)" << endl;
//	}
//	rec.showInfo();
//	return 0;
//}