///************
//<주소>		: p300
//**********
//<해결방안>	:
//
//protect 상속이란,
//base 클래스의 상태변수들 중 protected 보다 접근 범위가 넓은 것들은 모두 protected 로 바꿔서 상속하라는 의미.
//
//따라서
//public -> protected
//protected -> protected
//private -> 애초에 접근 불가!
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
//	int priv;
//protected:
//	int prot;
//public:
//	int pub;
//
//	Base() : priv(1), prot(2), pub(3) { }
//};
//
//// protected 방식으로 상속!
//class Derived : protected Base {
//
//};
//
//int main() {
//	Derived drv;
//	drv.pub; // 컴파일 에러 발생! (public이 protected로 바뀜!)
//}