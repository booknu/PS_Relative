///************
//<주소>		: p196
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
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
//	Class *p1 = c1.getThisPointer(); // c1의 this 포인터를 p1으로 사용함
//	cout << p1 << ", ";
//	p1->print();
//
//	Class c2(200);
//	Class *p2 = c2.getThisPointer(); // c2의 this 포인터를 p2로 사용함
//	cout << p2 << ", ";
//	p2->print();
//
//	return 0;
//}