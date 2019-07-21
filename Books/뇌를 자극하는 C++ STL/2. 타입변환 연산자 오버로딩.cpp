/************
<주소>		: p51
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
	// B 객체가 A, int, double 객체로 형변환 가능!
	operator A() {
		cout << "operator A();" << endl;
		return A();
	}
	operator int() {
		cout << "operator int();" << endl;
		return 10;
	}
	operator double() {
		cout << "operator double();" << endl;
		return 9.9;
	}
};
int main(void) {
	B b;

	// 생성하자마자 형변환해서 초기화
	A a = b;
	int i = b;
	double d = b;

	// 선언된 변수를 대입
	a = b;
	i = b;
	d = b;

	// 명시적 형변환
	(A)b;
	(int)b;
	(double)b;
//	(ostream)b; 오버로딩 되지 않은 형변환은 불가!

}