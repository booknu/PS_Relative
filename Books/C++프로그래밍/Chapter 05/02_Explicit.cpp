///************
//<�ּ�>		: p220
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
//	explicit Class(const Class &another) : num(another.num) { } // explicit���� ������ ��ȯ�� �Ͼ�� ����!
//	void print() { cout << num << endl; }
//};
//
//int main(void) {
//	Class c1(100);
//	// Class c2 = c1; �� explicit ������ �Ұ�!
//	Class c2(c1);
//	c2.print();
//}