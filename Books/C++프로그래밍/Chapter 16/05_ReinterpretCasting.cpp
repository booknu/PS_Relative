/************
<주소>		: p642
**********
<해결방안>	:

[ 사용조건 ]
모든 타입

[ 대상 ]
모든 대상

[ 사용 예 ]
1. 변수에 대해 1byte 씩 접근하고 싶을 때
2. 주소값(*)을 int로 변환하고 싶을 때
3. int를 주소값(*)으로 변환하고 싶을 때


**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Main {
public:
	static int main() {
		//// 변수에 대해 특정 byte 단위로 접근 가능!
		int n = 0x010203; // 16진수 = 4bit
		char *ptr = reinterpret_cast<char*>(&n); // char* ptr은 1byte 단위로 접근 가능

		for (int i = 0; i < sizeof(n); i++) {
			// char* 포인터에 연산을 하면 1byte씩 증가
			cout << static_cast<int>(*(ptr + i)) << endl;
		}


		int num = 72;
		int *iptr = &num;

		//// 주소값(*)을 int로 변환 가능!
		int addr = reinterpret_cast<int>(iptr); // 주소값(*)을 정수로 변환 가능!
		cout << "addr: " << addr << endl;

		//// int를 주소값(*)으로 변환 가능!
		int* rptr = reinterpret_cast<int*>(addr);
		cout << "value: " << *rptr << endl;

		return 0;
	}
};