///************
//<�ּ�>		: p383
//**********
//<�ذ���>	:
//
//�̷��� ���� ��� ����
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class BaseOne {
//public:
//	void func1() { cout << "func1();" << endl; }
//};
//
//class BaseTwo {
//public:
//	void func2() { cout << "func2();" << endl; }
//};
//
//class MultiDerived : public BaseOne, protected BaseTwo {
//public:
//	void myFunc() {
//		func1();
//		func2();
//	}
//};
//
//int main() {
//	MultiDerived m;
//	// m.func2(); �� protected ����̱� ������ ���� �Ұ�!
//	m.myFunc();
//}