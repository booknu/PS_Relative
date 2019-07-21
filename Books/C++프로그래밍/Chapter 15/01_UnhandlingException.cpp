/************
<주소>		: p586
**********
<해결방안>	:

예외처리를 하지 않았을 시

**********
<오답노트>	:

*/

#include <iostream>
using namespace std;

class Main {
public:
	static int main() {
		int n1, n2;
		cout << "두 개의 숫자 입력: ";
		cin >> n1 >> n2;
		
		// n2 = 0일 때 ArithmeticException 발생 (Divided by Zero)
		// 예외처리를 안 하면 프로그램이 영문도 모른채 꺼짐
		cout << "나눗셈의 몫: " << n1 / n2 << endl;
		cout << "나눗셈의 나머지: " << n1 % n2 << endl;
		return 0;
	}
};