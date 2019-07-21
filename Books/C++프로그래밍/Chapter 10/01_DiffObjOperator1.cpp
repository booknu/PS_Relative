///************
//<주소>		: p425
//**********
//<해결방안>	:
//
//연산자 오버로딩을 사용하면 서로 다른 자료형 간의 연산이 가능함.
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
//	Point(int x = 0, int y = 0) : x(x), y(y) {
//		cout << "const: " << x << ", " << y << endl;
//	}
//	void print() const {
//		cout << '(' << x << ", " << y << ')' << endl;
//	}
//	// Point * int 같이 다른 자료형 간의 곱셈 가능!
//	Point operator*(int times) {
//		return Point(x * times, y * times);
//	}
//};
//
//int main() {
//	Point p(1, 2);
//	p.print();
//
//	Point mult = p * 2;
//	mult.print();
//
//	// operator*(int times) 함수가 2번 호출됨
//	// p*2의 결과 임시 객체에 다시 *5를 해서 만들어진 임시객체를 mult 이름으로 사용
//	mult = p * 2 * 5;
//	mult.print();
//
//	// mult = 2 * p; 같이 int * Point는 구현되지 않았으므로 불가 (전역함수로 따로 정의해줘야 함)
//
//	return 0;
//}