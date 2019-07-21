/************
<주소>		:
**********
<해결방안>	:

1. 전역함수는 헤더파일에 들어가면 안 된다. (컴파일 에러)
   전역변수는 헤더파일에 선언과 값을 넣어도 된다.

2. 다른 파일에서 전역함수/변수에 접근하려면 extern 키워드를 사용해야 한다.
   (함수는 묵시적 extern) (변수는 명시적으로 extern 선언해야)

전역함수의 선언은 .h에서 하고,
구현은 .cpp에서 해야한다.
==> 이렇게 하면 오류 추적이 편해진다.

**********
<오답노트>	:

*/

#include "외부 파일 전역함수.h"
#include <iostream>
using namespace std;

class Main {
public:
	static int main() {
		globFunc();
		cout << globVar << endl;
		cout << GLOB_CONST << endl;

		return 0;
	}
};