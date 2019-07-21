///************
//<주소>		: p492
//**********
//<해결방안>	:
//
//Number n(20);
//Number res = n + 20;
//
//이 연산이 제대로 이루어지려면
//1. Number클래스가 operator+를 오버로딩 하고 있다.
//2. Number클래스가 int 데이터로 형변환이 되어야 한다. (그리고 나서 int의 operator+로 진행)
//이 둘 중 하나가 되어야 한다.
//
//지금은 Number클래스를 int 데이터로 형변환 하는 법을 사용했다.
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Number {
//private:
//	int num;
//
//public:
//	Number(int n = 0) : num(n) {
//		cout << "Number 생성자: " << n << endl;
//	}
//
//	Number& operator=(const Number& copy) {
//		cout << "operator=" << endl;
//		num = copy.num;
//		return *this;
//	}
//
//	/**
//	 *	형 변환 연산자 오버로딩
//	 *	반환형을 지정할 필요가 없다.
//	 *	@return 변환된 num
//	 */
//	operator int() {
//		return num;
//	}
//
//	void print() {
//		cout << num << endl;
//	}
//};
//
//int main() {
//	Number op;
//	op = 20;
//	Number res = op + 30; // Number op가 int 자료형으로 변환된다!
//	res.print();
//}