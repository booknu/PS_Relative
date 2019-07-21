///************
//<주소>		: p425
//**********
//<해결방안>	:
//
//연산자 오버로딩을 사용하면 서로 다른 자료형 간의 연산이 가능함.
//하지만,
//Obj1 * Obj2 와
//Obj2 * Obj1 과 같이 교환법칙이 성립하는 연산에 대해서는 두 가지 모두 정의해줘야 한다.
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
//	// int * Point 연산(교환법칙)에 대해서도 정의해줘야 함
//	friend Point operator*(int times, Point &p);
//};
//
//Point operator*(int times, Point &p) {
//	return p * times;
//}
//
//int main() {
//	Point p(1, 2);
//	p.print();
//
//	Point mult = p * 2;
//	mult.print();
//
//	// operator*(int times) 함수가 2번 호출됨2
//	// p*2의 결과 임시 객체에 다시 *5를 해서 만들어진 임시객체를 mult 이름으로 사용
//	mult = p * 2 * 5;
//	mult.print();
//
//	// 이제 교환법칙이 성립되는 연산에 대해서 순서에 상관없이 연산 사용 가능
//	mult = 2 * p * 5;
//	mult.print();
//
//	return 0;
//}