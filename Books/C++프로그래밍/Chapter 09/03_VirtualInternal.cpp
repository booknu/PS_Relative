///************
//<주소>		: p379
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
//class AAA {
//private:
//	int num1;
//
//public:
//	virtual void func1() { cout << "AAA::func1();" << endl; }
//	virtual void func2() { cout << "AAA::func2();" << endl; }
//};
//
//class BBB : public AAA {
//private:
//	int num2;
//
//public:
//	virtual void func1() { cout << "BBB::func1();" << endl; }
//	void func3() { cout << "BBB::func3();" << endl; }
//};
//
//int main() {
//	AAA *pa = new AAA();
//	pa->func1();
//
//	BBB *pb = new BBB();
//	pb->func1();
//
//	return 0;
//}