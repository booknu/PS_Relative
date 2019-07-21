/************
<주소>		: p490
**********
<해결방안>	:

Number n;
n = 20;
을 하면 대입 연산에서 자료형이 일치하지 않아 이루어지지 않을 것 같지만, (대입 연산은 자료형이 꼭 일치해야 함)
자동 형변환을 통해 대입 연산이 가능하다.
(따라서 대입 연산에서는 좌변의 타입에 따라 우변이 자동 형변환 된다.)

[ 과정 ]
1. Number과 int의 형태가 맞지 않는다는 것을 알아냈다.
2. int형 변수를 const Number 객체로 형변환한다. (임시객체 생성)
3. 임시객체를 대상으로 하는 대입 연산자를 호출한다.

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Number {
private:
	int num;

public:
	Number(int n = 0) : num(n) {
		cout << "Number 생성자: " << n << endl;
	}

	/**
	 *	대입 연산자
	 *	@param copy: const 형태로 선언해야 n = 20; 에서 20이 자동 형변환 되어 인자로 넘겨질 수 있음!
	 *	@return: 복사할 객체의 참조
	 */
	Number& operator=(const Number &copy) {
		cout << "operator=" << endl;
		num = copy.num;
		return *this;
	}

	void print() {
		cout << num << endl;
	}
};

class Main {
public:
	static int main() {
		Number n;
		n = 30; // 30이 const Number 객체로 형변환 된다! (그 과정에서 Number 생성자 호출)
		n.print();

		return 0;
	}
};
