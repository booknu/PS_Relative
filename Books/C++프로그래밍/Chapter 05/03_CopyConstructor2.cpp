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
//	MyClass c1 = 200; // MyClass c1(200); ���� ��ȯ! (implicit ��ȯ) (explicit Ű���� ���̸� �� ��)
//	c1.print();
//
//	return 0;
//}