///************
//<�ּ�>		: p196
//**********
//<�ذ���>	:
//
//**********
//<�����Ʈ>	:
//
//*/
//
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Class {
//private:
//	int num;
//
//public:
//	Class(int num) : num(num) {
//		cout << "num = " << num << ", address = " << this << endl;
//	}
//
//	void print() {
//		cout << num << endl;
//	}
//
//	Class* getThisPointer() {
//		return this;
//	}
//};
//
//int main(void) {
//	Class c1(100);
//	Class *p1 = c1.getThisPointer(); // c1�� this �����͸� p1���� �����
//	cout << p1 << ", ";
//	p1->print();
//
//	Class c2(200);
//	Class *p2 = c2.getThisPointer(); // c2�� this �����͸� p2�� �����
//	cout << p2 << ", ";
//	p2->print();
//
//	return 0;
//}