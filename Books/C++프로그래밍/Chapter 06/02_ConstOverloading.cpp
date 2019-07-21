///************
//<주소>		: p246
//**********
//<해결방안>	:
//const 유무에 따라 overloading 가능!
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
//	int num;
//
//public:
//	Class(int n) : num(n) { }
//	Class& add(int operand) {
//		num += operand;
//		return *this;
//	}
//	void sameFunc() {
//		cout << "sameFunc: " << num << endl;
//	}
//	void sameFunc() const {
//		cout << "const sameFunc: " << num << endl;
//	}
//};
//
//void yourFunc(const Class &obj) {
//	obj.sameFunc(); // obj가 const이기 때문에 무조건 const 붙은 func 호출!
//}
//
//int main(void) {
//	Class c1(1);
//	const Class c2(100);
//	c1.sameFunc(); // const 안 붙은 func 호출
//	c2.sameFunc(); // const 붙은 func 호출
//
//	yourFunc(c1); // const 붙은 func 호출
//	yourFunc(c2); // const 붙은 func 호출
//
//	// const 유무에 따라 오버로딩 가능!
//}
//
