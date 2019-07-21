///************
//<주소>		: p150
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Point {
//public:
//	int x, y;
//};
//
//class Rect {
//public:
//	Point upLeft;
//	Point downRight;
//public:
//	void showRecInfo() {
//		cout << "좌 상단: (" << upLeft.x << ", " << upLeft.y << ")" << endl;
//		cout << "우 하단: (" << downRight.x << ", " << downRight.y << ")" << endl;
//	}
//};
//
//int main(void) {
//	Point pos1 = {-2, 4}; // 상태변수가 public으로 선언되었으므로 struct처럼 선언 가능
//	Point pos2 = {5, 9};
//	Rect rect = {pos2, pos1};
//	rect.showRecInfo();
//	// 만약 프로그래머의 실수로 이와 같이 잘못된 정보로 객체를 생성하면, 막을 방법이 없다.
//	// 현재 이 사각형은 UL, DR의 위치가 바뀌었고, 좌표는 [0, 100]의 범위라는 제한에 맞지 않는다.
//
//	return 0;
//}