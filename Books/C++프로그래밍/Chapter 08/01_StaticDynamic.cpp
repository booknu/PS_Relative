///************
//<�ּ�>		: p340, p341
//**********
//<�ذ���>	:
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
//	bp = dp; // ����! Derived�� Base�� ����ϱ� ����
//	// bp->derivedFunc(); �Ұ�! Static Type�� Base �̱� ����
//	// Derived *dp = bp; �Ұ�! Static Type�� Base�̱� ������ �Ұ�
//
//	delete bp; // bp, dp�� �ϳ��� ��ü�� ����Ű�Ƿ� �� ���� delete
//}