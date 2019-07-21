/************
<주소>		: p33
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class FuncObject {
public:
	void operator()(int arg) const {
		cout << "FuncObject: " << arg << endl;
	}
};

void func1(int arg) {
	cout << "func: " << arg << endl;
}

int main(void) {
	void(*func2)(int) = func1; // 함수 포인터
	FuncObject func3; // 함수 객체

	func1(10);
	func2(20);
	func3(30);
}