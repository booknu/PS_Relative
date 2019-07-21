///************
//<주소>		: p383
//**********
//<해결방안>	:
//
//이렇게 다중 상속 가능
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class BaseOne {
//public:
//	void func1() { cout << "func1();" << endl; }
//};
//
//class BaseTwo {
//public:
//	void func2() { cout << "func2();" << endl; }
//};
//
//class MultiDerived : public BaseOne, protected BaseTwo {
//public:
//	void myFunc() {
//		func1();
//		func2();
//	}
//};
//
//int main() {
//	MultiDerived m;
//	// m.func2(); 는 protected 상속이기 때문에 접근 불가!
//	m.myFunc();
//}