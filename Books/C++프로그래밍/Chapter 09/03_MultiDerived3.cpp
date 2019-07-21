///************
//<주소>		: p386
//**********
//<해결방안>	:
//
//[ 다중 상속의 문제점 2 ]
//상속하는 두 객체의 Base가 같은 객체일시, Base의 멤버를 두 번 포함하게 된다.
//(따라서 Base의 멤버에 접근할 때 직접 이름을 지명해줘야 한다.)
//==> 상속하는 두 객체가 Base를 virtual 상속하고 있으면 해결 가능
//
//[ 예제 설명 ]
//LastDerived가 Base를 2번 간접 상속하게 된다.
//이 때 Base를 virtual 상속하지 않았다면 Base의 멤버는 두 번 포함되었을 것이다.
//따라서 이 경우에는 Base 클래스의 함수 baseFunc();를 이름만으로 호출할 수 없게된다.
//
//[ virtual 상속 ]
//다중 상속시 상속하는 여러개의 클래스 중 Base를 공유하는 클래스가 있다면,
//Base를 virtual 상속함으로서 여러번 생성자가 호출되어 중복 포함되는 것을 막을 수 있다.
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
//	Base() { cout << "Base Constructor" << endl; }
//	void baseFunc() { cout << "baseFunc();" << endl; }
//};
//
//// 가상 상속
//class MidDerivedOne : virtual public Base {
//public:
//	MidDerivedOne() : Base() {
//		cout << "MidDerived1 Constructor" << endl;
//	}
//	void midFunc1() {
//		baseFunc();
//		cout << "midFunc1();" << endl;
//	}
//};
//
//// 가상 상속
//class MidDerivedTwo : virtual public Base {
//public:
//	MidDerivedTwo() : Base() {
//		cout << "MidDerived2 Constructor" << endl;
//	}
//	void midFunc2() {
//		baseFunc();
//		cout << "midFunc2();" << endl;
//	}
//};
//
//class LastDerived : public MidDerivedOne, public MidDerivedTwo {
//public:
//	LastDerived() : MidDerivedOne(), MidDerivedTwo() {
//		cout << "LastDerived Constructor" << endl;
//	}
//	void lastFunc() {
//		midFunc1();
//		midFunc2();
//		baseFunc();
//	}
//};
//
//int main() {
//	cout << "----- 객체 생성 전 -----" << endl;
//	LastDerived ld;
//	cout << "----- 객체 생성 후 -----" << endl;
//	ld.lastFunc();
//
//	return 0;
//}