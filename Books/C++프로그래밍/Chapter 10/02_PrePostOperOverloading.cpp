///************
//<주소>		: p419
//**********
//<해결방안>	:
//
//++a, a++과 같이 전위, 후위 연산자의 오버로딩 하는 법
//[ 멤버 함수 ]
//Obj& operation++() { } : 전위 연산
//Obj& operation++(int) { } : 후위 연산
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//#include <cassert>
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
//
//	bool operator==(Point &op) {
//		return (x == op.x && y == op.y);
//	}
//
//	bool operator!=(Point &op) {
//		return !(*this == op);
//	}
//
//	// 전위 연산
//	Point& operator++() {
//		x++;
//		y++;
//		return *this;
//	}
//
//	// 후위 연산
//	// 후위 연산은 현재 값을 반환한 후, 현재 값을 바꾸는 것이므로,
//	// 바뀌기 전 값(const Obj)을 반환하고, 그 다음 값을 바꿔야한다.
//	// 반환형이 const Obj이기 때문에, (p++)++ 과 같이 const Obj를 반환한 것의 값을 바꿀 수 없다
//	const Point operator++(int) {
//		const Point curr = *this; // 현재 객체는 복사해둠
//		x++;
//		y++;
//		return curr;
//	}
//
//	friend Point& operator--(Point &op);
//	friend const Point operator--(Point &op, int);
//};
//
//// 전위 연산
//Point& operator--(Point &op) {
//	op.x--;
//	op.y--;
//	return op;
//}
//
//// 후위 연산
//// 바뀌기 전 값을 curr에 복사해두고, 값을 바꾼 뒤, curr 값을 반환한다.
//const Point operator--(Point &op, int) {
//	Point curr = op;
//	op.x--;
//	op.y--;
//	// op != curr이어야 오류가 안 남
//	assert(op != curr);
//	return curr;
//}
//
//int main() {
//	Point p(3, 5);
//	// Point cpy = (p--)-- 는 컴파일 에러! (p--)의 반환형이 const 객체이기 때문!
//	Point cpy = p--; // cpy에는 p의 현재 값인 3, 5가 저장되고, p 값은 2, 4여야 함
//	cpy.print();
//	p.print();
//
//	cpy = p++; // cpy에는 p의 현재 값인 2, 4가 저장되고, p 값은 3, 5여야 함
//	cpy.print();
//	p.print();
//}