/************
<주소>		: p68
**********
<해결방안>	:

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;
void Client();

//// 서버 ////
void PrintHello() {
	cout << "Hello" << endl;
	Client(); // 서버측에서 클라이언트 코드 콜백
}

//// 클라이언트 ////
void Client() {
	cout << "Client측에서 코드 구현" << endl; // 콜백 함수
}

int main(void) {
	PrintHello();

	return 0;
}