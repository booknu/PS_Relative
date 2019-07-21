///************
//<주소>		: p114 - 문제
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//
//using namespace std;
//
//// 나는 (y, x)를 기준으로 만듬
//struct Point {
//	int y, x;
//
//	// 좌표 이동
//	void move(int y, int x) {
//		Point::y += y; // this와 같은 기능
//		Point::x += x; // this와 같은 기능
//	}
//
//	// 좌표 이동
//	void move(const Point &pos) {
//		y += pos.y;
//		x += pos.x;
//	}
//
//	// 좌표 출력
//	void showPos() {
//		cout << "(" << y << ", " << x << ")" << endl;
//	}
//};
//
//int main(void) {
//	Point pos1 = { 12, 4 };
//	Point pos2 = { 20, 30 };
//
//	pos1.move(-7, 10);
//	pos1.showPos();
//
//	pos1.move(pos2);
//	pos1.showPos();
//
//	return 0;
//}