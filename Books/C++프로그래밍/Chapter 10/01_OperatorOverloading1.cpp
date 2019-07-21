///************
//<주소>		: p402
//**********
//<해결방안>	:
//
//연산자 오버로딩의 두 가지 방법
//
//1. 멤버 함수 사용
//Obj operator+(Obj &operand); 와 같이 구현
//a.operator+(b); 같이 사용됨
//
//2. 전역 함수 사용
//Obj operator+(Obj &op1, Obj &op2); 와 같이 구현
//operator+(op1, op2); 같이 사용됨
//
//==> 둘 다 a + b; 와 같이 사용 가능
//==> 둘 다 구현되어 있을 시 멤버 함수가 우선순위 높음
//
//멤버함수 사용 = Java Comparable 인터페이스 구현
//전역함수 사용 = Java Comparator 인자로 넘기기
//와 비슷함
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
//private:
//	int x, y;
//
//public:
//	Point(int x = 0, int y = 0) : x(x), y(y) { }
//	void print() const {
//		cout << "(" << x << ", " << y << ")" << endl;
//	}
//	// Point 임시객체를 생성해 참조자를 반환
//	// heap에 할당하는게 아님!
//	Point operator+(const Point &operand) {
//		Point pos(x + operand.x, y + operand.y);
//		return pos;
//	}
//};
//
//int main() {
//	Point p1(3, 4);
//	Point p2(10, 20);
//	Point res = p1.operator+(p2); // operator+ 함수를 불러 연산을 수행하고, 그 결과로 복사되어 반환된 Point를 res라는 이름으로 사용
//								  // (&res와 다름 없음) (복사 생성자 챕터 참조)
//	p1.print();
//	p2.print();
//	res.print();
//}