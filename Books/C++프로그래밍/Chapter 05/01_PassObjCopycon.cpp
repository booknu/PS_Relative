///************
//<�ּ�>		: p230
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
//	void print() {
//		cout << "num = " << num << endl;
//	}
//};
//
//void objCallByValue(Class obj) {
//	obj.print();
//}
//
//int main(void) {
//	Class c(100);
//	cout << "�Լ� ȣ�� ��" << endl;
//	objCallByValue(c); // ���⼭ Class obj = c; �� �Ͼ (���� ������) (���� explicit Ű���尡 ������ �Ұ�)
//	cout << "�Լ� ȣ�� ��" << endl;
//
//	return 0;
//}