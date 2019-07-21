///************
//<주소>		: p169
//**********
//<해결방안>	:
//
//**********
//<오답노트>	:
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
//	/* 이런 식으로 하면 위와 같이 안 해도 됨 
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
//	// Class()가 호출됨
//	// Class c1(); ==> X
//	// Class *c1 = new Class; ==> O
//	// Class *c1 = new Class(); ==> O
//	Class c1;
//	c1.print();
//
//	// stack에 생성
//	Class c2(1);
//	c2.print();
//
//	// new 로도 heap에 생성 가능
//	Class *c3 = new Class(1, 2);
//	c3->print();
//	delete c3;
//}