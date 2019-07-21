/************
<주소>		: p599
**********
<해결방안>	:

함수를 호출한 지역으로 예외 데이터가 전달되는 현상

[ 설 명 ]
함수를 호출할 때마다 Stack Frame이 쌓이는데,
특정 함수에서 Exception이 throw 되면,
catch가 될 때까지 Stack Frame을 거슬러 올라온다.
이런 현상을 Unwinding 이라고 한다.

[ catch가 안 되면? ]
만약 main문까지 Unwinding 되어도 처리되지 않는다면,
terminate 함수가 호출되며 프로그램이 종료된다.

[ Exception 객체형이 일치하지 않으면? ]
catch가 되지 않고, 그 위로 계속 Unwinding 된다.

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Main {
public:
	static void func1() {
		cout << "func1()" << endl;
		func2();
	}

	static void func2() {
		cout << "func2()" << endl;
		func3();
	}

	static void func3() {
		cout << "func3()" << endl;
		throw -1;
	}

	static int main() {
		try {
			func1();
		} catch (int e) {
			cout << "Exeption code: " << e << endl;
		}
		return 0;
	}
};