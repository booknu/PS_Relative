/************
<주소>		: p647
**********
<해결방안>	:

[ 발생 위치 ]
dynamic_cast 연산 중 발생

[ 대상 ]
참조자형
(포인터형일 경우는 그냥 NULL 반환)

[ 원인 ]
dynamic_cast 중
dynamic type이 Base -> Derived 인 경우

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

/**
*	virtual 함수를 하나 이상 가지고 있으므로
*	Polymorphic Class
*/
class Base {
public:
	virtual void print() {
		cout << "virtual Base Class" << endl;
	}
};

class Derived : public Base {
public:
	void print() {
		cout << "virtual Derived Class" << endl;
	}
};

class Main {
public:
	static int main() {
		Base b;
		Base &refB = b;

		try {
			Derived &refD = dynamic_cast<Derived&>(refB);
			refD.print();
		} catch (bad_cast e) {
			cout << "type cast 중 Exception 감지" << endl;
			cout << e.what() << endl;
		}

		return 0;
	}
};