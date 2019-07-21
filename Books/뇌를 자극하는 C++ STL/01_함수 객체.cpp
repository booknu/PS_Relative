/************
<주소>		: p77
**********
<해결방안>	:

[[ 함수 객체의 장점 ]]
1. 다른 멤버함수, 멤버변수를 가질 수 있다.
2. 시그니쳐가 같더라도 객체 타입이 다르면 서로 다른 타입으로 인식된다.
3. 일반 함수보다 속도가 빠르다.
4. 함수 포인터는 inline 될 수 없지만, 함수 객체는 inline 될 수 있다.
5. 컴파일러가 쉽게 최적화 할 수 있다.

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

void Print() {
	cout << "전역 함수" << endl;
}

class Functor {
public:
	void operator()() {
		cout << "함수 객체" << endl;
	}
};

int main(void) {
	Functor f;

	Print();// 전역함수
	f();	// 객체를 함수처럼 사용가능!

	return 0;
}