/************
<주소>		: p48
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class A {

};

class B {
public:
	// A, int, double이 형변환 해서 B객체가 되는게 가능!
	B() { cout << "Constructor B();" << endl; }
	B(A &a) { cout << "Constructor B(A &a);" << endl; }
	B(int a) { cout << "Constructor B(int a);" << endl; }
	B(double d) { cout << "Constructor B(double a);" << endl; }
	~B() { cout << "Destructor" << endl; }
};

int main(void) {
	A a;
	int b = 1;
	double c = 1.0;

	B b1 = B();
	B b2 = a;
	B b3 = b;
	B b4 = c;
}