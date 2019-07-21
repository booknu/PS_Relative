///************
//<주소>		: p48
//**********
//<해결방안>	:
//
//namespace가 과도하게 중첩 되었을 때, 그것을 또 하나의 namespace로 통일하여 부를 수 있다.
//
//A::B::C::D::func(10) 을 부르는 대신,
//namespace ABCD = A::B::C::D;
//ABCD::func(10) 을 사용 가능
//
//**********
//<오답노트>	:
//
//*/
//
//#include <iostream>
//
//using namespace std; // 이렇게 통째로 namespace를 사용하는 것보다, using sdt::cout 과 같이 하나씩 사용하는게 더 좋은 습관
//
//namespace A {
//	namespace B {
//		namespace C {
//			namespace D {
//				int num = 10;
//			}
//		}
//	}
//}
//
//int main(void) {
//	cout << "num = " << A::B::C::D::num << endl;
//
//	namespace ABCD = A::B::C::D; // 하나의 namespace로 통일하여 부를 수 있음!
//	cout << "num = " << ABCD::num << endl;
//}