///************
//<주소>		: p340, p341
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
//class Base {
//public:
//	void baseFunc() {
//		cout << "baseFunc();" << endl;
//	}
//};
//
//class Derived : public Base {
//public:
//	void derivedFunc() {
//		cout << "derivedFunc();" << endl;
//	}
//};
//
//int main() {
//	Base *bp;
//	Derived *dp = new Derived();
//	bp = dp; // 가능! Derived는 Base를 상속하기 때문
//	// bp->derivedFunc(); 불가! Static Type이 Base 이기 때문
//	// Derived *dp = bp; 불가! Static Type이 Base이기 때문에 불가
//
//	delete bp; // bp, dp는 하나의 객체를 가리키므로 한 번만 delete
//}