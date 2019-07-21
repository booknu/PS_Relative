/************
<주소>		: p640
**********
<해결방안>	:

[ 사용조건 ]
const type -> type

[ 대상 ]
포인터형, 참조자형

[ 사용 예 ]
어떤 함수의 인자가 const형이 아닌데, 실제로 내부에서 값이 바뀌지 않는다면
const 객체/변수는 이 함수의 인자로 보낼 수 없다.
이럴 때 const_cast를 사용하면 함수를 호출 할 수 있다.

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Main {
public:
	/**
	 *	실제로 str의 값이 바뀌지는 않지만, const로 선언되지는 않았다.
	 */
	static void showString(char *str) {
		cout << str << endl;
	}

	/**
	 *	실제로 a, b의 값이 바뀌지는 않지만, const로 선언되지는 않았다.
	 */
	static void add(int &a, int &b) {
		cout << a + b << endl;
	}

	static int main() {
		const char *name = "My Name!";
		char *arg = const_cast<char*>(name); // const char* -> char*
		showString(arg); // const char* -> char* 형변환을 하지 않으면 컴파일 에러가 난다!

		cout << reinterpret_cast<int>(arg) << ' ' << reinterpret_cast<int>(name) << endl;

		// const_cast의 대상은 포인터, 참조자 이므로 이렇게 선언
		const int &a = 100;
		const int &b = 200;

		// const int& -> int&
		int &castA = const_cast<int&>(a);
		int &castB = const_cast<int&>(b);

		add(castA, castB);
		cout << &a << ' ' << &castA << endl;
		cout << &b << ' ' << &castB << endl;

		return 0;
	}
};