/************
<주소>		: p646
**********
<해결방안>	:

[ 사용조건 ]
Derive -> Base
Base -> Derived (단, Base가 Polymorphic Class 일 경우)

[ 대상 ]
포인터형, 참조자형

[ Polymorphic Class ]
하나 이상의 가상함수를 지니는 클래스

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
		Base *bp = new Derived();
		Derived *dp = dynamic_cast<Derived*>(bp); // Base가 Polymorphic Class 이므로 dynamic_cast 가능!
		dp->print();

		return 0;
	}
};