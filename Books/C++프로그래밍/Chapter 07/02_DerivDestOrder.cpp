///************
//<주소>		: p291
//**********
//<해결방안>	:
//
//소멸자는 derived -> base 순으로 호출!
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Base {
//private:
//	int baseNum;
//
//public:
//	Base(int n) : baseNum(n) {
//		cout << "Base(int n);" << endl;
//	}
//	~Base() {
//		cout << "~Base();" << endl;
//	}
//};
//
//class Derived : public Base {
//private:
//	int derivNum;
//
//public:
//	Derived(int n) : Base(n), derivNum(n) {
//		cout << "Derived(int n);" << endl;
//	}
//	~Derived() {
//		cout << "~Derived();" << endl;
//	}
//};
//
//// 소멸자의 경우에는 derived의 소멸자가 먼저 호출되고, base의 소멸자가 호출됨
//int main() {
//	Derived d1(20);
//	Derived d2(30);
//
//	return 0;
//}