///************
//<�ּ�>		: p246
//**********
//<�ذ���>	:
//const ������ ���� overloading ����!
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
//	int num;
//
//public:
//	Class(int n) : num(n) { }
//	Class& add(int operand) {
//		num += operand;
//		return *this;
//	}
//	void sameFunc() {
//		cout << "sameFunc: " << num << endl;
//	}
//	void sameFunc() const {
//		cout << "const sameFunc: " << num << endl;
//	}
//};
//
//void yourFunc(const Class &obj) {
//	obj.sameFunc(); // obj�� const�̱� ������ ������ const ���� func ȣ��!
//}
//
//int main(void) {
//	Class c1(1);
//	const Class c2(100);
//	c1.sameFunc(); // const �� ���� func ȣ��
//	c2.sameFunc(); // const ���� func ȣ��
//
//	yourFunc(c1); // const ���� func ȣ��
//	yourFunc(c2); // const ���� func ȣ��
//
//	// const ������ ���� �����ε� ����!
//}
//
