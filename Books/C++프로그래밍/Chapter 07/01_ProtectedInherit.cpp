///************
//<�ּ�>		: p300
//**********
//<�ذ���>	:
//
//protect ����̶�,
//base Ŭ������ ���º����� �� protected ���� ���� ������ ���� �͵��� ��� protected �� �ٲ㼭 ����϶�� �ǹ�.
//
//����
//public -> protected
//protected -> protected
//private -> ���ʿ� ���� �Ұ�!
//
//**********
//<�����Ʈ>	:
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
//// protected ������� ���!
//class Derived : protected Base {
//
//};
//
//int main() {
//	Derived drv;
//	drv.pub; // ������ ���� �߻�! (public�� protected�� �ٲ�!)
//}