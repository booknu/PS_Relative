/************
<주소>		: p121
**********
<해결방안>	:

클라이언트에서 서버로 함수 객체를 넘길 때,
return타입, args타입을 클라이언트 측에서 결정하는 함수 객체를 만들 수 있다.

**********
<오답노트>	:

*/

#include <iostream>
#include <string>
using namespace std;

// return 타입, args 타입을 템플릿으로 사용
template <typename RetType, typename ArgType>
class Functor {
public:
	RetType operator()(ArgType data) {
		cout << data << endl;
		return RetType();
	}
};

int main(void) {
	Functor<void, int> functor1;
	functor1(10);

	Functor<bool, string> functor2;
	functor2("STRING");

	return 0;
}