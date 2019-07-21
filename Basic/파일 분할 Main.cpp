/************
<주소>		: p544 - 메인 파일
**********
<해결방안>	:

컴파일러는 컴파일 타임에 자료형에 맞는 "템플릿 클래스"들을 생성해야 한다.
그러려면 "클래스 템플릿"의 '선언' 뿐 아니라 '구현'에 대한 정보도 필요하다!

[ 해 결 ]
방법 1: .h 파일에 '선언'과 '구현'을 한꺼번에 한다.
방법 2: .h 파일과 .cpp 파일을 분리해놓으나, 사용시 두 개의 파일 모두를 include한다.

**********
<오답노트>	:

*/

#include "파일 분할 Point.h"
#include "파일 분할 Point.cpp" // 이렇게 구현 파일에 대한 정보도 include 하거나,
class Main {
public:
	static int main() {
		Point<int> pos1(1, 4);;
		pos1.print();

		Point<double> pos2(1.1, 2.2);
		pos2.print();

		Point<char> pos3('A', 'Z');
		pos3.print();

		return 0;
	}
};
