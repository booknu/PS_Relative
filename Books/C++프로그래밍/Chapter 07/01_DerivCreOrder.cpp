///************
//<�ּ�>		: p285
//**********
//<�ذ���>	:
//
//derived �������� initializer�� üũ�ؼ� ����ϰ� �ִ� base�� �����ڸ� ȣ���ϰ� �ִ��� üũ�ϰ�,
//���� ���ٸ� �ڵ����� base�� void �����ڸ� ȣ����!
//
//������ ȣ�� ������
//derived ������ ȣ��� -> �� ó�� ���� �� base �����ڸ� ȣ���ϰ�, �׿� ���� �ʱ�ȭ -> derived �ʱ�ȭ
//��, base ��� ���� �ʱ�ȭ -> derived ��� ���� �ʱ�ȭ   ������ �����
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
//	// �̷��� base �����ڸ� ȣ������ ������ base�� void �����ڰ� ȣ���!
//	// base �����ڰ� initializer�� �ִ��� üũ��
//	// ���� base�� void �����ڰ� ������ �� ������ ������ ���� �߻�!
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
//// ���⼭ constructor�� base �����ڰ� ���� �Ҹ���, �� ���� derived �����ڰ� �Ҹ��ٴ� ���� �� �� ����!
//// but destructor�� derived �Ҹ��ڰ� �Ҹ� ���� base �Ҹ��ڰ� �Ҹ�!
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