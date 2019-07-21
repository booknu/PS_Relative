///************
//<주소>		: p478
//**********
//<해결방안>	:
//
//*, -> 의 오버로딩
//-> : 객체의 주소값을 반환
//*  : 객체의 참조값을 반환
//
//*ptr: ptr가 가리키는 것의 참조값을 반환!
//
//밑의 operator-> 구현은 굉장히 위험한 구현이므로 따라하면 안 됨
//(참조는 가능하되, 변경은 불가능 해야 함)
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Num {
//private:
//	int n;
//
//public:
//	Num(int n) : n(n) { }
//	void print() {
//		cout << n << endl;
//	}
//	Num* operator->() {
//		// private 변수인 this를 반환하고 있다!
//		// 정보 은닉에 있어서 절대 하면 안될 일
//		return this;
//	}
//	Num& operator*() {
//		return *this;
//	}
//};
//
//int main() {
//	Num n(20);
//	n.print();
//
//	// n이 포인터 형이 아닌데 포인터처럼 접근하고 있다!
//	n = 40;
//	n.print();
//	(*n) = 30; // n.operator*() = 30; : 객체의 참조값이 반환되므로 가능
//	n->print(); // n.operator->() print(); ==> n.operator->() -> print(); : 객체의 포인터가 반환되고, 그것의 print를 호출하기 위해 ->가 자동으로 추가된 모습
//	(*n).print(); // n.operator*().print(); : 객체의 참조값이 반환되므로 가능
//
//	return 0;
//}