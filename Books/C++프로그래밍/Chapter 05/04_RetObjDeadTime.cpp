///************
//<�ּ�>		: p238
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
//	Class(int n) : num(n) {
//		cout << "New Obj: " << this << endl;
//	}
//	Class(const Class &another) : num(another.num) {
//		cout << "New Obj Copy: " << this << endl;
//	}
//	~Class() {
//		cout << "Destroy obj: " << this << endl;
//	}
//};
//
//Class objRetFunc(Class obj) {
//	cout << "param addr: " << &obj << endl;
//	return obj;
//}
//
//int main(void) {
//	Class c(10); // c ��ü ����
//	objRetFunc(c); // obj ��ü ����, ret ��ü ����, obj ��ü �Ҹ�, ret ��ü �Ҹ�
//
//	cout << endl;
//	Class tempRef = objRetFunc(c); // obj ��ü ����, ret ��ü ����, obj ��ü �Ҹ�
//	cout << "Return Obj: " << &tempRef << endl;
//	// ret (tempRef) ��ü �Ҹ�
//	// c ��ü �Ҹ�
//}