///************
//<�ּ�>		: p48
//**********
//<�ذ���>	:
//
//namespace�� �����ϰ� ��ø �Ǿ��� ��, �װ��� �� �ϳ��� namespace�� �����Ͽ� �θ� �� �ִ�.
//
//A::B::C::D::func(10) �� �θ��� ���,
//namespace ABCD = A::B::C::D;
//ABCD::func(10) �� ��� ����
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//
//using namespace std; // �̷��� ��°�� namespace�� ����ϴ� �ͺ���, using sdt::cout �� ���� �ϳ��� ����ϴ°� �� ���� ����
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
//	namespace ABCD = A::B::C::D; // �ϳ��� namespace�� �����Ͽ� �θ� �� ����!
//	cout << "num = " << ABCD::num << endl;
//}