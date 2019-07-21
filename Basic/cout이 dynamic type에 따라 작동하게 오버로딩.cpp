/************
<주소>		:
**********
<해결방안>	:

operator<< 은 전역함수로 오버로딩 해야하기 때문에 virtual을 적용하는 것은 불가능하다.
따라서 virtual void out(); 이라는 함수를 출력용으로 사용하고,
operator<< 안에서는 out을 호출하면 dynamic type에 따라 print가 된다.

또한 operator<< 은 가장 Base 클래스에 하나 선언해놓으면 알아서 dynamic type에 따라 out을 호출한다.

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Base {
public:
	// 출력용
	virtual void out(ostream &os) const {
		os << "BASE";
	}
	friend ostream& operator<<(ostream &os, Base &b);
};

// operator<< 오버로딩은 가장 상위의 Base에만 선언해놓으면 됨
// 여기서 b의 dynamic type에 따라 out이 호출됨
ostream& operator<<(ostream &os, const Base &b) {
	b.out(os);
	return os;
}

class Derived : public Base {
public:
	// 출력용
	virtual void out(ostream &os) const {
		os << "DERIVED";
	}
};

class Main {
public:
	static int main() {
		// dynamic type에 따라 출력이 됨!
		Base *b = new Derived();
		cout << *b << endl;
		delete b;

		b = new Base();
		cout << *b << endl;
		delete b;

		return 0;
	}
};
