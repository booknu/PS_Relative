/************
<주소>		: p579
**********
<해결방안>	:

컴파일러는 "함수 템플릿 -> (여러개) 템플릿 함수" 를 만드는데,
이 때 함수 템플릿 안에 static 변수가 있으면
static 변수 또한 여러개의 메모리에 각각 저장된다.

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

template <class T>
void staticValueFunc() {
	static T n = 0;
	n += 1;
	cout << n << " ";
}

class Main {
public:
	static int main() {
		// 생성된 int 템플릿 함수끼리의 static 변수 메모리는 공유하지만,
		staticValueFunc<int>();
		staticValueFunc<int>();
		cout << endl;

		// 다르게 생성된 double 템플릿 함수끼리의 static 변수는 또 다른 공간에 저장됨
		staticValueFunc<double>();
		staticValueFunc<double>();
		cout << endl;

		// 이것도 마찬가지
		staticValueFunc<long>();
		staticValueFunc<long>();
		cout << endl;
		return 0;
	}
};