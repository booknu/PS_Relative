///************
//<�ּ�>		: p232
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
//	int num;
//
//public:
//	Class(int n) : num(n) { }
//	Class(Class &another) : num(another.num) {
//		cout << "called copy constructor: Class(Class &another)" << endl;
//	}
//	Class& add(int operand) {
//		cout << "add(" << operand << ")" << endl;
//		num += operand;
//		return *this;
//	}
//	void print() {
//		cout << "num = " << num << endl;
//	}
//};
//
//Class objReturnFunc(Class obj) {
//	cout << "return ����" << endl;
//	return obj;
//}
//
//int main(void) {
//	Class c(100);
//	objReturnFunc(c).add(30).print(); // �Լ��� ȣ��Ǹ� ���ڸ� �����ϸ� ������ ȣ�� �� ��,
//									  // ��ȯ ���� �����ϸ� ������ ȣ�� �� ��
//	c.print();
//
//	return 0;
//}