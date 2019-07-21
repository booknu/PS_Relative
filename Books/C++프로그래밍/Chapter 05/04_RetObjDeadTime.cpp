///************
//<林家>		: p238
//**********
//<秦搬规救>	:
//
//**********
//<坷翠畴飘>	:
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
//	Class c(10); // c 按眉 积己
//	objRetFunc(c); // obj 按眉 汗荤, ret 按眉 汗荤, obj 按眉 家戈, ret 按眉 家戈
//
//	cout << endl;
//	Class tempRef = objRetFunc(c); // obj 按眉 汗荤, ret 按眉 汗荤, obj 按眉 家戈
//	cout << "Return Obj: " << &tempRef << endl;
//	// ret (tempRef) 按眉 家戈
//	// c 按眉 家戈
//}