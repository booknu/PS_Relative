///************
//<�ּ�>		: p216
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
//	int num1, num2;
//
//public:
//	Class(int n1, int n2) : num1(n1), num2(n2) { }
//	// ���� ������
//	Class(const Class &another) : num1(another.num1), num2(another.num2) {
//		cout << "called Class(Class &another)" << endl;
//	}
//	void print() {
//		cout << num1 << endl << num2 << endl;
//	}
//};
//
//int main(void) {
//	Class c1(100, 200);
//	cout << "���� �� �ʱ�ȭ ����" << endl;
//	Class c2 = c1; // Class c2(c1); ���� ��ȯ��!
//	cout << "���� �� �ʱ�ȭ ����" << endl;
//	c2.print();
//
//	return 0;
//}