///************
//<�ּ�>		: p265
//**********
//<�ذ���>	:
//
//mutable Ű����� const �Լ� ������ ���������� ���� ������ ���!
//���� ������ ������� �ʾƾ� ��
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//using namespace std;
//
//class Class {
//private:
//	int num1;
//	mutable int num2; // const �Լ��� ���� ���������� ���� �ٲ� �� ����!
//
//public:
//	Class(int n1, int n2) : num1(n1), num2(n2) { }
//	void print() const {
//		cout << num1 << ", " << num2 << endl;
//	}
//	void copyToNum2() const {
//		num2 = num1; // const �Լ��̳� ���� �ٲ� �� �ִ�! (mutable ���º����̱� ����)
//	}
//};
//
//int main() {
//	Class c(1, 12345);
//	c.print();
//	c.copyToNum2(); // const �Լ��̳� ���� �ٲ�!
//	c.print();
//
//	return 0;
//}