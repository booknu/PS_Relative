///************
//<주소>		: p220
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
//class MyClass {
//private:
//	int n1, n2;
//
//public:
//	MyClass(int n1 = 0, int n2 = 0) : n1(n1), n2(n2) { }
//	MyClass(MyClass &another) : n1(another.n1), n2(another.n2) { }
//	void print() { cout << n1 << ' ' << n2 << endl; }
//};
//
//int main(void) {
//	MyClass c1 = 200; // MyClass c1(200); 으로 변환! (implicit 변환) (explicit 키워드 붙이면 안 됨)
//	c1.print();
//
//	return 0;
//}