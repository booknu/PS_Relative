///************
//<�ּ�>		: p169
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
//class Class {
//private:
//	int n1, n2;
//
//public:
//	Class() {
//		n1 = 0;
//		n2 = 0;
//	}
//
//	Class(int n) {
//		n1 = n;
//		this->n2 = 0;
//	}
//
//	Class(int n1, int n2) {
//		this->n1 = n1;
//		this->n2 = n2;
//	}
//
//	/* �̷� ������ �ϸ� ���� ���� �� �ص� �� 
//	Class(int n1 = 0, int n2 = 0) {
//		this->n1 = n1;
//		this->n2 = n2;
//	}
//	*/
//
//	void print() {
//		cout << n1 << " " << n2 << endl;
//	}
//};
//
//int main(void) {
//	// Class()�� ȣ���
//	// Class c1(); ==> X
//	// Class *c1 = new Class; ==> O
//	// Class *c1 = new Class(); ==> O
//	Class c1;
//	c1.print();
//
//	// stack�� ����
//	Class c2(1);
//	c2.print();
//
//	// new �ε� heap�� ���� ����
//	Class *c3 = new Class(1, 2);
//	c3->print();
//	delete c3;
//}