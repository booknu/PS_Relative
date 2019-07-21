///************
//<주소>		: p285
//**********
//<해결방안>	:
//
//derived 생성자의 initializer을 체크해서 상속하고 있는 base의 생성자를 호출하고 있는지 체크하고,
//만약 없다면 자동으로 base의 void 생성자를 호출함!
//
//생성자 호출 과정은
//derived 생성자 호출됨 -> 그 처리 과정 중 base 생성자를 호출하고, 그에 따라 초기화 -> derived 초기화
//즉, base 멤버 변수 초기화 -> derived 멤버 변수 초기화   순으로 진행됨
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
//	Base() : baseNum(20) {
//		cout << "Base();" << endl;
//	}
//	Base(int bn) : baseNum(bn) {
//		cout << "Base(int bn);" << endl;
//	}
//	void print() {
//		cout << baseNum << endl;
//	}
//};
//
//class Derived : public Base {
//private:
//	int derivNum;
//
//public:
//	// 이렇게 base 생성자를 호출하지 않으면 base의 void 생성자가 호출됨!
//	// base 생성자가 initializer에 있는지 체크함
//	// 만약 base의 void 생성자가 없으면 이 곳에서 컴파일 에러 발생!
//	Derived() : derivNum(30) {
//		cout << "Derived();" << endl;
//	}
//	Derived(int dn) : derivNum(dn) {
//		cout << "Derived(int dn);" << endl;
//	}
//	Derived(int bn, int dn) : Base(bn), derivNum(dn) {
//		cout << "Derived(int bn, int dn)" << endl;
//	}
//	void print() {
//		Base::print();
//		cout << derivNum << endl;
//	}
//};
//
//// 여기서 constructor은 base 생성자가 먼저 불리고, 그 다음 derived 생성자가 불린다는 것을 알 수 있음!
//// but destructor은 derived 소멸자가 불린 다음 base 소멸자가 불림!
//int main() {
//	cout << "[ case 1 ]" << endl;
//	Derived d1;
//	d1.print();
//
//	cout << endl << "[ case 2 ]" << endl;
//	Derived d2(-30);
//	d2.print();
//
//	cout << endl << "[ case 3 ]" << endl;
//	Derived d3(-20, -30);
//	d3.print();
//
//	return 0;
//}