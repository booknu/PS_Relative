/************
<주소>		: p34
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class FuncObj {
public:
	void operator()(int a) {
		cout << "FuncObj: " << a << endl;
	}
	void operator()(int a, int b) {
		cout << "FuncObj: " << a << ' ' << b << endl;
	}
	void operator()(int a, int b, int c) {
		cout << "FuncObj: " << a << ' ' << b << ' ' << c << endl;
	}
};

int main(void) {
	FuncObj func;
	func(10);
	func(10, 20);
	func(10, 20, 30);

	// 이렇게도 호출 가능 (임시 객체를 통해 호출)
	FuncObj()(10);
	FuncObj()(10, 20);
	FuncObj()(10, 20, 30);
}