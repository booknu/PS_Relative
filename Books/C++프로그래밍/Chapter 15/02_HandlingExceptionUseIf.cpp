/************
<주소>		: p587
**********
<해결방안>	:

예외처리를 if문으로 사용했을 시
예외 발생지역, 발견지역, 처리지역을 한 눈에 보기에 어렵다.

[ 단 점 ]
예외처리를 위한 코드와,
프로그램 흐름을 구성하는 코드를 쉽게 구분하지 못함

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
		// if문을 통해서 예외처리를 한 모습
		if (n2 == 0) {
			cout << "Divided by Zero Exception" << endl;
		} else {
			cout << "나눗셈의 몫: " << n1 / n2 << endl;
			cout << "나눗셈의 나머지: " << n1 % n2 << endl;
		}
		
		return 0;
	}
};