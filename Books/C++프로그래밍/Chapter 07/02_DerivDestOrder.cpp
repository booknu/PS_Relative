///************
//<�ּ�>		: p291
//**********
//<�ذ���>	:
//
//�Ҹ��ڴ� derived -> base ������ ȣ��!
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
//	int baseNum;
//
//public:
//	Base(int n) : baseNum(n) {
//		cout << "Base(int n);" << endl;
//	}
//	~Base() {
//		cout << "~Base();" << endl;
//	}
//};
//
//class Derived : public Base {
//private:
//	int derivNum;
//
//public:
//	Derived(int n) : Base(n), derivNum(n) {
//		cout << "Derived(int n);" << endl;
//	}
//	~Derived() {
//		cout << "~Derived();" << endl;
//	}
//};
//
//// �Ҹ����� ��쿡�� derived�� �Ҹ��ڰ� ���� ȣ��ǰ�, base�� �Ҹ��ڰ� ȣ���
//int main() {
//	Derived d1(20);
//	Derived d2(30);
//
//	return 0;
//}