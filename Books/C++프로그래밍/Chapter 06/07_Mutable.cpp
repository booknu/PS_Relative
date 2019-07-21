///************
//<주소>		: p265
//**********
//<해결방안>	:
//
//mutable 키워드는 const 함수 내에서 예외적으로 값의 변경을 허용!
//따라서 가급적 사용하지 않아야 함
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Class {
//private:
//	int num1;
//	mutable int num2; // const 함수에 대해 예외적으로 값이 바뀔 수 있음!
//
//public:
//	Class(int n1, int n2) : num1(n1), num2(n2) { }
//	void print() const {
//		cout << num1 << ", " << num2 << endl;
//	}
//	void copyToNum2() const {
//		num2 = num1; // const 함수이나 값이 바뀔 수 있다! (mutable 상태변수이기 때문)
//	}
//};
//
//int main() {
//	Class c(1, 12345);
//	c.print();
//	c.copyToNum2(); // const 함수이나 값이 바뀜!
//	c.print();
//
//	return 0;
//}