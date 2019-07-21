/************
<주소>		:
**********
<해결방안>	:

virtual 함수가 
Base b = Derived();
에 적용되는지 실험

Base b = Derived(); : 안 됨
Base &ref = Derived(); : 됨
Base *p = Derived() : 됨

[ 결 론 ]
참조형 변수인 경우만 dynamic type에 따라 작동

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Base {
public:
	virtual void sameFunc() {
		cout << "BASE" << endl;
	}
};

class Derived : public Base {
public:
	virtual void sameFunc() {
		cout << "DERIVED" << endl;
	}
};

class Main {
public:
	static int main() {
		// static type에 따라 작동
		cout << "[ Base b1 = Derived(); ]" << endl;
		Base b1 = Derived();
		b1.sameFunc();

		// dynamic type에 따라 작동
		cout << "[ Base *p = &Derived(); ]" << endl;
		Base *b2 = &Derived();
		b2->sameFunc();

		// dynamic type에 따라 작동
		cout << "[ Base *p = new Derived(); ]" << endl;
		Base *b3 = new Derived();
		b2->sameFunc();
		delete b3;

		// dynamic type에 따라 작동
		cout << "[ Base &ref = Derived(); ]" << endl;
		Base &b4 = Derived();
		b4.sameFunc();

		return 0;
	}
};