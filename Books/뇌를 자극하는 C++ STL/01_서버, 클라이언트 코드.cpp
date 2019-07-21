/************
<주소>		: p67
**********
<해결방안>	:

서버: 어떤 기능이나 서비스를 제공하는 코드 측
클라이언트: 서버의 기능을 제공받는 코드측

일반적으로 서버는 하나지만, 그것을 이용하는 클라이언트는 여러개

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

//// 서버 ////
void PrintHello() {
	cout << "Hello!" << endl;
}

//// 클라이언트 ////
int main(void) {
	PrintHello();

	return 0;
}