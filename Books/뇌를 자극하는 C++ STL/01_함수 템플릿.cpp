/************
<주소>		: p93
**********
<해결방안>	:

함수 템플릿: 개발자가 만들어놓은 함수의 틀
템플릿 함수: 함수 템플릿을 기반으로 컴파일러가 타입에 따라 필요한 함수들을 각각 만듬

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

template <typename T>
void Print(T a, T b) {
	cout << a << ", " << b << endl;
}

int main(void) {
	Print(10, 20);
	Print(10.1, 20.2);
	Print("Hello", "World!");

	// 템플릿을 명시하고 사용할 수도 있음
	Print<int>(10, 20);
	Print<double>(10.1, 20.2);
	Print<const char*>("Hello", "World!");

	return 0;
}